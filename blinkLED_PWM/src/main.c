#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h" // for PWM
#include "esp_err.h"     // for PWM

#define BLINK_GPIO 2 //in-board blue LED

void app_main() {

    // Prepare and set configuration of timers that will be used by LED Controller
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_8_BIT, // resolution of PWM duty
        .freq_hz = 500,                      // frequency of PWM signal
        .speed_mode = LEDC_HIGH_SPEED_MODE,  // timer mode
        .timer_num = LEDC_TIMER_0,           // timer index
    };
    ledc_timer_config(&ledc_timer); // Set configuration of timer0 for high speed channels

    ledc_channel_config_t ledc_channel = {
        .channel    = LEDC_CHANNEL_0,
        .duty       = 0,
        .gpio_num   = BLINK_GPIO,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);

    while(1) {
        // PWM
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 0);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 0.5s off

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 64);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 0.5s at 25%

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 128);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 0.5s at 50%

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 191);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 0.5s at 75%

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 255);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 0.5s at 100%

    }
}
