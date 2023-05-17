#include "CPU6502.h"

int main()
{
    log_info("starting emulation");
    CPU6502 cpu;
    cpu.reset();

    return 0;
}