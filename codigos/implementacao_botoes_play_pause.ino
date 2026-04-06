/**************************************************
 * PROJETO : Dispositivo eletrônico portátil para estímulo à comunicação oral 
 * AUTOR   : Paulo Sérgio Santos de Oliveira
 * DATA DA ÚLTIMA MODIFICAÇÃO : 18/12/2025
 * VERSÃO  : 1.0
 **************************************************
 * DESCRIÇÃO:
 
 * Este projeto trata-se do desenvolvimento de um dispositivo portátil usando o microcontrolador ESP32 assim como o protocolo de comunicação Bluetooth para auxiliar na reabilitação e estímulo de pessoas com limitações na fala. 
 *
 * BASEADO EM:
 
 * Este código utiliza funções da biblioteca ESP32-A2DP
 * desenvolvida por Phil Schatzmann.
 * Este código utiliza a biblioteca Arduino Audio Tools
 * desenvolvida por Phil Schatzmann para manipulação e reprodução de áudio no ESP32.
 *
 *
 * Modificações realizadas:
 
 * Implementação de leitura de botões de play e pause 
 *
 * REPOSITÓRIOS ORIGINAAIS:
 
 * https://github.com/pschatzmann/ESP32-A2DP
 * https://github.com/pschatzmann/arduino-audio-tools
 
 * OBSERVAÇÃO:
 
 * Este projeto utiliza funcionalidades das bibliotecas
 * originais sem modificações significativas.

 
 **************************************************/
 
#include "AudioTools.h" //--- Biblioteca para trabalhar com áudio ---//
#include "BluetoothA2DPSink.h" //--- Biblioteca que transforma o ESP32 em um receptor Bluetooth  ---//

AnalogAudioStream out; //--- Esta função cria um fluxo de áudio analógico que vai sair som pelos pinos do DAC interno do ESP32  ---//
BluetoothA2DPSink a2dp_sink(out); //--- Esta função cria o receptor Bluetooth usando o fluxo de áudio, ou seja, qualquer musica que chegar no bleutooth vai ser transmitido pelo out  ---//

//--- Definição dos pinos dos botões ---//
#define BUTTON_PLAY   12; //--- GPIO12 do ESP32 ---//
#define BUTTON_PAUSE  14; //--- GPIO14 do ESP32 ---//

//--- Variáveis de controle de debounce ---//
//--- Guarda o estado anterior dos botões de play e pause respectivamente ---//
bool lastPlayState = false;
bool lastPauseState = false;

void setup() {

   Serial.begin(115200); // Inicialização a comunicação serial 

  // Configura os botões como entrada com resistor de pull-up interno
  pinMode(BUTTON_PLAY, INPUT_PULLUP);
  pinMode(BUTTON_PAUSE, INPUT_PULLUP);

  // Inicia a comunicação Bluetooth A2DP como o dispositivo nomeado de FonoTech
  a2dp_sink.start("FonoTech");
  
}

void loop() {
  // As funções a seguir foram criadas para obter a leitura dos estados dos botões 
  bool playState = digitalRead(BUTTON_PLAY); 
  bool pauseState = digitalRead(BUTTON_PAUSE);

  //--- Esta estrutura condicional detecta quando o estado do botão muda de true para falso ---//
  if (playState == true && lastPlayState == false) {
     a2dp_sink.play(); //--- Esta função envia o comando de play via Bluetooth ---//
     Serial.println("Play acionado!"); // Verificação no monitor serial se os botões físicos estão funcionando corretamente 
   }

  //--- Esta estrutura condicional também detecta quando o estado do botão de pause muda de verdadeiro para falso ---//
  if (pauseState == true && lastPauseState == false) {
    a2dp_sink.pause(); //--- Esta estrutura envia o comando de pause via Bluetooth ---//
    Serial.println("Pause acionado!");
  }
 //--- Estas estruturas criadas guardam os Estados dos botões para realizarem comparações no próximo loop  ---//
lastPlayState = playState;
lastPauseState = pauseState;
}

