#include "cpu.hpp"
#include "component.hpp"
#include "env.hpp"
#include <iostream>

using std::string;
using namespace Env;
using namespace MIPS;
using namespace std;

void BIND(BaseComponent &a, string output, BaseComponent &b, string input)
{
	a.bind(output, b.getListener(input));
}

EventListener partialListener(int start, int end, BaseComponent &comp, string name)
{
	return [=,&comp](LineData data) {
		unsigned int d = data;
		// 10011 << 3 = 11000
		d = d << (31 - end);
		// 11000 >> 3 = 00011
		d = d >> (start + 31 - end);
		comp.input(name, d);
	};
}

namespace MIPS {

	CPU::CPU() : pc(-4), instMem("Instruction Memory"), dataMem("Data Memory"),
		muxMem2Reg("muxMem2Reg"), muxAlu("muxAlu"), muxRegDes("muxRegDes")

	{
		// Add your code here
		BIND(pc,newPC,instMem,address);
		BIND(pc,memRead,instMem,memRead);

		instMem.bind(readData,partialListener(26,31,ctr,opCode));
		instMem.bind(readData,partialListener(21,25,reg,readReg1));
		instMem.bind(readData,partialListener(16,20,reg,readReg2));
		instMem.bind(readData,partialListener(16,20,muxAlu,input1));
		instMem.bind(readData,partialListener(11,15,muxAlu,input2));
		instMem.bind(readData,partialListener(0,15,signExtend,immInput));
		instMem.bind(readData,partialListener(0,5,aluControl,funct));
		BIND(ctr,regDst,muxAlu,muxSel);
		BIND(ctr,regWrite,reg,regWrite);
		BIND(signExtend,immData,muxRegDes,input2);
		
		BIND(ctr,memWrite,dataMem,memWrite);
		BIND(ctr,memRead,dataMem,memRead);
		BIND(reg,readData2,dataMem,writeData);
		
		BIND(reg,readData2,muxRegDes,input1);
		BIND(ctr,ALUSrc,muxRegDes,muxSel);
		BIND(muxAlu,muxOut,reg,writeReg);
		BIND(ctr,branch,pc,branch);
		BIND(ctr,jump,ctr,jump);
		BIND(signExtend,immData,pc,immData);
		BIND(ctr,memToReg,muxMem2Reg,muxSel);
		BIND(dataMem,readData,muxMem2Reg,input2);
		BIND(muxMem2Reg,muxOut,reg,writeData);
		BIND(ctr,aluOp,aluControl,aluOp);
		BIND(reg,readData1,alu,input1);
		BIND(muxRegDes,muxOut,alu,input2);
		BIND(alu,aluRes,dataMem,address);
		BIND(alu,aluRes,muxMem2Reg,input1);
		BIND(aluControl,aluCtr,alu,aluCtr);
		
		BIND(alu,zero,pc,zero);
	}

	LineData CPU::run()
	{
		int count = 0;
		while (instMem.output(readData) != 0xFFFFFFFF)
		{
			//std::cout<<instMem.output(readData)<<std::endl;
			// All program should be terminated in max_cpu_cycle cycles
			count++;
			if (count > max_cpu_cycle)
			{
				break;
			}
			// IF
			pc.clock();

			std::cout<<std::endl<<std::endl<<"pc clock is over"<<std::endl<<std::endl<<std::endl;
			instMem.clock();

			std::cout<<std::endl<<std::endl<<"instruction memory clock is over"<<std::endl<<std::endl<<std::endl;
			// Mem
			dataMem.clock();

			std::cout<<std::endl<<std::endl<<"data memory clock is over"<<std::endl<<std::endl<<std::endl;
			// WB
			reg.clock();

			std::cout<<std::endl<<std::endl<<"register clock is over"<<std::endl<<std::endl<<std::endl;
			
#ifdef DEBUG
			reg.logStatus();
#endif
		}
		// Get result
		
		reg.input(readReg1, 2);

		std::cout<<std::endl<<std::endl<<"result taken"<<std::endl<<std::endl<<std::endl;
		return reg.output(readData1);
	}

	void CPU::reset()
	{
		// Initialize Program Counter
		pc = PC(-4);
	}
}
