#include <iostream>
#include "memory.h"
#include "cpu.h"
using namespace std;
int main()
{
    cout<<"Init memory..."<<endl;
    Memory* theMemory = new Memory();
    cout<<"Ready"<<endl;
    cout<<"Memory size:"<<(int)theMemory->c_MaxAddress<<endl;
    cout<<"Adding machine code..."<<endl;
    //load0 value 1
    theMemory->write(1,1);
    theMemory->write(2,1);
    //load1 value 2
    theMemory->write(3,2);
    theMemory->write(4,2);
    //add
    theMemory->write(5,3);
    //store to 12
    theMemory->write(6,5);
    theMemory->write(7,12);
    //store to 12
    theMemory->write(8,6);
    theMemory->write(9,12);
    //beep
    theMemory->write(10,4);
    //halt
    theMemory->write(11,0);
    cout<<"Init CPU..."<<endl;
    CPU* myCPU = new CPU(theMemory);
    cout<<"Ready"<<endl;
    cout<<"Starting..."<<endl;

    myCPU->run();
    cout<<"Complete"<<endl;
    delete myCPU;
    delete theMemory;
}
