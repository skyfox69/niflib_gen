/**
*  classdata.h
*  Implementation of class ClassData
*  Created on:      13-Dec-2017 20:22
*  Original author: skyfox69
*/
#pragma once

#include <string>

namespace niflib_gen {
	struct ClassFilePath {
		std::string					_className;
		std::string					_fileName;
		std::string					_pathName;
	};

	class ClassData {
		public:
			ClassFilePath			_selfClass;
			ClassFilePath			_baseClass;

		public:
									ClassData() = default;
			virtual					~ClassData() = default;

			virtual	std::string		getPathHeader(const std::string pathBase, const bool full = false) const;
			virtual	std::string		getPathImplem(const std::string pathBase, const bool full = false) const;
	};
};
