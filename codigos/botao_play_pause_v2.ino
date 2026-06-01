#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

AnalogAudioStream out;
BluetoothA2DPSink a2dp_sink(out);

// Pino do botão
#define BUTTON_PLAY_PAUSE 25

// Estado anterior do botão
bool lastButtonState = HIGH;

// Estado da música
bool isPlaying = false;

void setup() {

  Serial.begin(115200);

  // Botão com pull-up interno
  pinMode(BUTTON_PLAY_PAUSE, INPUT_PULLUP);

  // Inicia Bluetooth
  a2dp_sink.start("FonoTech");

  Serial.println("Bluetooth iniciado!");
}

void loop() {

  bool buttonState = digitalRead(BUTTON_PLAY_PAUSE);

  // Detecta clique
  if (buttonState == LOW && lastButtonState == HIGH) {

    // Alterna entre play e pause
    if (isPlaying) {

      a2dp_sink.pause();
      Serial.println("Pause");

      isPlaying = false;

    } else {

      a2dp_sink.play();
      Serial.println("Play");

      isPlaying = true;
    }

    // Debounce simples
    delay(200);
  }

  // Atualiza estado anterior
  lastButtonState = buttonState;
}
