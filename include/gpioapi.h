/**
 */

#ifndef __GPIOAPI_H__
#define __GPIOAPI_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"
#define GPIO_NODE "/sys/class/gpio/gpio%d"
#define GPIO_DIRECTION "/sys/class/gpio/gpio%d/direction"
#define GPIO_VALUE "/sys/class/gpio/gpio%d/value"

#define PIO_A 1
#define PIO_B 2
#define PIO_C 3
#define EXPANDER 4

#define PIO_A_BASE 32
#define PIO_B_BASE 64
#define PIO_C_BASE 96
#define EXPANDER_BASE 200

#define MAX_LEN 50

// Error values
// pin value specified is invalid
#define EINVALPIN -1
// system call failed
#define ESYSCALLFAIL -2
// specified gpio not yet initialized
#define EGPIONOINIT -3
// One of the parameters that should match a macro doesn't match
#define EINVALPARAM -4
// The GPIO couldn't be initialized
#define EGPIONA -5

#define IN 0
#define OUT 1

typedef struct gpio_struct{
   int pin;
}gpio;

int readGPIO(gpio *node);
int setGPIO(gpio *node, int direction, int value);
int initGPIO(int chip, int pin, gpio *node);
int freeGPIO(gpio *node);

#endif
