# ESP Digital Wristwatch (Jam Tangan Digital ESP)

Proyek Arduino untuk membuat jam tangan digital dengan tampilan **OLED SSD1306 128x64** dan modul **RTC DS1307** untuk mencatat waktu secara real-time. Project ini sempurna untuk diintegrasikan ke dalam jam tangan digital yang stylish dan fungsional.
<img width="960" height="1280" alt="wear img" src="https://github.com/user-attachments/assets/682ba7db-bc96-4138-8296-d637fa8c3e70" />
<img width="960" height="1280" alt="display" src="https://github.com/user-attachments/assets/59def669-8909-4a53-bd48-0f4d03281160" />


## 📋 Deskripsi Project

Project ini menampilkan:
- **Jam**: Menampilkan waktu dalam format `HH:MM:SS` dengan font yang besar dan tebal
- **Hari & Tanggal**: Menampilkan hari (Min, Sen, Sel, Rab, Kam, Jum, Sab) dan tanggal dalam format `DD.MM.YYYY`
- **Interface**: Tampilan clean dan minimalis yang cocok untuk jam tangan
- **Pengaturan Waktu**: Dapat mengatur waktu RTC melalui Serial Monitor dengan mudah

## 🛠️ Hardware yang Digunakan

| Komponen | Keterangan |
|----------|-----------|
| **Mikrokontroller** | NodeMCU ESP8266 / Wemos D1 Mini |
| **OLED Display** | SSD1306 128x64 (I2C) |
| **RTC Module** | DS1307 (I2C) |
| **Kabel** | Untuk koneksi antar komponen |
| **USB Cable** | Micro USB untuk programming |
| **Baterai 3.7** | Baterai lipo kecil untuk power |

## 🔌 Koneksi Pin

### I2C Connection (Untuk OLED dan RTC pada NodeMCU ESP8266)

| Komponen | Pin NodeMCU | GPIO Number |
|----------|-------------|-------------|
| **OLED SDA** | D2 | GPIO4 |
| **OLED SCL** | D1 | GPIO5 |
| **RTC SDA** | D2 | GPIO4 |
| **RTC SCL** | D1 | GPIO5 |
| **GND** | GND | GND (semua komponen) |
| **VCC** | 3V3 atau 5V | 3V3 atau 5V (lihat spesifikasi modul) |

**Catatan Penting**:
- NodeMCU ESP8266 menggunakan pin I2C default: **D1 (GPIO5)** untuk SCL dan **D2 (GPIO4)** untuk SDA
- OLED dan RTC berbagi bus I2C yang sama dengan alamat I2C berbeda (OLED: 0x3C, RTC: 0x68)
- Gunakan **3.3V untuk power** (ESP8266 native), atau gunakan level shifter jika menggunakan 5V
- Tambahkan **resistor pull-up 4.7kΩ** pada pin SDA dan SCL untuk stabilitas I2C

## 📚 Library yang Diperlukan

Install library berikut melalui Arduino IDE (Sketch → Include Library → Manage Libraries):

1. **Adafruit GFX Library** - Library untuk grafis
   - Cari: `Adafruit GFX` by Adafruit
   
2. **Adafruit SSD1306** - Driver untuk OLED SSD1306
   - Cari: `Adafruit SSD1306` by Adafruit
   
3. **RTClib** - Library untuk RTC DS1307
   - Cari: `RTClib` by Adafruit

### Langkah Instalasi Library:
1. Buka Arduino IDE
2. Klik **Sketch** → **Include Library** → **Manage Libraries**
3. Cari nama library di atas
4. Klik **Install**

## 🚀 Cara Menggunakan

### 0. Setup Arduino IDE untuk NodeMCU ESP8266
1. Buka Arduino IDE
2. Klik **File** → **Preferences**
3. Di bagian "Additional Board Manager URLs", tambahkan:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. Klik **OK**
5. Buka **Tools** → **Board** → **Board Manager**
6. Cari "esp8266" dan install "ESP8266 Community" by ESP8266 Community
7. Pilih **Tools** → **Board** → **NodeMCU 1.0 (ESP-12E Module)**
8. Setup **Tools** → **Port** ke port COM yang sesuai

### 1. Upload Kode ke NodeMCU
1. Buka file `projekjam.ino` di Arduino IDE
2. Pastikan board sudah dipilih: **Tools** → **Board** → **NodeMCU 1.0**
3. Pilih port COM yang benar (Tools → Port)
4. Baud rate untuk upload: **115200**
5. Klik **Upload** (tombol panah ke kanan)

### 2. Mengatur Waktu RTC
Setelah upload berhasil, buka **Serial Monitor** (Ctrl + Shift + M) dengan baud rate **115200**:

```
Ketik SET hh mm ss dd MM yyyy untuk set waktu
Contoh: SET 14 30 00 11 08 2025
```

**Contoh pengaturan waktu**:
- Waktu: 14:30:00
- Tanggal: 11 Agustus 2025
- Masukkan: `SET 14 30 00 11 08 2025`

Setelah dienter, Anda akan melihat pesan "Waktu berhasil diatur!"
Display OLED akan menampilkan:
```
     Digital Wristwatch
=====================
     14:30:00
=====================
   Min, 11.08.2025
```

## 📝 Penjelasan Kode

