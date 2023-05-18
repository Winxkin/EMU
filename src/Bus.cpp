#include "Bus.h"

BUS::BUS()
{
    cpu.connectBus(this);
}

BUS::~BUS()
{
}

BYTE BUS::read(uint16_t addr, bool breadonly)
{
    if (addr >= 0x0000 && addr <= 0xFFFF)
    {
        _log_info("read BYTE from ram at %X", addr);
        return ram[addr];
    }
    else
    {
        log_error("out of address");
        return ERROR;
    }
}

void BUS::write(uint16_t addr, BYTE data)
{
    if (addr >= 0x0000 && addr <= 0xFFFF)
    {
        _log_info("write BYTE into ram at %X", addr);
        ram[addr] = data;
    }
    else
    {
        log_error("out of address");
    }
}
