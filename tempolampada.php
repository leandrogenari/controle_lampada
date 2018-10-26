#!/usr/bin/php -q
<?php
require 'phpagi.php';
$port = '/dev/ttyACM0';
$fp = fopen($port, 'w+');
$mensagem = 3;
fwrite($fp, $mensagem);

$mensagem2 = 2400;
fwrite($fp, $mensagem2);


?>
