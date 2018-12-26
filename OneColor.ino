//ЗАЛИВКА В ОДИН ЦВЕТ; цвет в формате RGB(через запятую), скорость заливки в ms (0 - сразу вся, >1 (положительное число) - заливка от начала, <1 (отрицательное число) - заливка с конца ленты).

// Примеры вызова
OneColor (255,0,255,100);
OneColor (0,255,0,-100);
OneColor (0,100,255,0);



//ЗАЛИВКА В ОДИН ЦВЕТ
  
  void OneColor(int r, int g, int b, int second)
  {
    //int n = 0; 
    //int m = LED_COUNT;
    if (second >= 0)
    {
      for (int i = 0; i < LED_COUNT; i++) 
      {
        strip.setPixelColor(i, strip.Color(r, g, b));
        if (second != 0) 
        {
          strip.show(); // Передаем в ленту.
          delay(second);
        }
      }  
    } 
    if (second < 0)
    {
      for (int i = 0; i < LED_COUNT; i++) 
      {
        strip.setPixelColor((LED_COUNT - i - 1), strip.Color(r, g, b));
          strip.show(); // Передаем в ленту.
          delay(abs(second));
      }  
    } 
    
    if (second == 0)
    {
      strip.show(); // Передаем в ленту.
    }
  }
  //заливка в один цвет, конец
