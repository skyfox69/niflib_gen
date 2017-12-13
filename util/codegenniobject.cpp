/**
 *  codegenniobject.cpp
 *  Implementation of class CodeGenNiObject
 *  Created on:      10-Dec-2017 12:30
 *  Original author: skyfox69
 */

#include "util/codegenniobject.h"
#include "parameters.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace niflib_gen;

/*---------------------------------------------------------------------------*/
CodeGenNiObject::CodeGenNiObject(std::string pathBase, XMLFile* pXmlFile)
	:	CodeGenBase(),
		_pathBase(pathBase),
		_pXmlFile(pXmlFile)
{}

/*---------------------------------------------------------------------------*/
bool CodeGenNiObject::generate(const std::string classToParse) {
	niflib_gen::itervecstr*		pIter(nullptr);

	while (true) {
		pIter = _pXmlFile->findItem("niobject", pIter);
		if (pIter == nullptr) {
			break;
		}

		if ((!classToParse.empty() && ((*pIter)->find("name=\"" + classToParse + "\"") != std::string::npos)) ||
		    classToParse.empty()) {

			generateHeader(*pIter);


		}
	};
	return true;
}

/*---------------------------------------------------------------------------*/
bool CodeGenNiObject::generateHeader(niflib_gen::itervecstr iterStart) {
	//  className, baseName, fileName
	_classData._selfClass = extractString(*iterStart, "name=\"", "\"");
	_classData._baseClass = extractString(*iterStart, "inherit=\"", "\"");

	system(("mkdir -p " + _classData.getPathHeader(_pathBase)).c_str());








	//  open file and write header comment
	std::ofstream	outFile(_classData.getPathHeader(_pathBase, true));

	if (outFile.fail()) {
		return false;
	}

	outFile << "/**\n"
		<< " *  " << _classData._selfClass._fileName << ".h\n"
		<< " *  Implementation of class " << _classData._selfClass._className << "\n"
		<< " *  Generated on: " << "datum" << "\n"
		<< " *  DO NOT MODIFY OUTSIDE OF MARKED REGIONS\n"
		<< " */\n"
		<< "#pragma once\n\n";

/*
	outFile << "/**\n"
			<< " *  " << cFileName << ".h\n"
			<< " *  Implementation of class " << className << "\n"
			<< " *  Created on:      \n"
			<< " *  Original author: niflib_gen\n"
			<< " *  DO NOT MODIFY OUTSIDE OF MARKED REGIONS\n"
			<< " *\/\n"
			<< "#pragma once\n\n";

	if (!bFileName.empty()) {
		outFile << "#include \"";
		if (!bPathName.empty()) {
			outFile << bPathName << "/";
		}
		outFile << bFileName << ".h\"\n\n";
	}

	outFile << "namespace " << NIFLIB_GEN_NAMESPACE << " {\n"
			<< "\tclass " << className;

	if (!baseName.empty()) {
		outFile << " : public " << baseName;
	}
	outFile << " {\n";





	//  write closing brackets
	outFile << "\t};\n};\n";
*/
	//  flush and close file
	outFile.flush();
	outFile.close();

	return true;
}

