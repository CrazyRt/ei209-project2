#include "reg.hpp"
#include "env.hpp"
#include <iostream>
using namespace Env;
using std::vector;

namespace MIPS {
Reg::Reg() : BaseComponent("Register Stack")
{
	memory.resize(max_reg_num);
}
void Reg::onChange()
{
	
	// Add your code here
	setOutput(readData1, memory[in[readReg1]]);
	setOutput(readData2, memory[in[readReg2]]);

	//std::cout<<name<<"    readData1      "<<memory[in[readReg1]]<<" readData2   "<<memory[in[readReg2]]<<std::endl;
}

void Reg::onClock()
{
	// Add your code here
	//std::cout<<name<<"   regWrite      "<<"    "<<in[regWrite]<<std::endl;
		if (in[regWrite] == 1){
		memory[in[writeReg]] = in[writeData];
		std::cout<<name<<"   reg  writedata      "<<"    "<<in[writeData]<<std::endl;
		//std::cout<<name<<"   writeReg     "<<"    "<<in[writeReg]<<std::endl;
		std::cout<<name<<"   v0     "<<"    "<<memory[2]<<std::endl;
		std::cout<<name<<"   v1     "<<"    "<<memory[3]<<std::endl;
		std::cout<<name<<"   v2     "<<"    "<<memory[4]<<std::endl;
		std::cout<<name<<"   v3     "<<"    "<<memory[5]<<std::endl;
		std::cout<<name<<"   v4     "<<"    "<<memory[6]<<std::endl;
		std::cout<<name<<"   v5     "<<"    "<<memory[7]<<std::endl;
		
	}	
		onChange();
}

void Reg::logStatus()
{
	printf("=========================\n");
	printf("Reg value: \n");
	for (int i = 0 ; i != memory.size(); ++i)
	{
		printf("r%d\t:%d\n", i, memory[i]);
	}
	printf("=========================\n");
}
}
