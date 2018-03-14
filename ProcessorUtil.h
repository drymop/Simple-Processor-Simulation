#ifndef PROCESSOR_UTIL_H_
#define PROCESSOR_UTIL_H_

#include "ProcessorComponent.h"

namespace ioutil
{
	void setInputs(ProcessorComponent& _comp, unsigned long _input);

	unsigned long getOutputs(ProcessorComponent& _comp);
};

#endif // PROCESSOR_UTIL_H_