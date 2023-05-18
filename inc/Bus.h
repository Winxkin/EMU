#ifndef BUS_H
#define BUS_H
#include "common.h"
#include "cpu6502.h"

class BUS
{
private:
    /*component in BUS*/
    CPU6502 cpu;
    array<BYTE, 1024 * 64> ram;

public:
    BUS();
    ~BUS();
    BYTE read(uint16_t addr, bool breadonly = false);
    void write(uint16_t addr, BYTE data);
};

#endif