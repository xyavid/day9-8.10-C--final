#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "main.h"
#include "led.h"

#define LED_ALL_MASK ((uint16_t)(LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN))

typedef enum
{
    STATE_IDLE=0,
    STATE_RUNNING,
    STATE_ALARM,
    STATE_COUNT
}state_id;

typedef void (*state_func)(void);


extern state_id current_state;
extern const state_func state_table[STATE_COUNT + 1];
#endif
