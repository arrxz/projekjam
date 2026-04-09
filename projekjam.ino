#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

// Font tambahan
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

RTC_DS1307 rtc;

// Nama hari
const char* daysOfTheWeek[7] = {
  "Min", "Sen", "Sel", "Rab", "Kam", "Jum", "Sab"
};

void setup() {
  Serial.begin(115200);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED gagal"));
    while (true);
  }
  display.clearDisplay();

  // RTC
  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan!");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC tidak berjalan, atur ke waktu kompilasi");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  Serial.println("Ketik SET hh mm ss dd MM yyyy untuk set waktu");
  Serial.println("Contoh: SET 14 30 00 11 08 2025");
}

void loop() {
  // Cek apakah ada perintah set waktu dari Serial
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.startsWith("SET")) {
      int hh, mm, ss, d, m, y;
      if (sscanf(cmd.c_str(), "SET %d %d %d %d %d %d", &hh, &mm, &ss, &d, &m, &y) == 6) {
        rtc.adjust(DateTime(y, m, d, hh, mm, ss));
        Serial.println("Waktu berhasil diatur!");
      } else {
        Serial.println("Format salah! Gunakan: SET hh mm ss dd MM yyyy");
      }
    }
  }

  DateTime now = rtc.now();

  display.clearDisplay();

  // === HEADER ===
  display.setFont();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30, 0);
  display.print("Agna's Clock");
  // === JAM ===
  display.setFont(&FreeSansBold12pt7b);
  char timeStr[9];
  sprintf(timeStr, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  display.setCursor(17, 36);
  display.print(timeStr);
  display.setFont();
  display.setTextSize(1);
  display.setCursor(0, 8);
  display.print("=====================");
  display.setCursor(0, 44);
  display.print("=====================");
  // === HARI & TANGGAL ===
  display.setFont();  
  display.setTextSize(1); // ukuran teks 1 (default)
  display.setCursor(20, 56);
  display.printf("%s, %02d.%02d.%04d",
               daysOfTheWeek[now.dayOfTheWeek()],
               now.day(), now.month(), now.year());


  display.display();
}
