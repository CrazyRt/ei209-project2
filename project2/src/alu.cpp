#include "alu.hpp"
#include "env.hpp"
using namespace Env;
	#include <iostream>

namespace MIPS {
void ALU::onChange()
{
	// Add your code here
	LineData result = 0;
	switch (in[aluCtr]){
	case 0: result = in[input1] & in[input2]; break;
	case 1: result = in[input1] | in[input2]; break;
	case 2: result = in[input1] + in[input2]; break;
	case 6: result = in[input1] - in[input2];
			if (in[input1] == in[input2]) setOutput(zero, 1);
			else setOutput(zero,0);
			break;
	case 7: result = 0; 
			if (in[input1] < in[input2]) ++result; 
			if (in[input1] == in[input2]) setOutput(zero, 1);
			break;
	case 12: result = ~(in[input1] | in[input2]); break;
	}
	setOutput(aluRes, result);
	std::cout<<name<<"  aluCtr   "<<in[aluCtr]<<"   input1  "<<in[input1] <<"  input2   "<<in[input2]<<"  aluOutput   "<<out[aluRes]<<std::endl;
}
}
