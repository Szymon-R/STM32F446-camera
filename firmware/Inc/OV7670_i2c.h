#ifndef OV7670_I2C_GUARD
#define OV7670_I2C_GUARD
#include "stm32f4xx_hal.h"
#include "i2c.h"
#include "debug.h"


typedef struct i2c_command
{
	const char* name;
	uint8_t adress;
	uint8_t current_value;
	uint8_t set_up_value;
}i2c_command;

extern i2c_command commands[];

int setup_connection(void);
inline uint8_t get_device_adress(void);
int send_command(i2c_command com);
int read_command(i2c_command com);

#endif
