#pragma once

#include <string>
#include <vector>

#include "Utility.h"

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];

	bool isEndOfWord;
};


TrieNode* getNode();

//word: value will be insert into Tries
void insert(struct TrieNode* root, std::string word);

//find words with prefix:
//str: prefix
//count: count characters of word (more than 2)
//listWords: return all of word found
void findWordsWithPrefix(TrieNode* root, int alphabet[], std::string str, int count, std::vector<std::string>& listWords);

std::vector<std::string> getAllWordFromAString(std::string source, TrieNode* root);

void buildTrieWords(TrieNode* root, std::vector<std::string> wordList);