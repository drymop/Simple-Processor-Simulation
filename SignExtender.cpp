#ifndef SIGN_EXTENDER_CPP_
#define SIGN_EXTENDER_CPP_

#include "SignExtender.h"

//TODO: Delete this
#include <iostream>

SignExtender::
SignExtender() : ProcessorComponent(NUM_INPUTS, NUM_OUTPUTS) {};

void
SignExtender::
setInput(int _line_id, bool _bit)
{
	m_inputs.set(_line_id, _bit);
	
	m_updated_inputs.set(_line_id);
	if (m_updated_inputs.all())
		update();
}

bool
SignExtender::
getOutput(int _line_id)
{
	return m_outputs.test(_line_id);
}

void
SignExtender::
update()
{
	for (int i = 0; i < NUM_INPUTS; i++)
		m_outputs[i] = m_inputs[i];

	bool sign_bit = m_outputs[NUM_INPUTS - 1];
	for (int i = NUM_INPUTS; i < NUM_OUTPUTS; i++)
		m_outputs[i] = sign_bit;

	m_updated_inputs.reset();

	fireAllOutputs();

	// TODO: Delele this
	/*std::cout << std::hex << std::showbase;
	std::cout << "Update SignExtender: " << m_inputs.to_ulong() << " "
	<< m_outputs.to_ulong() << " " << m_updated_inputs.to_ulong() << std::endl;*/
}

#endif // SIGN_EXTENDER_CPP_


