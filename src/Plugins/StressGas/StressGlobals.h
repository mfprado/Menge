/*
 Menge Crowd Simulation Framework

 Copyright and trademark 2012-17 University of North Carolina at Chapel Hill

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0
 or
    LICENSE.txt in the root of the Menge repository.

 Any questions or comments should be sent to the authors menge@cs.unc.edu

 <http://gamma.cs.unc.edu/Menge/>
*/
#ifndef __STRESS_GLOBALS_H__
#define __STRESS_GLOBALS_H__

#include "StressGasConfig.h"
#include "StressManager.h"

//Define the global static proxy unit
namespace StressGAS {
	// TODO(curds01) 10/4/2016 - This is not particularly thread safe
	/**
	 *	@brief		Manager accessible to all StressGas members
	 */
	extern EXPORT_API StressManager *STRESS_MANAGER;
}	// namespace StressGAS

#endif
