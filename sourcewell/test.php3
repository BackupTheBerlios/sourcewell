<?php
/*
 * $Horde: horde/test.php3,v 1.1.2.19 2000/11/06 21:16:32 bjn Exp $
 *
 * Copyright 1999, 2000 Charles J. Hagenbuch <chuck@horde.org>
 *
 * See the enclosed file COPYING for license information (LGPL).  If you
 * did not receive this file, see http://www.fsf.org/copyleft/lgpl.html.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 * This file has been modified by Gregorio Robles <grex@scouts-es.org>
 * to fit it to the SourceWell system
 *
 *                                                  (C) May 2001
 */
	
/* Handle special modes */
if (isset($mode)) {
    switch ($mode) {

    case 'phpinfo':
        phpinfo();
        exit;
        break;

    case 'phplib-sourcewell':
        page_open(array('sess' => 'SourceWell_Session'));

        // s is a per session variable, u is a per user variable.
        if (!isset($s)) {
            $s = 0;
            $sess->register('s');
        }
        ?>
        <html><head>
        <title>SourceAgency: System Capabilities Test - Sessions</title>
        </head>
        <body bgcolor="white" text="black">
        <font face="Helvetica, Arial, sans-serif" size="3">
            <a href="<?php $sess->pself_url()?>">Reload</a> this page to see the counters increment.<br>
            <a href="test.php3">Go back</a> to the test.php3 page.<br>
            <a href="test.php3?mode=phpinfo">View</a> the output of phpinfo().<br>
            <h3>Per Session Data: <?php echo ++$s ?></h3>
            Session ID: <?php echo $sess->id ?>
            <p>If this page works correctly, then you have a correctly configured SourceAgency_Session class. You should be done with PHPLIB setup. Congratulations!
        </body></html>
        <?php
        // Save data back to database.
        page_close();
        break;

    default:
        break;
    }
} else {

// stub to avoid errors
class ImpSession {
}

/* We want to be as verbose as possible here. */
error_reporting(E_ALL);

function status($foo) {
    if ($foo) {
        echo '<font color="green"><b>Yes</b></font>';
    } else {
        echo '<font color="red"><b>No</b></font>';
    }
}

/* PHP Version */
$some_no = 0;
$version = phpversion();
$major = $version[0];
$pl = strstr($version, "pl");
if ($pl) {
    $version = substr_replace($version, '', -strlen($pl));
}
if ($major == 3) {
    $bits = explode('.', $version);
    $minor = $bits[count($bits) - 1];
    $class = 'release';
} else {
    if (strspn($version, '0123456789.') == strlen($version)) {
        $bits = explode('.', $version);
        $minor = $bits[count($bits) - 1];
        $class = 'release';
    } else {
        $tail = substr($version, -4);
        if (($tail == '-dev') || ($tail == '-cvs')) {
            $bits = explode('.', $version);
            $minor = $bits[count($bits) - 1];
            $minor = substr($minor, 0, strlen($minor) - 4);
            $class = substr($tail, 1);
        } else {
            $minor = substr($version, 3);
            $class = 'beta';
        }
    }
}

/* PHP module capabilities */
$mysql = function_exists('mysql_pconnect');
$pgsql = function_exists('pg_pconnect');

/* PHPLIB tests */
$phplib = function_exists('page_open');
$track_vars = isset($HTTP_GET_VARS);

/* PHP Settings */
$magic_quotes_gpc = get_magic_quotes_gpc();
$magic_quotes_runtime = !get_magic_quotes_runtime();

?>

<html>
<head>
<title>SourceWell: System Capabilities Test</title>
</head>

<body bgcolor="white" text="black">
<font face="Helvetica, Arial, sans-serif" size="2">
<a href="test.php3?mode=phpinfo">View phpinfo() screen</a>

<?php
include("include/config.inc");
?>

<h3>SourceWell Version <?php echo $SourceWell_Version ?> System Capabilities Test</h3>

<h3>PHP Version</h3>
<ul>
    <li>PHP Version: <?php echo "$version$pl"; ?></li>
    <li>PHP Major Version: <?php echo $major; ?>, PHP Minor Version: <?php echo "$minor$pl"; ?>, PHP Version Classification: <?php echo $class; ?></li>
    <?php if ($major == 3) {
        if ($minor < 16): ?>
            <li><B><font color="red">Your PHP3 version is older than 3.0.16. You should upgrade to 3.0.16 (or later).</font></B></li>
        <?php else: ?>
            <li><B><font color="green">Your PHP3 version is recent. You should not have any problems with SourceWell modules.</font></B></li>
        <?php endif;
    } elseif ($major == 4) {
        if ($class == 'beta') { $some_no=1; ?>
            <li><B><font color="red">You are running a beta or release candidate of PHP4. You need to upgrade to a release version, at least 4.0.3.</font></B></li>
        <?php } elseif ($minor < 3) { $some_no=1; ?>
            <li><B><font color="red">You are running a version of PHP4 older than 4.0.3. You need to upgrade to at least 4.0.3.</font></B></li>
        <?php } else { ?>
            <li><B><font color="green">You are running a supported release of PHP4. Enjoy the ride!</font></B></li>
        <?php } ?>
    <?php } else { ?>
        <li><font color="orange">Wow, a mystical PHP from the future. Maybe yo've got to look up if a more modern SourceWell version exists!</font></li>
    <?php } ?>
</ul>

<h3>Miscellaneous PHP Settings</h3>
<ul>
    <li>magic_quotes_gpc set to On: <?php echo status($magic_quotes_gpc) ?></li>
    <?php if (!$magic_quotes_gpc) { $some_no=1; ?>
        <li><font color="red">PHPLIB installation instructions (and other useful programs like phpMyAdmin) claim that they want this setting on. Maybe they'll work perfectly well with it off, but lets better have it like they want.</font></li>
    <?php } ?>
    <li>magic_quotes_runtime set to Off: <?php echo status($magic_quotes_runtime) ?></li>
    <?php if (!$magic_quotes_runtime) { $some_no=1; ?>
        <li><font color="red">magic_quotes_runtime may not cause quite as many problems as magic_quotes_gpc, but you still do not need it. Turn it off. If the PHPLIB installation instructions claim that they want this setting on, they lie - PHPLIB versions 7 and later work perfectly well with it off.</font></li>
    <?php } ?>
</ul>


<h3>PHP Module Capabilities</h3>
<ul>
    <li>MySQL Support: <?php status($mysql) ?></li>
    <li>PostgreSQL Support: <?php status($pgsql) ?></li>
</ul>


<h3>SourceWell Database Connection</h3>
<ul>
    <li>I am now going to try to create a DB_SourceWell database connection. If this line is the last thing that you see then you should look at these points and fix them before proceeding:
	<UL>
	<LI>Have you introduced the correct database parameters (<I>Host</I>, <I>Database</I> name, <I>User</I> name and <I>Password</I>) in the include/local.inc file?
        <LI>Have you created the database structures in the database? (you've got them in the <I>sql</I> subdirectory)
        <LI>Is your database running? ;-)
	</UL>
        <?php
        $db = @new DB_SourceWell;
        if ($db->query("SELECT * FROM software")): ?>
            <li><B><font color="green">Created a DB_SourceWell database connection successfully.</font></B></li>
        <?php endif; ?>

</ul>


<h3>PHPLIB Configuration</h3>
<ul>
    <li>track_vars: <?php echo status($track_vars) ?></li>
    <?php if (!$track_vars) { $some_no=1; ?>
        <li><B><font color="red">PHPLIB will not work correctly with track_vars disabled. Enable it in your config file before continuing.</font></B></li>
    <?php } ?> 
    <li>PHPLIB (is page_open() defined): <?php echo status($phplib) ?></li>
    <?php if ($phplib) { ?>
        <li>I am now going to try to create a SourceWell_Session class. If this line is the last thing you see, then you do not have class SourceWell_Session defined in include/local.inc. Fix that before proceeding.</li>
        <?php $sess = @new SourceWell_Session;
        if ($sess): ?>
            <li><B><font color="green">Created a SourceWell_Session instance successfully.</font></B> <a href="test.php3?mode=phplib-sourcewell">Click here to test PHPLIB for SourceWell</a>.</li>
        <?php endif; ?>
    <?php } ?>
</ul>

<?php } 

if ($some_no == 1) {
  echo "<CENTER><TABLE width=75%><TR><TD><B><FONT COLOR=red><CENTER>\n";
  echo "Sorry! You have to fix some things to be able to work with SourceWell.\n";
} else {
  echo "<CENTER><TABLE width=75%><TR><TD><CENTER><B><FONT COLOR=\"green\">\n";
  echo "Congratulations! If you can read this line, then your system is ready for using SourceWell.<BR>\n";
  echo "Follow the link to arrive at the <A HREF=\"index.php3\">index file</A>.</FONT></B></CENTER></TD></TR></TABLE></CENTER>\n";
}

echo "<P align=right><FONT SIZE=2>";
echo "This test page is based on the Horde (<A HREF=\"http://www.horde.org\">http://www.horde.org</A>) test page.<BR>\n";
echo "Copyright 1999, 2000 Charles J. Hagenbuch &lt;<A HREF=\"mailto:chuck@horde.org\">chuck@horde.org</A>&gt released under the GPL<BR>\n";
echo "<BR>It has been modified by Gregorio Robles &lt;<A HREF=\"mailto:grex@scouts-es.org\">grex@scouts-es.org</A>&gt; to fit it to the SourceWell system.</FONT>\n";
?>
</font>
</body>
</html>