<?php

    $lastModified = '1016292668';
    $now = time();
    $maxCache = $now - 10800; // Max. time before refreshing
    $headers = getallheaders();
    $refresh= TRUE; // refresh, as default

    if(isset($headers["If-Modified-Since"])) {
        // NetCrap sends ";lenght = xxx" after the date
        $arraySince = explode(";", $headers["If-Modified-Since"]);
        $since = strtotime($arraySince[0]);
        if($since >= $lastModified) {
            $refresh=FALSE;
        }
    }

    if($logged == TRUE) {
        $tag="\"AUT".$lastModified."\"";  // A private page
    } else {
        $tag="\"PUB".$lastModified."\"";  // and public one
    }

    if(isset($headers["If-None-Match"])) { // check ETag
        if(strcmp($headers["If-None-Match"], $tag) == 0 ) {
            $refresh=FALSE;
        } else {
            $refresh=TRUE;
        }
    }

    if(!$refresh) {
        header("HTTP/1.1 304 Not changed");
        // The first header must be this
        // otherwise Netcrap gives "No Data" error
        $strLastModified = gmdate("r", $lastModified);
        $string = 'hola';
    } else {
        $strLastModified = gmdate("r", $now);
        $string = 'adios';
    }

    header("ETag: $tag");  // The new TAG
    header("Last-Modified: $strLastModified");
    header("Expires: " . gmdate("r", time()+3));
    header("Cache-Control: max-age=3, must-revalidate"); // HTTP/1.1

    // Netscape doesn't handle very well the header("Pragma: no-cache");

    if(!$refresh) {
  //        ob_end_clean(); // Just in case..
        die; // Don't do anything more
    }

print $string;
print '<br>'.$lastModified;
print '<br>'.$arraySince[0];
$headers = getallheaders();
while (list ($header, $value) = each ($headers)) {
    echo "$header: $value<br />\n";
}
?>
