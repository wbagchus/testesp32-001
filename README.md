# testesp32-001
First Test Repository with VS Code and ESP32-C6 — 4-8-2026

---

## WillemsFirstSketch

**Willem's First Published Sketch** — a demo for the ESP32-C6 with the
1.47″ ST7789 display (Waveshare ESP32-C6-LCD-1.47 or compatible board).

### What it does

| Feature | Detail |
|---------|--------|
| Background | Solid yellow |
| Text | "Willem's First Published Sketch" in black, split across four centred lines |
| Text height | Size-4 font = 32 px ≈ 0.13″ (> 1/8″ at ~247 PPI) |
| Colour square | 32 × 32 px (≈ 1/8″) centred below the text |
| Colour cycle | Cycles through 8 spectrum colours every 500 ms: Red → Orange → Yellow → Green → Cyan → Blue → Indigo → Violet |

### Hardware

- **Board:** ESP32-C6 development board (e.g. Waveshare ESP32-C6-LCD-1.47)
- **Display:** 1.47″ ST7789V2, 172 × 320 px, connected via SPI

Default pin wiring (Waveshare ESP32-C6-LCD-1.47):

| Signal | GPIO |
|--------|------|
| MOSI (DIN) | 6 |
| SCLK | 7 |
| CS | 14 |
| DC | 15 |
| RST | 21 |
| BL (backlight) | 22 |

### Required library

[TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) by Bodmer
- Arduino IDE: install via **Sketch → Include Library → Manage Libraries…**
- PlatformIO: add `Bodmer/TFT_eSPI` to `platformio.ini`

### Setup steps

1. Install the **TFT_eSPI** library.
2. **Copy** `WillemsFirstSketch/User_Setup.h` into the TFT_eSPI library folder,
   replacing the existing `User_Setup.h`:
   - Arduino IDE: `<Documents>/Arduino/libraries/TFT_eSPI/User_Setup.h`
   - PlatformIO: `.pio/libdeps/<env>/TFT_eSPI/User_Setup.h`
3. Open `WillemsFirstSketch/WillemsFirstSketch.ino` in the Arduino IDE
   (or open the project folder in VS Code with PlatformIO).
4. Select board **ESP32C6 Dev Module** and the correct COM port.
5. Upload — the display should light up immediately after flashing.
