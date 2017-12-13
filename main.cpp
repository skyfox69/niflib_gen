/**
*  main.cpp
*  Entry point
*  Created on:      10-Dec-2017 12:18
*  Original author: skyfox69
*/
#include "util/xmlfile.h"
#include "util/codegenerator.h"
#include <iostream>
#include "unistd.h"

std::string		classToParse;
std::string		inputFileName;
std::string		outputPathName;

/*---------------------------------------------------------------------------*/
void usage() {
	std::cout << "usage: niflib_gen [options] <XML-fileName> <target-directory>" << std::endl
		<< "Copyright (c) 2018 by Skyfox69" << std::endl << std::endl
		<< " options:" << std::endl
		<< " -c<name>\tgenerate class <name>" << std::endl
		<< " -h\t\tshow help (this text)" << std::endl
		<< std::endl;
}

/*---------------------------------------------------------------------------*/
bool decodeParameters(int argc, char** argv) {
	int		params(argc);
	int		c(0);

	if (argc < 3) {
		return false;
	}
	outputPathName = argv[argc - 1];
	inputFileName  = argv[argc - 2];
	argc -= 2;

	while ((c = getopt(argc, argv, "c:h")) != -1) {
		switch (c) {
			case 'c':
				if (*optarg == 0) {
					return false;
				}
				classToParse = optarg;
				--params;
				break;

			case 'h':
			default:
				return false;
		}
	}
	return true;
}

/*---------------------------------------------------------------------------*/
int main(int argc, char** argv) {
	if (!decodeParameters(argc, argv)) {
		usage();
		return -1;
	}

	//  read XML file
	niflib_gen::XMLFile		xmlFile;

	if (!xmlFile.readFile(inputFileName)) {
		std::cout << "error reading XML file '" << inputFileName << "'" << std::endl;
		return -1;
	}

	//  generate code
	niflib_gen::CodeGenerator		codeGenerator(outputPathName);

	codeGenerator.generateFromXmlFile(&xmlFile, classToParse);







    return 0;
}


