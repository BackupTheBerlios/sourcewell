<?php
/****************************************************************************
 ** PROGRAM    : phpLinkValidator v1.2                                     **
 ** AUTHOR     : (C) 2001 by Marek Podmaka <marki@yours.com>               **
 ** USAGE      : See file USAGE                                            **
 ** HISTORY    : See file ChangeLog                                        **
 ** BUGS/LIMITS: See file BUGS                                             **
 ** EXAMPLES   : See file EXAMPLES                                         **
 ** LICENSE    : GPL - for details see file LICENSE                        **
 ** DESCRIPTION: Main intention was to write simple but powerful HTML link **
 **              validator. It searches the specified file (local or http) **
 **              for all links and it runs itself recursively with all     **
 **              linked files.                                             **
 ****************************************************************************/

/***** DEFAULT PARAMETERS set here ******************************************/
// debug level (for info, see above)
$LV_debug=1;

// set time limit for execution in seconds (will stop after it)
// 0 = disable
$LV_timelimit=0;

// whether to check only local links - remote links will be ignored
// (remote links begin with http:// or ftp://)
$LV_local_only=1;

// these followed by "=", quotes, some text and quotes
// will threat as link, the text between is filename (e.g. src='image.jpg')
// will be compared case insensitive
$LV_links="href|src|background";

// do not read files with these extensions (don't search for links there)
// of course will try to open them to ensure they exist
// this mainly for speed - it would be useless to search in these files
// will be compared case insensitive

// only constants
$LV_no_images="jpeg|jpg|gif|png|bmp";                   // images
$LV_no_audiov="rm|ra|mp3|mid|midi|wav|asf|mpg|mp2|avi"; // audio/video
$LV_no_packed="zip|rar|tar|tgz|tbz|gz|bz2|deb|rpm";     // compressed
$LV_no_binary="bin|exe|com|dll";                        // other binary

// this is really used
$LV_no_read=$LV_no_images."|".
            $LV_no_audiov."|".
	    $LV_no_packed."|".
	    $LV_no_binary;

// this array is used for remembering which files have been checked
// already (to prevent from looping).
// index is filename with path, must be set to !=0
// (e.g. $LV_done["/my_web/gallery/pictures/myself/2.jpg"]="OK")
unset($LV_done);
$LV_done[]="";

// only for debugging
$LV_rec=0;       // current recursion level
$LV_rec_max=0;   // max. recursion level
$LV_num_links=0; // total no. of links checked

// some constants
$LV_prog_name="phpLinkValidator";
$LV_prog_ver="v1.2";
$LV_prog_copy="(C) 2001, Marek Podmaka <marki@yours.com>";

/***** DEFINITIONS OF FUNCTIONS *********************************************/

// just reset all parameters to their default value
function LV_Reset() {
  global $LV_done;
  unset($LV_done);
  $LV_done[]="";
}

// main function called by user
// $filename  ... name (and) path of file to check
// $recursive ... optional; if set to 0, will check links only in $filename
function ValidateFile($filename,$recursive=1) {
  global $LV_timelimit;
  global $LV_prog_name,$LV_prog_ver,$LV_prog_copy;
  global $LV_rec,$LV_rec_max,$LV_num_links;
  $LV_rec=0;       // current recursion level
  $LV_rec_max=0;   // max. recursion level
  $LV_num_links=0; // total no. of links checked

  set_time_limit($LV_timelimit);
  $old_error_rep=error_reporting(); // save current error reporting level
  error_reporting(21);              // don't print warnings
  $beg=time();
  printDebug("<b>INFO</b>: $LV_prog_name $LV_prog_ver, $LV_prog_copy");
  printDebug("<b>START</b>: Check began at ".date("d.m.Y H:i:s",$beg).".");
  if (!_ValidateFile($filename,!$recursive))
     printDebug("<b>FATAL ERROR:</b> Main file cannot be opened!");
  $end=time();
  $elapsed=date("i:s",$end-$beg);
  printDebug("<b>FINISHED</b>: Check finished at ".date("d.m.Y H:i:s",$end).". It took $elapsed. Total no. of different links checked: $LV_num_links. Max. recursion level achieved: $LV_rec_max.");
  error_reporting($old_error_rep);  // restore old error reporting level
}

