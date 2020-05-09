#include "Tps22994.h"
#include <Wire.h>
void tps22994::channel_off(uint8_t channel)
{
	uint8_t ctrl_reg;

	ctrl_reg = read_byte(TPS22994_REG_CONTROL);
	ctrl_reg &= ~(1 << (channel & 0xF));
	write_byte(TPS22994_REG_CONTROL, ctrl_reg);
}
void tps22994::channel_on(uint8_t channel)
{
	uint8_t ctrl_reg;

	ctrl_reg = read_byte(TPS22994_REG_CONTROL);
	ctrl_reg |= (1 << (channel & 0xF));
	write_byte(TPS22994_REG_CONTROL, ctrl_reg);
}

void tps22994::channel_toggle(uint8_t channel)
{
	uint8_t ctrl_reg;

	ctrl_reg = read_byte(TPS22994_REG_CONTROL);
	ctrl_reg ^= (1 << (channel & 0xF));
	write_byte(TPS22994_REG_CONTROL, ctrl_reg);
}

void tps22994::config_all_quick_dis(uint8_t val)
{
	for (int i = 0x00; i < 0x04; i++)
	{
		quick_discharge(i, val);
	}

}

void tps22994::write_ctrl_reg(uint8_t value)
{
	write_byte(TPS22994_REG_CONTROL, value);
}

void tps22994::config_all_ch_to_i2c()
{
	write_byte(TPS22994_REG_CONTROL,0xF0);
}

uint8_t tps22994::read_ctrl_reg()
{
	return read_byte(TPS22994_REG_CONTROL);
}

uint8_t tps22994::read_mode_reg(uint8_t reg)//falta tranformar dec a hex, solo funciona con hex
{
	return read_byte(reg);
}

void tps22994::set_address(uint8_t address_)
{
	address = address_;
}

void tps22994::quick_discharge(uint8_t ch, uint8_t val)
{
	//00 110ohm  0
	//01 490 1
	//10 951 2
	//11 none 3
	uint8_t reg= read_byte(ch);
	reg = reg >> 2;
	reg = reg << 2;
	reg = reg | val;
	write_byte(ch, reg);
}

void tps22994::write_byte(uint8_t reg, uint8_t data)
{
	Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(reg);
	Wire.write(data);
	Wire.endTransmission();
}

uint8_t tps22994::read_byte(uint8_t reg)
{
	Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(reg);
	Wire.endTransmission();
	Wire.requestFrom(address, (byte)1);
	uint8_t value = Wire.read();
	Wire.endTransmission();
	return value;
}
