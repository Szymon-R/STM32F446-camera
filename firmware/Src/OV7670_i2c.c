#include "OV7670_i2c.h"

static uint8_t device_adress=0x42;

i2c_command commands[]=
{
	{"COM7",12,10,0x04}
};


uint8_t get_device_adress()
{
	return device_adress;
}
int setup_connection()
{
	if(	HAL_I2C_IsDeviceReady(&hi2c2,get_device_adress(),5,1000)!=HAL_OK)
	{
		error_handling("Couldn't set up connection");
		return 0;
	}
	return 1;
}

int send_command(i2c_command com)
{
	if(HAL_I2C_Master_Transmit(&hi2c2,get_device_adress(),(unsigned char*)(com.adress+com.set_up_value),2,1000)!=HAL_OK)
	{
		error_handling("Couldn't transmit the command via i2c");
		return 0;
	}
	return 1;
}

int read_command(i2c_command com)
{
	uint8_t data;
	HAL_StatusTypeDef result;
	result|=HAL_I2C_Master_Transmit(&hi2c2,get_device_adress(),(uint8_t*)(com.adress),2,1000);
	result|=HAL_I2C_Master_Receive(&hi2c2,get_device_adress(),&com.current_value,1,1000);
	if(result!=HAL_OK)
	{
		error_handling("Couldn't read rhe command via i2c");
		return 0;
	}
	return 1;
}