#pragma once

#include <vector>
#include <string>

#define ALPHABET_SIZE 26

int charToInt(const char c);
int intToChar(const char num);

std::vector<std::string> ReadDictionary(std::string fileName);
std::string getSourceString(std::string fileName);

void writeResult(std::vector<std::string> wordList, std::string fileName);
