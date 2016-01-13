#include "pc.hpp"
#include "env.hpp"
#include <iostream>
using namespace Env;

namespace MIPS {
void PC::onClock()
{
	// Add your code here

	if (in[branch] && in[zero] == 1) {
		m_pc+=in[immData]*4;
	}
	
	m_pc+=4;
	std::cout<<"pc"<<m_pc<<"   branch   "<<in[branch]<<" zero  "<< in[zero]<<" m_pc  "<< m_pc<<" immData  "<< in[immData]<<std::endl;
	int n_pc=m_pc+4;
	setOutput(memRead,1);
	setOutput(newPC,m_pc);	
}
}
