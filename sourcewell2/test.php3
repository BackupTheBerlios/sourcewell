<?php

include('start.inc');
config_inc('TextField');
config_inc('TextAreaField');
config_inc('SelectField');
config_inc('Form');
config_inc('Preview');
config_inc('Insertion');

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

config_inc('end');
?>
