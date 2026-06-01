/****************************************************************************
* PROJETOFONO : Feedback Multimodal
* AUTOR : Paulo Sérgio Santos de Oliveira
* DATA : 09/04/2026
* VERSÃO : 2.0
****************************************************************************/

// ---------------- PINOS DOS BOTÕES ---------------- //
const int BOTAO_01 = 13;
const int BOTAO_02 = 12;
const int BOTAO_03 = 14;
const int BOTAO_MOTOR = 27;

// ---------------- PINOS DOS LEDS ---------------- //
const int LED_VERDE = 4;
const int LED_VERMELHO = 5;
const int LED_AMARELO = 19;

// ---------------- PINO DO MOTOR ---------------- //
const int MOTOR_DC = 25;


// ---------------- VARIÁVEIS DE ESTADO ---------------- //

// Estado atual dos LEDs
bool estadoLedVerde = false;
bool estadoLedVermelho = false;
bool estadoLedAmarelo = false;
bool estadoMotor = false;

// Guarda estado anterior dos botões
bool ultimoEstadoBotao1 = HIGH;
bool ultimoEstadoBotao2 = HIGH;
bool ultimoEstadoBotao3 = HIGH;
bool ultimoEstadoBotaoMotor = HIGH;

void setup() {

  // Botões
  pinMode(BOTAO_01, INPUT_PULLUP);
  pinMode(BOTAO_02, INPUT_PULLUP);
  pinMode(BOTAO_03, INPUT_PULLUP);
  pinMode(BOTAO_MOTOR, INPUT_PULLUP);

  // LEDs
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);

  // Motor
  pinMode(MOTOR_DC, OUTPUT);

  // Inicializa desligado
  digitalWrite(MOTOR_DC, LOW);
}

void loop() {

  // -------- LEITURA DOS BOTÕES -------- //
  bool leituraBotao1 = digitalRead(BOTAO_01);
  bool leituraBotao2 = digitalRead(BOTAO_02);
  bool leituraBotao3 = digitalRead(BOTAO_03);
  bool leituraBotaoMotor = digitalRead(BOTAO_MOTOR);

  // =====================================================
  // BOTÃO 1 -> LED VERDE
  // =====================================================
  if (leituraBotao1 == LOW && ultimoEstadoBotao1 == HIGH) {

    estadoLedVerde = !estadoLedVerde;

    digitalWrite(LED_VERDE, estadoLedVerde);

    delay(200);
  }

  // =====================================================
  // BOTÃO 2 -> LED VERMELHO
  // =====================================================
  if (leituraBotao2 == LOW && ultimoEstadoBotao2 == HIGH) {

    estadoLedVermelho = !estadoLedVermelho;

    digitalWrite(LED_VERMELHO, estadoLedVermelho);

    delay(200);
  }

  // =====================================================
  // BOTÃO 3 -> LED AMARELO
  // =====================================================
  if (leituraBotao3 == LOW && ultimoEstadoBotao3 == HIGH) {

    estadoLedAmarelo = !estadoLedAmarelo;

    digitalWrite(LED_AMARELO, estadoLedAmarelo);

    delay(200);
  }

  // =====================================================
  // BOTÃO MOTOR
  // =====================================================
  if (leituraBotaoMotor == LOW && ultimoEstadoBotaoMotor == HIGH) {

    estadoMotor = !estadoMotor;

    digitalWrite(MOTOR_DC, estadoMotor);

    delay(200);
  }

  // Atualiza estados anteriores
  ultimoEstadoBotao1 = leituraBotao1;
  ultimoEstadoBotao2 = leituraBotao2;
  ultimoEstadoBotao3 = leituraBotao3;
  ultimoEstadoBotaoMotor = leituraBotaoMotor;
}
