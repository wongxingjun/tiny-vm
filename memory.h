#ifndef MEMORY
#define MEMORY

typedef unsigned char byte;

class Memory
{
    public:
        const byte c_MaxAddress;

    private:
        byte* m_MemorySpace;

    public:
        Memory();
        ~Memory();
        void clear();
        const byte& read(const byte& p_Address);
        void write(const byte& p_Address, const byte& p_Value);

};


#endif
