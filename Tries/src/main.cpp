#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Utility.h"
#include "TrieNode.h"

int main()
{
	std::cout << "Running!!!" << std::endl;
	std::vector<std::string> list = ReadDictionary("data/Dic.txt");

	// Root Node of Trie 
	TrieNode* root = getNode();

	buildTrieWords(root, list);

	std::string source = getSourceString("data/input.txt");

	std::vector<std::string> words = getAllWordFromAString(source, root);

	writeResult(words, "data/output.txt");
	std::cout << "Completed!!!" << std::endl;
	system("pause");
	return 0;
}