#include "Utility.h"

#include <fstream>
#include <iostream>
#include <algorithm>


int charToInt(const char c)
{
	return static_cast<int>(c) - static_cast<int>('a');
}

int intToChar(const char num)
{
	return static_cast<char>(num) + static_cast<char>('a');;
}

std::vector<std::string> ReadDictionary(std::string file_name)
{
	std::fstream fileInput(file_name, std::ios::in);

	if (fileInput.fail())
	{
		std::cout << "Cannot open file at " << file_name << std::endl;
	}

	std::string word;

	std::vector<std::string> returnVal;

	while (getline(fileInput, word))
	{
		returnVal.push_back(word);
	}

	fileInput.close();

	return returnVal;
}

std::string getSourceString(std::string fileName)
{
	std::fstream fileInput(fileName, std::ios::in);

	if (fileInput.fail())
	{
		std::cout << "Cannot open file at " << fileName << std::endl;
	}

	std::string source;
	getline(fileInput, source);

	fileInput.close();
	
	//delete whilte space
	source.erase(std::remove_if(source.begin(), source.end(), isspace), source.end());
	return source;
}

void writeResult(std::vector<std::string> wordList, std::string fileName)
{
	std::fstream fileOutput(fileName, std::ios::out);

	fileOutput << wordList.size() << std::endl;

	for (auto i : wordList)
	{
		fileOutput << i << std::endl;
	}

	fileOutput.close();
}

