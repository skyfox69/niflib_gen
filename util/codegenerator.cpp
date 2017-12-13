/**
*  codegenerator.h
*  Implementation of class CodeGenerator
*  Created on:      10-Dec-2017 12:30
*  Original author: skyfox69
*/

#include "util/codegenerator.h"
#include "util/codegenniobject.h"
#include <iostream>

using namespace niflib_gen;

/*---------------------------------------------------------------------------*/
CodeGenerator::CodeGenerator(std::string pathBase)
	:	_pathBase(pathBase)
{}

/*---------------------------------------------------------------------------*/
bool CodeGenerator::generateFromXmlFile(XMLFile* pXmlFile, const std::string classToParse) {
	//  -- niobject --
	CodeGenNiObject(_pathBase, pXmlFile).generate(classToParse);



	return true;
}

