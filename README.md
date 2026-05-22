# 🎵 ESP8266 Real-Time Lyrics Player

## 🛠️ Cara Pakai
1. Rakit komponen sesuai skema kabel.
2. *Upload* kode via Arduino IDE (Board: NodeMCU 1.0).
3. Putar lagu bersamaan dengan menekan tombol **RST** di NodeMCU.


## 🔌 Skema Kabel

| Pin LCD I2C | Pin NodeMCU |
| :--- | :--- |
| **VCC** | **VIN (5V)** |
| **GND** | **GND** |
| **SDA** | **D2** |
| **SCL** | **D1** |

## 📚 Library yang Dibutuhkan
* **Wire.h** (Bawaan Arduino IDE)
* **LiquidCrystal_I2C** (Bisa dicari via Library Manager)

## 🚀 Fitur Singkat
* **Smart Word-Wrap:** Otomatis memotong kalimat panjang ke baris ke-2 tanpa merusak kata.
* **Blink Indicator:** LED bawaan berkedip 3x saat reset dan berkedip sekali tiap lirik ganti.
* **Auto-Stop:** Layar bersih dan mengunci tampilan akhir setelah lagu selesai.
