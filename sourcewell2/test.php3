<?php

page_open(array('sess' => 'SourceAgency_Session'));
if (isset($auth) && !empty($auth->auth['perm'])) {
  page_close();
  page_open(array('sess' => 'SourceAgency_Session',
                  'auth' => 'SourceAgency_Auth',
                  'perm' => 'SourceAgency_Perm'));
}

include('start.inc');
include('Field.inc');
include('TextField.inc');
include('TextAreaField.inc');
include('SelectField.inc');
include('Form.inc');
include('Preview.inc');
include('Table.inc');
include('Insertion.inc');

$table = new Table();

$name = new TextField('Name', 'name','',1);
$name->setIsTitle();
$fields[] = $name;
$description = new TextAreaField('Description', 'description','',1);
$description->setShowType('B');
$fields[] = $description;
$fields[] = new SelectField('Type', 'type', '', array('1', '2', '3', '4'));

$form = new Form('Testing classes');


if ($HTTP_POST_VARS['Insert']) {

    $insertion = new Insertion('table');
    $id = $insertion->generateQuery(&$fields);

    /*  
    $show = new FormShow('table');
    $show->addCondition('id',$id);
    $show->printShow(&$fields);
    */

} else {
    if ($HTTP_POST_VARS[$form->getPreviewButton()]) {
        $preview = new Preview();
        $preview->ShowFields(&$fields);
    }
    $form->FormFields(&$fields);
}

@page_close();
?>
