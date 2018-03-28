#ifndef ALU_CONTROL_CPP_
#define ALU_CONTROL_CPP_

#include "ALUControl.h"


const std::bitset<ALUControl::NUM_INPUTS> ALUControl::ALU_OP_MASK (0b11);


ALUControl::
ALUControl() : ProcessorComponent(NUM_INPUTS, NUM_OUTPUTS) {}


void
ALUControl::
setInput(int _line_id, bool _bit)
{
	m_inputs.set(_line_id, _bit);
	m_updated_inputs.set(_line_id);

	if (m_updated_inputs.all())
		updateOutputs();
}


void
ALUControl::
updateOutputs()
{
	unsigned long aluOp = (m_inputs >> aluOpStartID() & ALU_OP_MASK).to_ulong();
	unsigned long func  = (m_inputs >> funcStartID()).to_ulong();
	switch (aluOp)
	{
		case OP_ADD: m_outputs = OUT_ADD; break;
		case OP_SUB: m_outputs = OUT_SUB; break;
		default: switch (func)
		{
			case FUNC_ADD: m_outputs = OUT_ADD; break;
			case FUNC_SUB: m_outputs = OUT_SUB; break;
			case FUNC_SLT: m_outputs = OUT_SLT; break;
		}
	}

	m_updated_inputs.reset();
	fireAllOutputs();
}

#endif // ALU_CONTROL_CPP_