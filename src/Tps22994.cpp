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

void tps22994::write_ctrl_reg(uint8_t value)
{
	write_byte(TPS22994_REG_CONTROL, value);
}

uint8_t tps22994::read_ctrl_reg()
{
	return read_byte(TPS22994_REG_CONTROL);
}

void tps22994::set_address(uint8_t address_)
{
	address = address_;
}

void tps22994::write_byte(uint8_t reg, uint8_t data)
{
	Wire.beginTransmission(address);
	Wire.write(reg);
	Wire.write(data);
	Wire.endTransmission();
}

uint8_t tps22994::read_byte(uint8_t reg)
{
	////uint8_t data = 0;

	Wire.beginTransmission(address);
	Wire.write(reg);
	Wire.endTransmission();
	Wire.requestFrom(reg, (byte)1);
	return Wire.read();
}
