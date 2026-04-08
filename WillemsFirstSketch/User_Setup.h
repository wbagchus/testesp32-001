// =============================================================================
// TFT_eSPI User_Setup.h
// =============================================================================
// Board   : Waveshare ESP32-C6-LCD-1.47  (or compatible ESP32-C6 board with
//           a 1.47" ST7789 display wired to these pins)
// Display : ST7789V2  172×320 pixels
//
// HOW TO USE:
//   Copy this file into the TFT_eSPI library folder, replacing the existing
//   User_Setup.h, then recompile the sketch.
//
//   Arduino IDE   : <Documents>/Arduino/libraries/TFT_eSPI/User_Setup.h
//   PlatformIO    : <project>/.pio/libdeps/<env>/TFT_eSPI/User_Setup.h
//                   (or add to lib/TFT_eSPI/ if you vendor the library)
// =============================================================================

// ---- Display driver --------------------------------------------------------
#define ST7789_DRIVER

// ---- Display resolution ----------------------------------------------------
#define TFT_WIDTH   172
#define TFT_HEIGHT  320

// ---- SPI pins (Waveshare ESP32-C6-LCD-1.47) --------------------------------
#define TFT_MOSI  6    // SPI data
#define TFT_SCLK  7    // SPI clock
#define TFT_CS    14   // Chip select
#define TFT_DC    15   // Data / Command
#define TFT_RST   21   // Reset
// Backlight is driven from pin 22 in the sketch (digitalWrite HIGH = on)

// ---- Colour order ----------------------------------------------------------
// ST7789 typically uses BGR.  If colours appear wrong (e.g. red shows as blue),
// change TFT_BGR to TFT_RGB below.
#define TFT_RGB_ORDER TFT_BGR

// ---- SPI speed -------------------------------------------------------------
#define SPI_FREQUENCY       40000000   // 40 MHz
#define SPI_READ_FREQUENCY   6000000   //  6 MHz for reads

// ---- Font support ----------------------------------------------------------
// Built-in Adafruit-compatible fonts (used by drawString / setTextSize)
#define LOAD_GLCD    // Font 1 — default 8 px Adafruit font (used in sketch)
#define LOAD_FONT2   // Font 2 — 16 px
#define LOAD_FONT4   // Font 4 — 26 px
#define LOAD_FONT6   // Font 6 — 48 px (digits only)
#define LOAD_FONT7   // Font 7 — 7-segment 48 px (digits only)
#define LOAD_FONT8   // Font 8 — 75 px (digits only)
#define LOAD_GFXFF   // FreeFonts — use #include <Fonts/...> in sketch

#define SMOOTH_FONT
