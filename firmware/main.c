
#include <util/delay.h>
#include "Light_WS2812/light_ws2812.h"

#define LED_COUNT 8
struct cRGB leds[LED_COUNT];

int main(void)
{
    leds[0].r=255;
    leds[0].g=0;
    leds[0].b=0;

    int x = 0;

    #define COLOR_COUNT 6

    struct cRGB color_table[COLOR_COUNT];

    color_table[0].r = 255;
    color_table[0].g = 0;
    color_table[0].b = 0;

    color_table[1].r = 0;
    color_table[1].g = 255;
    color_table[1].b = 0;

    color_table[2].r = 255;
    color_table[2].g = 255;
    color_table[2].b = 0;

    color_table[3].r = 0;
    color_table[3].g = 0;
    color_table[3].b = 255;

    color_table[4].r = 0;
    color_table[4].g = 255;
    color_table[4].b = 255;

    color_table[5].r = 255;
    color_table[5].g = 0;
    color_table[5].b = 255;

    uint8_t current_color = 0;

    while(1)
    {
        for(int i=0; i<LED_COUNT; i++)
        {
            leds[i].r = 0;
            leds[i].g = 0;
            leds[i].b = 0;
        }

        leds[x++] = color_table[current_color];
        if(x ==LED_COUNT)
        {
            x=0;
            current_color++;
            if(current_color >= COLOR_COUNT)
                current_color = 0;
        }

        ws2812_setleds(leds,8);
        _delay_ms(60);
    }
}
