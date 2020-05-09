#ifndef _Tps22994_h
#define _Tps22994_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define TPS22994_I2C_ADDRESS        (0xE0>>1)
#define TPS22994_REG_CONTROL        0x05

enum mode_quick_dis
{
res_110=0,
res_490,
res_951,
high_imp
};


class tps22994
{
public:
//void channel_off(uint8_t address, uint8_t channel); 
void channel_off(uint8_t channel);

//void channel_on(uint8_t address, uint8_t channel);
void channel_on(uint8_t channel);

void channel_toggle(uint8_t channel);
//void channel_toggle(uint8_t address, uint8_t channel);

void config_all_quick_dis(uint8_t val= high_imp);
void write_ctrl_reg(uint8_t value);
/*!
	@brief retorna el registro de control
	@return uint8_t 
*/
void config_all_ch_to_i2c();
uint8_t read_ctrl_reg();
uint8_t read_mode_reg(uint8_t reg);
void set_address(uint8_t address_);
void quick_discharge(uint8_t ch, uint8_t val );
private:
uint8_t address= TPS22994_I2C_ADDRESS;
//uint8_t read_reg(uint8_t address, uint8_t reg);
//void write_reg(uint8_t address, uint8_t reg, uint8_t value);

void write_byte(uint8_t reg, uint8_t data);
uint8_t read_byte(uint8_t reg);
};
#endif

