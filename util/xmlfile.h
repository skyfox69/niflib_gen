/**
*  xmlfile.h
*  Implementation of class XMLFile
*  Created on:      10-Dec-2017 12:30
*  Original author: skyfox69
*/
#pragma once

#include <vector>
#include <string>

namespace niflib_gen {
	typedef std::vector<std::string>::iterator	itervecstr;

	class XMLFile {
		private:
			std::vector<std::string>	_lines;
			itervecstr					_iterLines;

		public:
										XMLFile() = default;
			virtual						~XMLFile() = default;

			virtual	bool				readFile(const std::string fileName);
			virtual	itervecstr*			findItem(const std::string typeName, itervecstr* pIterIn = nullptr);
	};
};
