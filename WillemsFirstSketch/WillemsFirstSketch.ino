/*
 * Willem's First Published Sketch
 * --------------------------------
 * Hardware : ESP32-C6 + 1.47" ST7789 display (172x320 px, ~247 PPI)
 * Library  : TFT_eSPI  (install via Arduino Library Manager or PlatformIO)
 *
 * What it does:
 *   1. Fills the screen with a yellow background and draws
 *      "Willem's First Published Sketch" in black text.
 *      Text size 4 = 32 px tall ≈ 0.13" (> 1/8") at 247 PPI.
 *
 *   2. Shows a 32×32 px square (~1/8") centred below the text.
 *      Every 500 ms it cycles through 8 spectrum colours:
 *      Red → Orange → Yellow → Green → Cyan → Blue → Indigo → Violet
 *
 * Setup:
 *   Copy the included User_Setup.h into your TFT_eSPI library folder
 *   (overwriting the existing User_Setup.h) before compiling.
 *   See README.md for full instructions.
 */

#include <TFT_eSPI.h>
#include <SPI.h>

// --------------------------------------------------------------------------
// Display constants
// Landscape rotation (rotation 1): physical 320 px wide × 172 px tall
// --------------------------------------------------------------------------
#define SCREEN_W  320
#define SCREEN_H  172

// 32 px ≈ 0.130" at ~247 PPI — satisfies the ≥ 1/8" requirement
#define SQUARE_SIZE  32
#define SQUARE_X     ((SCREEN_W - SQUARE_SIZE) / 2)   // horizontally centred
#define SQUARE_Y     136                               // below the four text lines

// --------------------------------------------------------------------------
// 8 spectrum colours, red → violet  (RGB-565 format)
// --------------------------------------------------------------------------
static const uint16_t SPECTRUM[8] = {
  0xF800,  // Red
  0xFD20,  // Orange
  0xFFE0,  // Yellow
  0x07E0,  // Green
  0x07FF,  // Cyan
  0x001F,  // Blue
  0x4810,  // Indigo
  0x901A   // Violet / Purple
};

// --------------------------------------------------------------------------
// Globals
// --------------------------------------------------------------------------
TFT_eSPI tft = TFT_eSPI();
int colorIdx = 0;

// --------------------------------------------------------------------------
// setup()
// --------------------------------------------------------------------------
void setup() {
  // Initialise backlight pin (active HIGH on Waveshare ESP32-C6-LCD-1.47)
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);

  tft.init();
  tft.setRotation(1);            // Landscape: 320 px wide, 172 px tall
  tft.fillScreen(TFT_YELLOW);

  // ---- Draw title text ----
  // Text size 4 → each character is 24 px wide × 32 px tall.
  // Lines are placed so all four fit above the colour square.
  //   y =   0  "Willem's"
  //   y =  34  "First"
  //   y =  68  "Published"
  //   y = 102  "Sketch"
  //   (each line 32 px tall + 2 px gap = 34 px step)
  tft.setTextColor(TFT_BLACK, TFT_YELLOW);  // black text, yellow background
  tft.setTextSize(4);
  tft.setTextDatum(TC_DATUM);               // top-centre alignment

  int cx = SCREEN_W / 2;                   // horizontal centre = 160

  tft.drawString("Willem's",   cx,   0);
  tft.drawString("First",      cx,  34);
  tft.drawString("Published",  cx,  68);
  tft.drawString("Sketch",     cx, 102);

  // ---- Draw initial spectrum square ----
  tft.fillRect(SQUARE_X, SQUARE_Y, SQUARE_SIZE, SQUARE_SIZE, SPECTRUM[colorIdx]);
}

// --------------------------------------------------------------------------
// loop() — advance the square colour every 500 ms
// --------------------------------------------------------------------------
void loop() {
  delay(500);
  colorIdx = (colorIdx + 1) % 8;
  tft.fillRect(SQUARE_X, SQUARE_Y, SQUARE_SIZE, SQUARE_SIZE, SPECTRUM[colorIdx]);
}
