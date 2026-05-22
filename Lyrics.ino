#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct Lyric {
  unsigned long timestamp;
  String text;
};

Lyric playlist[] = {
  { 0,     "Wake up in the morning" },
  { 1230,  "Everything s alright" },
  { 4060,  "At the end of the story" },
  { 6090,  "You're holding me tight" },
  { 8120,  "I don't need to worry" },
  { 10030, "Am I out of my mind?" },
  { 11240, "Oh it's hard to see you" },
  { 13270, "But I wish you were here" },
  { 15210, "Oh it's hard to leave you" },
  { 17200, "When I get you everywhere" },
  { 19190, "All this time I'm thinking" },
  { 21190, "I'm strong enough\nto sink it" }, 
  { 23180, "I don't need you" },
  { 25150, "but I wiss you come here" }
};

const int totalLyrics = sizeof(playlist) / sizeof(playlist[0]);
unsigned long startTime = 0;
int currentIndex = 0;
bool isPlaying = false;
bool isFinished = false;

void printLeftAligned(String text) {
  lcd.clear();
  
  int newLineIndex = text.indexOf('\n');
  
  if (newLineIndex != -1) {
    String baris1 = text.substring(0, newLineIndex);
    String baris2 = text.substring(newLineIndex + 1);
    
    lcd.setCursor(0, 0);
    lcd.print(baris1);
    lcd.setCursor(0, 1);
    lcd.print(baris2);
  } 
  else if (text.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(text);
  } 
  else {
    int cutIndex = 16;
    for (int i = 16; i > 0; i--) {
      if (text.charAt(i) == ' ') {
        cutIndex = i;
        break;
      }
    }
    
    String baris1 = text.substring(0, cutIndex);
    String baris2 = text.substring(cutIndex);
    baris2.trim(); 
    
    lcd.setCursor(0, 0);
    lcd.print(baris1);
    lcd.setCursor(0, 1);
    lcd.print(baris2);
  }
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, LOW);  
  delay(50);                       
  digitalWrite(LED_BUILTIN, HIGH); 
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, LOW);  
    delay(80);
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(80);
  }

  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  startTime = millis();
  isPlaying = true;
}

void loop() {
  if (isPlaying && currentIndex < totalLyrics) {
    unsigned long elapsedTime = millis() - startTime;

    if (elapsedTime >= playlist[currentIndex].timestamp) {
      printLeftAligned(playlist[currentIndex].text);
      
      blinkLED();
      
      currentIndex++; 
    }
  } 
  else if (currentIndex >= totalLyrics && !isFinished) {
    delay(3500); 
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("@zxy:numpang WM");
    
    isFinished = true; 
    isPlaying = false;
  }
}