// main recursive function
// $file     ... filename (with path) to check
// $onlythis ... if 1, will reset $LV_no_read (to skip all further files)
// returns false if file doesn't exist
function _ValidateFile($file,$onlythis=0) {
 global $LV_done,$LV_links,$LV_no_read,$LV_local_only;
 global $LV_rec,$LV_rec_max,$LV_num_links;

 $LV_done[$file]="OK"; // save we checked this file already
 $LV_num_links++;      // increase total no. of checked links
 printDebug("BEGIN: $file (".($LV_rec+1).")",2);
 if (!$f=fopen($file,"r")) return false; // if the file doesn't exist

 $LV_rec++; // increase recursion level
 if ($LV_rec>$LV_rec_max) $LV_rec_max=$LV_rec;
 ereg('^(.*)/([^/]*)$',$file,$out); $dir=$out[1]; // get path from filename
 printDebug("CHECKING: $file ($LV_rec)",1);
 
 // test if we want to search in this file
 if (eregi('\.('.$LV_no_read.')$',$file)) { fclose($f); $LV_rec--; return true; }
 // if $onlythis --> reset $LV_no_read to skip all files
 if ($onlythis) {
    $old_no_read=$LV_no_read;
    $LV_no_read=".*";
 }
 $link='('.$LV_links.')=(\'|")([^\'"]*)(\'|")';
 while (!feof($f)) {                           // for each line in file
   $line=fgets($f,65000);                      // get first 6500 bytes of line
   while (eregi($link,$line,$out)){            // for each link on that line
     $new_file=eregi_replace('#.*',"",$out[3]);// filename from the link (w/o anchor)
     if (eregi('^mailto:',$new_file)) $new_file=""; // if it is mailto: URL
     if (($LV_local_only)&&(eregi('^(http|ftp)://',$new_file)))
        $new_file="";                          // don't check remote links
     if ($new_file) {                          // if valid link to check
       $new=ParseParent($dir,$new_file);       // filename with parsed path
       if (!$LV_done[$new])                    // if it was not checked already
          if (!_ValidateFile($new))            // if the file was not found
             printDebug("<b>ERROR</b>: Not found: '$new_file' in '$file'!");
     }
     // remove that link from line
     $line=eregi_replace(AddSlashes($out[0]),"",$line);
   }      // end of line
 }        // end of file
 flush(); // try to flush all data to web-server
 fclose($f);
 if ($onlythis) $LV_no_read=$old_no_read; // restore normal
 printDebug("END: $file",2);
 $LV_rec--;
 return true;
}

// will output $message if $LV_debug permits
// $level ... in which debug-level the message should be printed
function printDebug($message,$level=0) {
  global $LV_debug;
  if ((!$level)||($LV_debug==$level)) // if ==0, or the levels equal
     echo "\n<br>$message";
}

// Used for parsing relative paths (e.g. "../../../another/imgs")
// For every "../" in $file remove last directory from $dir
// return new filename with path
// $dir is directory without trailing "/" (e.g. "/my_html/imgs")
// $file is just filename with relative path (e.g. "../New/pict1.jpg")
// e.g. ParseParent("/my_html/gallery/new/imgs","../../old/color/me.jpg")
// will return "/my_html/gallery/old/color/me.jpg"
// if $file has absolute path, return it without any modifications
function ParseParent($dir,$file){
  if ($file[0]=="/") return $file; // absolute path
  while (eregi('\.\./',$file,$out)) { // for every "../" in $file
    $dir=eregi_replace('^(.*)/([^/]*)$',"\\1",$dir); // remove last subdir from $dir
    $file=eregi_replace('^\.\./(.*)$',"\\1",$file);  // remove this "../" from $file
  }
  return $dir."/".$file; // return new filename with path
}

/***** INIT (called when this file is require()'d ***************************/
LV_Reset();

/***** END of file **********************************************************/
?>