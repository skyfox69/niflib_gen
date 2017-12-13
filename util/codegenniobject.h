/**
*  codegenniobject.h
*  Implementation of class CodeGenNiObject
*  Created on:      10-Dec-2017 12:30
*  Original author: skyfox69
*/
#pragma once

#include "util/codegenbase.h"
#include "util/xmlfile.h"
#include "util/classdata.h"
#include <string>

namespace niflib_gen {
	class CodeGenNiObject : protected CodeGenBase {
		private:
			XMLFile*					_pXmlFile;
			ClassData					_classData;
			std::string					_pathBase;

			virtual	bool				generateHeader(niflib_gen::itervecstr iterStart);

		public:
										CodeGenNiObject(const std::string pathBase, XMLFile* pXmlFile);
			virtual						~CodeGenNiObject() = default;

			virtual	bool				generate(const std::string classToParse);
	};
};
