<?php

function cmtform($row) {
    global $PHP_SELF, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Your Comment about")." \"".$row["name"]."\"");
	$bx->box_body_begin();
    echo "<form action=\"cmtins.php3\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Subject")." (128):</td><td><input type=\"TEXT\" name=\"subject\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (*):</td><td><textarea cols=40 rows=7 name=\"text\" wrap=\"virtual\" maxlength=255></textarea></td></tr>\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Send")."\"></td>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function cmtshow($row) {
    global $t, $bx;
	$bx->box_begin();
	$bx->box_title($t->translate("Comment").": ".$row["subject_cmt"]);
	$bx->box_body_begin();
    $timestamp = mktimestamp($row["creation_cmt"]);
    echo "<b><a href=\"mailto:".$row["email_usr"]."\">".$row["user_cmt"]."</a> - ".timestr($timestamp)."</b>\n";
    echo "<p>".$row["text_cmt"]."\n";
	$bx->box_body_end();
	$bx->box_end();
}

function cmtmod($row) {
   global $PHP_SELF, $t, $bx;
	$bx->box_begin();
	$bx->box_title($t->translate("Comment about")." \"".$row["name"]."\"");
	$bx->box_body_begin();
    echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Subject")." (128):</td><td><input type=\"TEXT\" name=\"subject\" size=40 maxlength=128 value=\"".$row["subject_cmt"]."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (*):</td><td>
<textarea cols=40 rows=7 name=\"text\" wrap=\"virtual\" maxlength=255>".$row["text_cmt"]."</textarea></td></tr>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
    echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["creation_cmt"]."\">\n";
    echo "<input type=\"hidden\" name=\"modify\" value=\"2\">\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Modify")."\"></td>\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}

?>