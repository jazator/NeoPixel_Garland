// OneColor(R, G, B, second)
// Заливка ленты одним цветом.
//
// Параметры:
//   R, G, B — компоненты цвета (0..255).
//   second — скорость заливки в миллисекундах на один светодиод:
//            0  — мгновенная заливка всей ленты;
//            >0 — заливка от начала ленты с задержкой second;
//            <0 — заливка от конца ленты с задержкой abs(second).
//
// Примеры вызова:
//   OneColor(255, 0, 255, 100);
//   OneColor(0, 255, 0, -100);
//   OneColor(0, 100, 255, 0);

void loop() {
  OneColor(255, 0, 255, 100);
  OneColor(0, 255, 0, -100);
  OneColor(0, 100, 255, 0);
  // Можно продолжать вызывать OneColor с разными параметрами в новых строках.
}

// ФУНКЦИЯ: заливка в один цвет.
void OneColor(int r, int g, int b, int second) {
  if (second >= 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(r, g, b));
      if (second != 0) {
        strip.show(); // Отправляем текущее состояние в ленту.
        delay(second);
      }
    }
  }

  if (second < 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(LED_COUNT - i - 1, strip.Color(r, g, b));
      strip.show(); // Отправляем текущее состояние в ленту.
      delay(abs(second));
    }
  }

  if (second == 0) {
    strip.show(); // Мгновенно показываем результат без задержек.
  }
}
