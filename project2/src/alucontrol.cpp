#include "alucontrol.hpp"
#include "env.hpp"
#include <iostream>
using namespace Env;

namespace MIPS {
	void ALUControl::onChange()
	{
		// Add your code here
		std::cout<<"alu control    "<<in[aluOp]<<"   "<<in[funct]<<std::endl;
		if (in[aluOp] == 0) {
			setOutput(aluCtr, 2);
			return;
		}
		if (in[aluOp] == 1) {
			setOutput(aluCtr, 6);
			return;
		}
		if (in[aluOp] == 2) {
			if (in[funct] == 0) {
				setOutput(aluCtr, 2);
				return;
			}
			if (in[funct] == 32) {
				setOutput(aluCtr, 2);
				return;
			}
			if (in[funct] == 2) {
				setOutput(aluCtr, 6);
				return;
			}
			if (in[funct] == 4) {
				setOutput(aluCtr, 0);
				return;
			}
			if (in[funct] == 5) {
				setOutput(aluCtr, 1);
				return;
			}
			if (in[funct] == 10) {
				setOutput(aluCtr, 7);
				return;
			}
			if (in[funct]==34){
				setOutput(aluCtr, 6);
				return;
			}
			if (in[funct] == 8) {
				setOutput(aluCtr, 2);
				return;
			}
			if (in[funct] == 1) {
				setOutput(aluCtr, 2);
				return;
			}
		}

	}
}