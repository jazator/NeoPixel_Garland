// OneColor(R, G, B, speed)
// Заливка ленты одним цветом.
//
// Параметры:
//   R, G, B — компоненты цвета (0..255).
//   speed  — скорость заливки в миллисекундах на один светодиод:
//            0  — мгновенная заливка всей ленты;
//            >0 — заливка от начала ленты с задержкой speed;
//            <0 — заливка от конца ленты с задержкой abs(speed).

void loop() {
  OneColor(255, 0, 255, 100);
  OneColor(0, 255, 0, -100);
  OneColor(0, 100, 255, 0);
  // Можно продолжать вызывать OneColor с разными параметрами в новых строках.
}

// ФУНКЦИЯ: заливка в один цвет.
void OneColor(int r, int g, int b, int speed) {
  if (speed >= 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(r, g, b));
      if (speed != 0) {
        strip.show(); // Отправляем текущее состояние в ленту.
        delay(speed);
      }
    }
  }

  if (speed < 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(LED_COUNT - i - 1, strip.Color(r, g, b));
      strip.show(); // Отправляем текущее состояние в ленту.
      delay(abs(speed));
    }
  }

  if (speed == 0) {
    strip.show(); // Мгновенно показываем результат без задержек.
  }
}
