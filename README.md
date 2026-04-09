# Digital Clock (Jam Digital Arduino)

Proyek Arduino untuk membuat jam digital dengan tampilan **OLED SSD1306 128x64** dan modul **RTC DS1307** untuk mencatat waktu secara real-time.

## 📋 Deskripsi Project

Project ini menampilkan:
- **Jam**: Menampilkan waktu dalam format `HH:MM:SS` dengan font yang besar dan tebal
- **Hari & Tanggal**: Menampilkan hari (Min, Sen, Sel, Rab, Kam, Jum, Sab) dan tanggal dalam format `DD.MM.YYYY`
- **Header**: Menampilkan "Agna's Clock" sebagai judul
- **Pengaturan Waktu**: Dapat mengatur waktu RTC melalui Serial Monitor

## 🛠️ Hardware yang Digunakan

| Komponen | Keterangan |
|----------|-----------|
| **Arduino** | Arduino Uno / Nano / Mega |
| **OLED Display** | SSD1306 128x64 (I2C) |
| **RTC Module** | DS1307 (I2C) |
| **Kabel Jumper** | Untuk koneksi antar komponen |

## 🔌 Koneksi Pin

### I2C Connection (Untuk OLED dan RTC)

| Komponen | Pin Arduino |
|----------|-------------|
| **OLED SDA** | A4 (SDA) |
| **OLED SCL** | A5 (SCL) |
| **RTC SDA** | A4 (SDA) |
| **RTC SCL** | A5 (SCL) |
| **GND** | GND (semua komponen) |
| **VCC** | 5V (semua komponen) |

**Catatan**: OLED dan RTC berbagi bus I2C yang sama dengan alamat I2C berbeda (OLED: 0x3C, RTC: 0x68)

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

### 1. Upload Kode ke Arduino
1. Buka file `projekjam.ino` di Arduino IDE
2. Pilih board yang sesuai (Tools → Board)
3. Pilih port COM yang benar (Tools → Port)
4. Klik **Upload** (tombol panah ke kanan)

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

### 3. Lihat Hasil
Display OLED akan menampilkan:
```
   your's Clock
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

## 🐛 Troubleshooting

| Masalah | Solusi |
|---------|--------|
| **OLED tidak menyala** | Periksa koneksi SDA/SCL, pastikan alamat I2C 0x3C |
| **RTC tidak terbaca** | Periksa koneksi I2C, pastikan baterai pada RTC masih baik |
| **Serial Monitor blank** | Periksa baud rate harus 115200 |
| **Waktu tidak tersimpan** | Baterai RTC mungkin habis atau kontak jelek |

## 💡 Fitur yang Bisa Dikembangkan

- [ ] Menambah alarm functionality
- [ ] Menambah mode 12-jam/24-jam
- [ ] Menambah brightness control untuk OLED
- [ ] Menyimpan multiple alarms
- [ ] Menampilkan suhu dengan sensor DHT22
- [ ] Integrasi dengan WiFi untuk auto time sync

## 📄 Lisensi

Project ini tersedia untuk penggunaan pribadi dan edukatif.

## 👤 Author

**Agna**

---

**Dibuat dengan ❤️ menggunakan Arduino**
