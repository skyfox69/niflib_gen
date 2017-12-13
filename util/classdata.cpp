/**
*  classdata.cpp
*  Implementation of class ClassData
*  Created on:      13-Dec-2017 20:22
*  Original author: skyfox69
*/

#include "util/classdata.h"

using namespace niflib_gen;

/*---------------------------------------------------------------------------*/
std::string ClassData::getPathHeader(const std::string pathBase, const bool full) const {
	std::string		path(pathBase + "/inc/" + _selfClass._pathName);

	if (path.back() == '/') {
		path.pop_back();
	}
	if (full) {
		path += "/" + _selfClass._fileName + ".h";
	}
	return path;
}

/*---------------------------------------------------------------------------*/
std::string ClassData::getPathImplem(const std::string pathBase, const bool full) const {
	std::string		path(pathBase + "/src/" + _selfClass._pathName);

	if (path.back() == '/') {
		path.pop_back();
	}
	if (full) {
		path += "/" + _selfClass._fileName + ".cpp";
	}
	return path;
}

