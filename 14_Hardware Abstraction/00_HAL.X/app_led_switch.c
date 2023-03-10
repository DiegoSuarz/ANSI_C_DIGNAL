#include "app_led_switch.h"
#include "system.h"

void app_led_switch()
{
    if(BUTTON_IsPressed(BUTTON_WIFI_CONN)== true)
    {
        LED_On(LED_WIFI_CONN);
        LED_Off(LED_ERROR);
    }
    else
    {
        LED_Off(LED_WIFI_CONN);
        LED_On(LED_ERROR);
    }
    
    
}