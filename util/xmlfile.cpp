/**
*  xmlfile.cpp
*  Implementation of class XMLFile
*  Created on:      10-Dec-2017 12:30
*  Original author: skyfox69
*/
#include "util/xmlfile.h"
#include <fstream>
#include <iostream>

using namespace niflib_gen;

/*---------------------------------------------------------------------------*/
bool XMLFile::readFile(const std::string fileName) {
	if (fileName.empty()) {
		return false;
	}

	//  open file
	std::ifstream	inStream(fileName);
	std::string		line;

	if (inStream.fail()) {
		return false;
	}

	//  read lines into array
	while (std::getline(inStream, line)) {
		_lines.push_back(line);
	}

	//  clean up
	inStream.close();

	std::cout << "read " << _lines.size() << " lines" << std::endl;
	return true;
}

/*---------------------------------------------------------------------------*/
itervecstr* XMLFile::findItem(const std::string typeName, itervecstr* pIterIn) {
	itervecstr*		pIter(nullptr);

	if (!typeName.empty()) {
		//  reset iterator if new start initiated
		if (pIterIn == nullptr) {
			_iterLines = _lines.begin();
		} else {
			++_iterLines;
		}

		//  search next occurance of typeName
		for (; _iterLines != _lines.end(); ++_iterLines) {
			if (_iterLines->find("<" + typeName) != std::string::npos) {
				pIter = &_iterLines;
				break;
			}
		}
	}
	return pIter;
}

