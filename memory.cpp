#include "memory.h"

Memory::Memory():c_MaxAddress(255),
    m_MemorySpace(new byte[c_MaxAddress])
{
    clear();
}

Memory::~Memory()
{
    if(m_MemorySpace!=nullptr)
    {
        delete[] m_MemorySpace;
        m_MemorySpace=nullptr;
    }
}

void Memory::clear()
{
    for(byte i=0;i<c_MaxAddress;i++)
    {
        m_MemorySpace[i]=0;
    }
}

const byte& Memory::read(const  byte& p_Address)
{
    return m_MemorySpace[p_Address];
}

void Memory::write(const byte& p_Address, const byte& p_Value)
{
    m_MemorySpace[p_Address]=p_Value;
}
