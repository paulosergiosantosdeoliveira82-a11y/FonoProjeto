/**************************************************
 * PROJETO : Dispositivo Portátil para Estímulo à Comunicação Oral (Feedback multimodal/Acionamento do motor via ESP32 e botão)***
 * AUTOR   : Paulo Sérgio Santos de Oliveira
 * DATA    : 09/04/2026
 * VERSÃO  : 1.0
 **************************************************
 * DESCRIÇÃO:
 * Acionamento de  um motor vibratório usando um botão com
 * INPUT_PULLUP. O Acionamento do motor é controlado via transistor.
 *
 * HARDWARE:
 * - ESP32DEVKITV1
 * - Motor DC
 * - Transistor 2N2222
 * - Resistor 1kΩ
 * - Botão
 **************************************************/
 
 // Definição dos pinos
const int botao = 27;   // GPIO27 pino onde o botão está conectado
const int motor = 25;   // GPIO25 pino que controla a base do transistor

void setup() {
  // Configura o pino do motor como saída
  pinMode(motor, OUTPUT);
  
  // Configura o pino do botão como entrada com resistor de pull-up interno
  // Isso mantém o pino em HIGH até que o botão seja pressionado (GND)
  pinMode(botao, INPUT_PULLUP);
  
  // Garante que o motor comece desligado
  digitalWrite(motor, LOW);
}

void loop() {
  // Lê o estado do botão
  int estado_Botao = digitalRead(botao);

  // Se o botão for pressionado (nível lógico LOW)
  if (estado_Botao == LOW) {
    digitalWrite(motor, HIGH); // Liga o motor
  } else {
    digitalWrite(motor, LOW);  // Desliga o motor
  }
}
    
