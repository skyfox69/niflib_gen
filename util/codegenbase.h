/**
*  codegenbase.h
*  Implementation of class CodeGenBase
*  Created on:      13-Dec-2017 20:22
*  Original author: skyfox69
*/
#pragma once

#include "classdata.h"

namespace niflib_gen {
	class CodeGenBase {
		protected:
			virtual	ClassFilePath		extractString(std::string text, const std::string delimStart, const std::string delimEnd);

		public:
										CodeGenBase() = default;
			virtual						~CodeGenBase() = default;
	};
};
