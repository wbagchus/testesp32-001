#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"

#define LCD_BK_LIGHT_PIN 22  // The backlight pin for your board

void app_main(void)
{
    // Initialize the backlight pin
    gpio_config_t bk_conf = {
        .pin_bit_mask = (1ULL << LCD_BK_LIGHT_PIN),
        .mode = GPIO_MODE_OUTPUT,
    };
    gpio_config(&bk_conf);

    // Turn ON the backlight
    gpio_set_level(LCD_BK_LIGHT_PIN, 1);
    
    ESP_LOGI("LCD_TEST", "Backlight is now ON!");
}
