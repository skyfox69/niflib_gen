/**
*  codegenerator.h
*  Implementation of class CodeGenerator
*  Created on:      10-Dec-2017 12:30
*  Original author: skyfox69
*/
#pragma once

#include <string>

namespace niflib_gen {
	class	XMLFile;

	class CodeGenerator {
		private:
			std::string					_pathBase;

		public:
										CodeGenerator(const std::string pathBase);
			virtual						~CodeGenerator() = default;

			virtual	bool				generateFromXmlFile(XMLFile* pXmlFile, const std::string classToParse = "");
	};
};
