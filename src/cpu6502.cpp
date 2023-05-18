#include "CPU6502.h"

CPU6502::CPU6502()
{
    log_info("Initialize CPU 6520");
    /*create loop up table mapping instruct operation and address mode */
    look_up =
        {{"LDA", &CPU6502::LDA, &CPU6502::IME, 2}, {"LDA", &CPU6502::LDA, &CPU6502::ZP0, 3}, {"LDA", &CPU6502::LDA, &CPU6502::ZPX, 4}, {"LDA", &CPU6502::LDA, &CPU6502::ABS, 4}, {"LDA", &CPU6502::LDA, &CPU6502::ABX, 4}, {"LDA", &CPU6502::LDA, &CPU6502::ABY, 4}, {"LDA", &CPU6502::LDA, &CPU6502::INDX, 6}, {"LDA", &CPU6502::LDA, &CPU6502::INDY, 5}};

    reset();
};

CPU6502::~CPU6502()
{
    log_info("Stop CPU 6520");
};

void CPU6502::reset()
{
    log_info("reset CPU");
    PC = 0xFFFC;
    X = 0x00;
    Y = 0x00;
    SR = 0x00;
};

void CPU6502::fetch()
{
}
void CPU6502::connectBus(BUS *b)
{
    bus = b;
};

bool CPU6502::getflag(FLAG f)
{
    if (f & SR)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void CPU6502::setflag(FLAG f, bool val)
{
    if (val)
    {
        SR |= f; // set flag to 1
    }
    else
    {
        SR &= ~f; // clear flag
    }
}

BYTE CPU6502::IME()
{
    return 0;
}

BYTE CPU6502::ZP0()
{
    return 0;
}

BYTE CPU6502::ZPX()
{
    return 0;
}

BYTE CPU6502::ABS()
{
    return 0;
}

BYTE CPU6502::ABX()
{
    return 0;
}

BYTE CPU6502::ABY()
{
    return 0;
}

BYTE CPU6502::INDX()
{
    return 0;
}

BYTE CPU6502::INDY()
{
    return 0;
}

BYTE CPU6502::LDA()
{
    return 0;
}

BYTE CPU6502::LDX()
{
    return 0;
}

BYTE CPU6502::LDY()
{
    return 0;
}

BYTE CPU6502::STA()
{
    return 0;
}

BYTE CPU6502::STX()
{
    return 0;
}

BYTE CPU6502::STY()
{
    return 0;
}

BYTE CPU6502::TAX()
{
    return 0;
}

BYTE CPU6502::TAY()
{
    return 0;
}

BYTE CPU6502::TSX()
{
    return 0;
}

BYTE CPU6502::TXA()
{
    return 0;
}

BYTE CPU6502::TXS()
{
    return 0;
}

BYTE CPU6502::TYA()
{
    return 0;
}

BYTE CPU6502::PHA()
{
    return 0;
}

BYTE CPU6502::PHP()
{
    return 0;
}

BYTE CPU6502::PLA()
{
    return 0;
}

BYTE CPU6502::PLP()
{
    return 0;
}

BYTE CPU6502::DEC()
{
    return 0;
}

BYTE CPU6502::DEX()
{
    return 0;
}

BYTE CPU6502::DEY()
{
    return 0;
}

BYTE CPU6502::INC()
{
    return 0;
}

BYTE CPU6502::INX()
{
    return 0;
}

BYTE CPU6502::INY()
{
    return 0;
}

BYTE CPU6502::ADC()
{
    return 0;
}

BYTE CPU6502::SBC()
{
    return 0;
}

BYTE CPU6502::AND()
{
    return 0;
}

BYTE CPU6502::EOR()
{
    return 0;
}

BYTE CPU6502::ORA()
{
    return 0;
}

BYTE CPU6502::ASL()
{
    return 0;
}

BYTE CPU6502::LSR()
{
    return 0;
}

BYTE CPU6502::ROL()
{
    return 0;
}

BYTE CPU6502::ROR()
{
    return 0;
}

BYTE CPU6502::CLC()
{
    return 0;
}

BYTE CPU6502::CLD()
{
    return 0;
}

BYTE CPU6502::CLI()
{
    return 0;
}

BYTE CPU6502::CLV()
{
    return 0;
}

BYTE CPU6502::SEC()
{
    return 0;
}

BYTE CPU6502::SED()
{
    return 0;
}

BYTE CPU6502::SEI()
{
    return 0;
}

BYTE CPU6502::CMP()
{
    return 0;
}

BYTE CPU6502::CPX()
{
    return 0;
}

BYTE CPU6502::CPY()
{
    return 0;
}

BYTE CPU6502::BCC()
{
    return 0;
}

BYTE CPU6502::BCS()
{
    return 0;
}

BYTE CPU6502::BEQ()
{
    return 0;
}

BYTE CPU6502::BMI()
{
    return 0;
}

BYTE CPU6502::BNE()
{
    return 0;
}

BYTE CPU6502::BPL()
{
    return 0;
}

BYTE CPU6502::BVC()
{
    return 0;
}

BYTE CPU6502::BVS()
{
    return 0;
}

BYTE CPU6502::JMP()
{
    return 0;
}

BYTE CPU6502::JSR()
{
    return 0;
}

BYTE CPU6502::RTS()
{
    return 0;
}

BYTE CPU6502::BRK()
{
    return 0;
}

BYTE CPU6502::RTI()
{
    return 0;
}

BYTE CPU6502::BIT()
{
    return 0;
}

BYTE CPU6502::NOP()
{
    return 0;
}
