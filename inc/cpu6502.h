#ifndef CPU6502_H
#define CPU6502_H
#include "common.h"
/*
Registers
PC	program counter	(16 bit)
AC	accumulator	(8 bit)
X	X register	(8 bit)
Y	Y register	(8 bit)
SR	status register [NV-BDIZC]	(8 bit)
SP	stack pointer	(8 bit)
Note: The status register (SR) is also known as the P register.

SR Flags (bit 7 to bit 0)
N	Negative
V	Overflow
-	ignored
B	Break
D	Decimal (use BCD for arithmetics)
I	Interrupt (IRQ disable)
Z	Zero
C	Carry
*/

/*creating empty class BUS to pass the compiler*/
class BUS;

class CPU6502
{
private:
    /*register*/
    WORD PC; // program couter
    BYTE AC; // accumulator
    BYTE X;  // X register
    BYTE Y;  // Y register
    BYTE SR; // status register
    BYTE SP; // stack register

    /*BIT STATUS*/
    enum FLAG
    {
        N = 1 << 7,  // Negative
        V = 1 << 6,  // Overflow
        IG = 1 << 5, // ignored
        B = 1 << 4,  // ignored
        D = 1 << 3,  // Decimal
        I = 1 << 2,  // Interrupt
        Z = 1 << 1,  // Zero
        C = 1 << 0   // Carry
    };

    bool getflag(FLAG f);           // return state of bit flag
    void setflag(FLAG f, bool val); // set bit flag 0 or 1

private:
    /*Address mode*/
    BYTE IME();  // immediate
    BYTE ZP0();  // zeropage
    BYTE ZPX();  // zeropage,X
    BYTE ABS();  // absolute
    BYTE ABX();  // absolute,X
    BYTE ABY();  // absolute,Y
    BYTE INDX(); //(indirect,X)
    BYTE INDY(); // (indirect),Y

private:
    /*Transfer Instructions*/
    BYTE LDA(); // load accumulator
    BYTE LDX(); // load X
    BYTE LDY(); // load Y
    BYTE STA(); // store accumulator
    BYTE STX(); // store X
    BYTE STY(); // store Y
    BYTE TAX(); // transfer accumulator to X
    BYTE TAY(); // transfer accumulator to Y
    BYTE TSX(); // transfer stack pointer to X
    BYTE TXA(); // transfer X to accumulator
    BYTE TXS(); // transfer X to stack pointer
    BYTE TYA(); // transfer X to stack pointer

private:
    /*Stack Instructions*/
    BYTE PHA(); // push accumulator
    BYTE PHP(); // push processor status register (with break flag set)
    BYTE PLA(); // pull accumulator
    BYTE PLP(); // pull processor status register

private:
    /*Decrements & Increments*/
    BYTE DEC(); // Decrements & Increments
    BYTE DEX(); // decrement X
    BYTE DEY(); // decrement X
    BYTE INC(); // increment (memory)
    BYTE INX(); // increment X
    BYTE INY(); // increment Y

private:
    /*Arithmetic Operations*/
    BYTE ADC(); // add with carry (prepare by CLC)
    BYTE SBC(); // subtract with carry (prepare by SEC)

private:
    /*Arithmetic Operations*/
    BYTE AND(); // and (with accumulator)
    BYTE EOR(); // exclusive or (with accumulator)
    BYTE ORA(); //(inclusive) or with accumulator

private:
    /*Shift & Rotate Instructions*/
    BYTE ASL(); // arithmetic shift left (shifts in a zero bit on the right)
    BYTE LSR(); // logical shift right (shifts in a zero bit on the left)
    BYTE ROL(); // rotate left (shifts in carry bit on the right)
    BYTE ROR(); // rotate right (shifts in zero bit on the left)

private:
    /*Flag Instructions*/
    BYTE CLC(); // clear carry
    BYTE CLD(); // clear decimal (BCD arithmetics disabled)
    BYTE CLI(); // clear interrupt disable
    BYTE CLV(); // clear overflow
    BYTE SEC(); // set carry
    BYTE SED(); // set decimal (BCD arithmetics enabled)
    BYTE SEI(); // set interrupt disable

private:
    /*Comparisons*/
    BYTE CMP(); // compare (with accumulator)
    BYTE CPX(); // compare with X
    BYTE CPY(); // compare with Y

private:
    /*Conditional Branch Instructions*/
    BYTE BCC(); // branch on carry clear
    BYTE BCS(); // branch on carry set
    BYTE BEQ(); // branch on equal (zero set)
    BYTE BMI(); // branch on minus (negative set)
    BYTE BNE(); // branch on not equal (zero clear)
    BYTE BPL(); // branch on not equal (zero clear)
    BYTE BVC(); // branch on overflow clear
    BYTE BVS(); // branch on overflow set

private:
    /*Jumps & Subroutines*/
    BYTE JMP(); // jump
    BYTE JSR(); // Jumps & Subroutines
    BYTE RTS(); // return from subroutine

private:
    /*Interrupts*/
    BYTE BRK(); // break / software interrupt
    BYTE RTI(); // return from interrupt

private:
    /*Other*/
    BYTE BIT(); // bit test (accumulator & memory)
    BYTE NOP(); // no operation

private:
    BUS *bus = nullptr; // Create pointer link to Bus communicate

public:
    CPU6502();
    ~CPU6502();
    void reset();
    void clock();
    void irq();
    void fetch();
    void connectBus(BUS *b);
    bool completed(); // return true if instruction completed

    struct INSTRUCTION
    {
        string name;
        BYTE(CPU6502::*operation)
        (void) = nullptr;
        BYTE(CPU6502::*addrmode)
        (void) = nullptr;
        int cycles = 0;
    };

    vector<INSTRUCTION> look_up;
};

#endif