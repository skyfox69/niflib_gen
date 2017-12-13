/**
*  codegenbase.cpp
*  Implementation of class CodeGenBase
*  Created on:      13-Dec-2017 20:22
*  Original author: skyfox69
*/

#include "util/codegenbase.h"
#include <algorithm>

using namespace niflib_gen;

/*---------------------------------------------------------------------------*/
ClassFilePath CodeGenBase::extractString(std::string text, const std::string delimStart, const std::string delimEnd) {
	ClassFilePath	result;
	size_t			posStart(text.find(delimStart));

	if (posStart != std::string::npos) {
		size_t			posEnd(std::string::npos);
		
		posStart += delimStart.size();
		posEnd    = text.find(delimEnd, posStart);
		if (posEnd != std::string::npos) {
			result._className = text.substr(posStart, posEnd - posStart);
			result._fileName  = result._className;
			std::transform(result._fileName.begin(), result._fileName.end(), result._fileName.begin(), ::tolower);
			result._pathName  = result._fileName.substr(0, result._className.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1));
		}
	}
	return result;
}

