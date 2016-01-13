#include "memory.hpp"
#include <iostream>
#include "env.hpp"
using namespace Env;
using std::vector;

namespace MIPS {

Memory::Memory(string name) : BaseComponent(name)
{
	memory.resize(max_mem_num);
}

void Memory::onChange()
{
	if (in[memRead]==1  && in[address] >= 0)
	//if (in[address]>=0)
	{
		setOutput(readData, memory[in[address]]);
		std::cout<<name<<"   readData  "<<memory[in[address]]<<"  address   "<<in[address]<<std::endl;

	}
}

void Memory::onClock()
{
	if (in[memWrite]==1)
	{
		memory[in[address]] = in[writeData];
		std::cout<<"save in"<< in[writeData] <<std::endl;
	}
	
	onChange();

}

void Memory::loadMemory(int address, LineData data)
{
	memory[address] = data;
}


//void Memory::deal()
//{
//	int lmax=0;
//	while (memory[lmax]!=0xFFFFFFFF) lmax+=4;
//	int a[5000];
//	for (int i=0;i<=lmax;i+=4) a[i*2]=memory[i];
//	for (int i=0;i<=2*lmax;i+=4) {memory[i]=a[i];memory[i+4]=0;}
//}
}