### Setup Function
- Inisialisasi Serial dengan baud rate 115200
- Inisialisasi OLED Display di alamat I2C 0x3C
- Inisialisasi RTC module
- Jika RTC belum berjalan, atur waktu ke waktu kompilasi

### Loop Function
- Membaca perintah dari Serial Monitor
- Jika menerima perintah "SET", parsing parameter waktu dan mengatur RTC
- Membaca waktu saat ini dari RTC
- Menampilkan jam, hari, dan tanggal di OLED

### Custom Array
```cpp
const char* daysOfTheWeek[7] = {
  "Min", "Sen", "Sel", "Rab", "Kam", "Jum", "Sab"
};
```
Array untuk nama hari dalam bahasa Indonesia (singkat)

## 🎯 Spesifikasi Jam Tangan

| Aspek | Detail |
|-------|--------|
| **Mikrokontroller** | NodeMCU ESP8266 (80/160 MHz) |
| **Ukuran Display** | 128x64 pixel (1.3 inch OLED) |
| **Waktu Operasi** | ~7-10 jam dengan baterai 500mAh @ 3.7V |
| **Update Rate** | Real-time (refresh setiap 50-100ms) |
| **Presisi Waktu** | ± 1-2 detik per hari (RTC DS1307) |
| **Daya yang Digunakan** | ~80-120mA (tanpa WiFi), ~160mA (dengan WiFi aktif) |
| **Antar Muka** | Serial Monitor via Micro USB |
| **Bonus** | WiFi-ready untuk sinkronisasi waktu otomatis |

## 🔧 Kemasan untuk Jam Tangan

Untuk mengintegrasikan ke jam tangan fisik:
1. **Casing 3D**: Desain casing yang pas untuk Mikrokontroller dan OLED
2. **Baterai**: Gunakan baterai 3.7V rechargeable
3. **Display Mounting**: Pasang OLED dengan secure sehingga tidak mudah bergeser
4. **Strap**: Gunakan strap kulit atau elastis untuk diikat di pergelangan tangan, bisa juga menggunakan model 3D print

---

## 🐛 Troubleshooting

| Masalah | Solusi |
|---------|--------|
| **OLED tidak menyala** | Periksa koneksi D1 (SCL) & D2 (SDA), pastikan alamat I2C 0x3C benar, cek tegangan 3.3V |
| **RTC tidak terbaca** | Periksa koneksi I2C pada D1/D2, pastikan baterai pada RTC masih baik, gunakan I2C scanner |
| **Serial Monitor blank** | Periksa baud rate harus 115200, NodeMCU mungkin perlu baud 74880 saat boot |
| **Waktu tidak tersimpan** | Baterai RTC mungkin habis, ganti baterai CR2032 |
| **Board tidak terdeteksi** | Install driver CH340 untuk NodeMCU, atau pilih port COM yang benar |
| **Upload error "espcomm error"** | Tekan tombol RESET pada NodeMCU saat proses upload |
| **Display terbalik/garbled** | Ubah alamat I2C atau coba rotate display di kode |
| **Waktu melompat** | Kristal RTC rusak atau koneksi I2C tidak stabil, tambah resistor pull-up |
| **NodeMCU restart sendiri** | Cek power supply (minimal 500mA), mungkin arus I2C kurang stabil |

## 💡 Fitur yang Bisa Dikembangkan

- [ ] Sinkronisasi waktu otomatis via WiFi (NTP)
- [ ] Menambah alarm functionality dengan vibration motor
- [ ] Menambah mode 12-jam/24-jam dengan toggle button
- [ ] Menambah brightness control untuk OLED dengan sensor cahaya
- [ ] Menyimpan multiple alarms di EEPROM
- [ ] Integrasi dengan sensor detak jantung (pulse sensor)
- [ ] Menampilkan suhu dan kelembaban dengan DHT22
- [ ] Mode stopwatch / timer untuk fitness tracking
- [ ] WebUI dashboard untuk konfigurasi via WiFi
- [ ] Battery status indicator dengan ADC
- [ ] Over-The-Air (OTA) firmware update via WiFi
- [ ] Data logging ke cloud (ThingSpeak, Firebase)
- [ ] Custom watch face themes dengan touchscreen
- [ ] Deep sleep mode untuk hemat daya

## 📄 Lisensi

Project ini tersedia untuk penggunaan pribadi, edukatif, dan non-komersial.

## 🔗 References & Resources

### Official Libraries
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
- [RTClib Documentation](https://github.com/adafruit/RTClib)

### ESP8266 Documentation
- [ESP8266 Arduino Core](https://github.com/esp8266/Arduino)
- [NodeMCU Documentation](https://nodemcu.readthedocs.io/)
- [DS1307 RTC Module Guide](https://www.electronicwings.com/sensors-modules/ds1307-real-time-clock)

### Tutorials & Resources
- [ESP8266 Pin Reference](https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h)
- [I2C Communication on ESP8266](https://arduino-esp8266.readthedocs.io/en/latest/i2c.html)
- [Adafruit SSD1306 Setup Guide](https://learn.adafruit.com/monochrome-oled-displays-with-arduino)
- [RTC DS1307 Integration](https://www.electronicwings.com/sensors-modules/ds1307-rtc-interfacing-with-arduino)

---

**ESPCLOCK**
