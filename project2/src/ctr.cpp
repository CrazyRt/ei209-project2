#include "ctr.hpp"
#include "env.hpp"
#include <iostream>
using namespace Env;

namespace MIPS {
void Ctr::onChange()
{
	// Add your code here
	std::cout<<"control   "<<name<<"   opcode   "<<in[opCode]<<std::endl;
	if (in[opCode] == B("000010")){
		setOutput(jump, 1);
	}
	if (in[opCode] == B("000000")){
		setOutput(regDst, 1);
		setOutput(ALUSrc, 0);
		setOutput(memToReg, 0);
		setOutput(regWrite, 1);
		setOutput(memRead, 0);
		setOutput(memWrite, 0);
		setOutput(branch, 0);
		setOutput(aluOp, 2);
	}
	if (in[opCode] == B("001000")){
		setOutput(regDst, 0);
		setOutput(ALUSrc, 1);
		setOutput(memToReg, 0);
		setOutput(regWrite, 1);
		setOutput(memRead, 0);
		setOutput(memWrite, 0);
		setOutput(branch, 0);
		setOutput(aluOp, 2);
	}
	if (in[opCode] == B("100011")){
		setOutput(regDst, 0);
		setOutput(ALUSrc, 1);
		setOutput(memToReg, 1);
		setOutput(regWrite, 1);
		setOutput(memRead, 1);
		setOutput(memWrite, 0);
		setOutput(branch, 0);
		setOutput(aluOp, 0);
	}
	if (in[opCode] == B("101011")){
		//setOutput(regDst, 1);
		setOutput(ALUSrc, 1);
		//setOutput(memToReg, 0);
		setOutput(regWrite, 0);
		setOutput(memRead, 0);
		setOutput(memWrite, 1);
		setOutput(branch, 0);
		setOutput(aluOp, 0);
	}
	if (in[opCode] == B("000100")){
		//setOutput(regDst, 1);
		setOutput(ALUSrc, 0);
		//setOutput(memToReg, 0);
		setOutput(regWrite, 0);
		setOutput(memRead, 0);
		setOutput(memWrite, 0);
		setOutput(branch, 1);
		setOutput(aluOp, 1);
	}
	//in[opCode]=0;
}
}
