#include "state_machine.h"


state_id current_state =STATE_IDLE;

static const uint16_t running_led[4]=
{
    LED1_PIN,
    LED2_PIN,
    LED3_PIN,
    LED4_PIN
};

static void state_idle_run(void);
static void state_running_run(void);
static void state_alarm_run(void);

const state_func state_table[STATE_COUNT+1] = 
{
    [STATE_IDLE] = state_idle_run,
    [STATE_RUNNING] = state_running_run,
    [STATE_ALARM] = state_alarm_run,
    [STATE_COUNT] = NULL
};

static void state_idle_run(void)
{
    led_off(LED_ALL_MASK);
    HAL_Delay(500U);

    current_state = STATE_RUNNING;
}

static void state_running_run(void)
{
    uint8_t i;
    for (i=0; i<4; i++)
    {
        led_on(running_led[i]);
        HAL_Delay(150U);
        led_off(running_led[i]);
    }

    current_state = STATE_ALARM;
}
// 三个led快闪三回
static void state_alarm_run(void)
{
    uint8_t i;
    for (i=0; i<3; i++)
    {
        led_on(LED_ALL_MASK);
        HAL_Delay(100U);
        led_off(LED_ALL_MASK);
        HAL_Delay(100U);
    }

    current_state = STATE_IDLE;
}

