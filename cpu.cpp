#include "cpu.h"
#include <iostream>
using namespace std;
CPU::CPU(Memory* p_TheMemory):
    c_BaseAddress(2),
    c_ReservedAddress(0),
    c_JumpToAddress(1),
    c_AddressCeiling(253),
    m_ProgramCounter(c_BaseAddress),
    m_Register0(0),
    m_Register1(0),
    m_OverflowError(false),
    m_UnderflowError(false),
    m_SignedMode(false),
    m_Halt(false),
    m_TheMemory(p_TheMemory)
{
}

CPU::~CPU()
{
    m_TheMemory=NULL;
}

void CPU::reset()
{
    m_ProgramCounter=0;
    m_OverflowError=false;
    m_UnderflowError=false;
    m_SignedMode=false;
    m_Halt=false;
}

const byte CPU::fetch()
{
    byte l_opCode=0;
    l_opCode=m_TheMemory->read(m_ProgramCounter);
    ++m_ProgramCounter;
    return l_opCode;
}

void CPU::decode(const byte& p_OpCode)
{
    if(m_Halt)
        return;
    switch(p_OpCode)
    {
        case 0:
            m_Halt = true;
            break;
        case 1:
            m_Register0=m_TheMemory->read(m_ProgramCounter);
            ++m_ProgramCounter;
            break;

        case 2:
            m_Register1=m_TheMemory->read(m_ProgramCounter);
            ++m_ProgramCounter;
            break;

        case 3:
            add();
            break;

        case 4:
            beep();
            break;

        case 5:
            store();
            break;

        case 6:
            print();
            break;

        case 7:
            clearRegister0();
            break;

        case 8:
            clearRegister1();
            break;

        case 9:

            jumpTo();
            break;

        case 10:
            jumpEqual();
            break;

        case 11:
            copy0();
            break;

        case 12:
            copy1();
            break;

        case 13:
            clearBoth();
            break;

    }
}

void CPU::add()
{
    m_Register0 += m_Register1;
}

void CPU::beep()
{
    cout<<'\a';
}

void CPU::store()
{
    m_Register1 = m_TheMemory->read(m_ProgramCounter);
    ++m_ProgramCounter;
    m_TheMemory->write(m_Register1,m_Register0);
}

void CPU::print()
{
    m_Register1=m_TheMemory->read(m_ProgramCounter);
    ++m_ProgramCounter;
    m_Register0=m_TheMemory->read(m_Register1);

    cout<<(int)m_Register0<<endl;
}

void CPU::halt()
{
    m_Halt = true;
}

void CPU::run()
{
    while(!m_Halt)
    {
       m_TheMemory->write(c_ReservedAddress,fetch());
       decode(m_TheMemory->read(c_ReservedAddress));
    }
}

void CPU::clearRegister0()
{
    m_Register0=0;
}

void CPU::clearRegister1()
{
    m_Register1=0;
}

void CPU::clearBoth()
{
    clearRegister0();
    clearRegister1();
}

void CPU::jumpTo()
{
    //m_TheMemory->write(m_TheMemory->c_JumpToAddress,m_TheMemory->read(m_ProgramCounter));
    //m_ProgramCounter=m_TheMemory->read(c_JumpToAddress);
}

void CPU::jumpEqual()
{
    if(m_Register0==m_Register1)
        jumpTo();
    else
        ++m_ProgramCounter;
}

void CPU::copy0()
{
    m_Register1=m_Register0;
}

void CPU::copy1()
{
    m_Register0=m_Register1;
}

