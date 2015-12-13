#ifndef CPU_PROCESSOR
#define CPU_PROCESSOR

#include "memory.h"

class CPU
{
    public:
        const byte c_BaseAddress;
        const byte c_ReservedAddress;
        const byte c_JumpToAddress;
        const byte c_AddressCeiling;
    private:
        byte m_ProgramCounter;
        byte m_Register0;
        byte m_Register1;
        bool m_OverflowError;
        bool m_UnderflowError;
        bool m_SignedMode;
        bool m_Halt;
        Memory* m_TheMemory;
        const byte fetch();
        void decode(const byte& p_OpCode);

    public:
        CPU(Memory* p_TheMemory);
        ~CPU();
        void reset();
        void run();
        void halt();
        void add();
        void beep();
        void store();
        void print();
        void clearRegister0();
        void clearRegister1();
        void clearBoth();
        void jumpEqual();
        void copy0();
        void copy1();
        void jumpTo();
};


#endif
