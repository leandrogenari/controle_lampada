#!/usr/bin/php -q
<?php
require 'phpagi.php';
$agi = new AGI();
// declaracao de variaveis principais
$mensagem = '0'; 
$status;

// Define porta onde arduino está conectado
$port = '/dev/ttyACM0';
 
// Configura velocidade de comunicação com a porta serial(não há necessidade de usar)
//exec("stty -F $port raw speed 9600");
 
// Inicia comunicação serial
$fp = fopen($port, 'w+');

//envia pedido de status da lâmpada
$mensagem = 5;
fwrite($fp, $mensagem);

$status = fread($fp, 1);

//echo $status;

// Executando operação do status;

//if($status == '0' || $status == 'D'){


$agi->set_variable("status", $status);
//agi->exec("Playback","pt_BR/reforgel/lampadaacessa");
//}
// 


// Escreve na porta
//fwrite($fp, $mensagem);
 
// Fecha a comunicação serial
fclose($fp);
?>
