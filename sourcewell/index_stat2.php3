<?

page_open(array("sess" => "SourceWell_Session"));

$sess->register("la");

require("config2.inc");
require("lib2.inc");
require("box2.inc");
require("html2.inc");
require("translation.inc");
$t = new translation;
require("lang.inc");


$db = new DB_SourceWell;
$bx = new box("general", "100%");
$bs = new box("general", "100%");
$be = new box("error", "75%");

?>
<!-- content -->
<table BORDER=0 CELLSPACING=10 CELLPADDING=0 WIDTH="100%" >
<tr width=80% valign=top><td>
<?php

if (!isset($by)) $by = "Date";
if (!isset($start)) $start = date("Y-m-d");
if (!isset($days)) $days=1;
if (!isset($cnt)) $cnt = 0;
$prev_cnt = $cnt + $config_show_appsperpage;
if ($cnt >= $config_show_appsperpage) $next_cnt = $cnt - $config_show_appsperpage;
else $next_cnt = 0;

$time = mktime(0,0,0,substr($start,5,2),substr($start,8,2),substr($start,0,4));
$timesav = $time;

$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
$tables = "software,counter,auth_user";

$start = strftime("%Y-%m-%d", $time);

$recent_time = $time;
$time -= 24 * 60 * 60;
$start_day_before = strftime("%Y-%m-%d", $time);

$where = "DATE_FORMAT(software.modification,'%Y-%m-%d')<=\"$start\" AND DATE_FORMAT(software.modification,'%Y-%m-%d')>=\"$start_day_before\" AND software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' GROUP BY software.appid";

switch ($by) {
  case "Importance":
    $order = "sum_cnt DESC";
    break;			
  case "Urgency":
    $order = "software.urgency DESC";
    break;			
  case "Name":
    $order = "software.name ASC";
    break;			
  case "Date":
  default:
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')<=\"$start\" AND software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' GROUP BY software.appid";
    $order = "software.modification DESC";
    break;
}

$limit = $cnt.",".$config_show_appsperpage;

$time = $recent_time;

$timenext = $time + ($days * 24 * 60 * 60);
$timeprev = $time - ($days * 24 * 60 * 60);
$weeknext = $time + (7 * 24 * 60 * 60);
$weekprev = $time - (7 * 24 * 60 * 60);


$sort = $t->translate("sorted by").": "
."<a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $time), "days" => $days, "by" => "Date"))."\">".$t->translate("Date")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $time), "days" => $days, "by" => "Importance"))."\">".$t->translate("Importance")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $time), "days" => $days, "by" => "Urgency"))."\">".$t->translate("Urgency")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $time), "days" => $days, "by" => "Name"))."\">".$t->translate("Name")."</a>\n";

$bs->box_strip($sort);
$nav = "<a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $weekprev), "days" => $days, "by" => $by))."\">&lt;&nbsp;".$t->translate("Week")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $timeprev), "days" => $days, "by" => $by))."\">&lt;&nbsp;".$t->translate("Day")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("start" => strftime("%Y-%m-%d", $time), "days" => $days, "cnt" => $prev_cnt, "by" => $by))."\">&lt;&nbsp;$config_show_appsperpage ".$t->translate("Apps")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("by" => "Date"))."\">".$t->translate("Today")."</a>";

if ($cnt > 0) {
  $nav .= " | <a href=\"".$sess->self_url().$sess->add_query(array("start" =>strftime("%Y-%m-%d", $time), "days" => $days, "cnt" => $next_cnt, "by" => $by))."\">$config_show_appsperpage&nbsp;".$t->translate("Apps")."&nbsp;&gt;</a>";
} else {
  $nav .= " | $config_show_appsperpage&nbsp;".$t->translate("Apps")."&nbsp;&gt;";
}

if ($timenext < time()) {
  $nav .= " | <a href=\"".$sess->self_url().$sess->add_query(array("start" =>strftime("%Y-%m-%d", $timenext), "days" => $days, "by" => $by))."\">".$t->translate("Day")."&nbsp;&gt;</a>";
} else {
  $nav .= " | ".$t->translate("Day")."&nbsp;&gt;";
}

if ($weeknext < time()) {
  $nav .= " | <a href=\"".$sess->self_url().$sess->add_query(array("start" =>strftime("%Y-%m-%d", $weeknext), "days" => $days, "by" => $by))."\">".$t->translate("Week")."&nbsp;&gt;</a></b>";
} else {
  $nav .= " | ".$t->translate("Week")."&nbsp;&gt;";
}

$bs->box_strip($nav);
$query = "SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit";
appdat($query);
$bs->box_strip($nav);
$bs->box_strip($sort);
?>
</td><td width=20%>
<?php

// Apps of last x days with apps at the right column
// x is given by the $config_show_numberofdays

$control=0; // when there are few days inserted.

for ($i=0; $i < $config_show_numberofdays; $i++) {
  if (!appday($start)) {$i -=1; $control++;}
  $time -= 24*60*60;
  $start = strftime("%Y-%m-%d", $time);
  if ($control == 500) $i = $config_show_numberofdays;
}

?>
</td></tr>
</table>
<!-- end content -->
