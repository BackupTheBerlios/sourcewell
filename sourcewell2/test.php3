<?php
include('start.inc');
lib_include('Field');
include('TextField');
include('Table.inc');

//$table = new Table();

$name = new TextField('Name', 'name','',1);
$nombre->setIsTitle();
$fields[] = $name;
$description = new TextAreaField('Description', 'description','',1);
$resumen->setShowType('B');
$fields[] = $description;
$fields[] = new SelectField('Type', 'type', '', array(1, 2, 3, 4));

$form = new Form('Testing classes');

if ($HTTP_POST_VARS[$form->getPreviewButton()]) {
    $preview = new Preview();
    $preview->ShowFields(&$fields);
}
$form->FormFields(&$fields);

?>
