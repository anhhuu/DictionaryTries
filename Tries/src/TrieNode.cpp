#include "TrieNode.h"
#include "Utility.h"


TrieNode* getNode()
{
	TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		pNode->children[i] = nullptr;
	}

	return pNode;
}

void insert(TrieNode* root, std::string key)
{
	TrieNode* pChild = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = charToInt(key[i]);

		if (pChild->children[index] == nullptr)
		{
			pChild->children[index] = getNode();
		}

		pChild = pChild->children[index];
	}

	//make last node as leaf node 
	pChild->isEndOfWord = true;
}

void findWordsWithPrefix(TrieNode* root, int alphabet[], std::string str, int count, std::vector<std::string>& listWords)
{
	//if we found word in trie / dictionary 
	if (root->isEndOfWord == true && count >= 2)
		listWords.push_back(str);

	//traverse all child's of current root 
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (alphabet[i] != 0 && root->children[i] != NULL)
		{
			//reduce the current character in source
			alphabet[i]--;
			//add current character 
			char c = intToChar(i);

			//recursively search reaming character of word in trie 
			findWordsWithPrefix(root->children[i], alphabet, str + c, count + 1, listWords);
			
			//increase the current character in the source. avoid word loops!
			alphabet[i]++;
		}
	}
}

std::vector<std::string> getAllWordFromAString(std::string source, TrieNode* root)
{
	// create a 'hash' array that will store all present character and number of them in source
	int hash[ALPHABET_SIZE] = { 0 };

	for (int i = 0; i < source.length(); i++)
	{
		int index = charToInt(source[i]);
		hash[index]++;
	}

	// tempary node 
	TrieNode* pChild = root;

	// string to hold output words 
	std::string str = "";

	std::vector<std::string> returnVal;
	// Traverse all matrix elements. There are only 26 character possible in char array 
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		//start searching for word in dictionary if we found a character which is child of Trie root 
		if (hash[i] != 0 && pChild->children[i])
		{
			//reduce the current character in source
			hash[i]--;
			str = str + static_cast<char>(intToChar(i));
			int count = 0;
			findWordsWithPrefix(pChild->children[i], hash, str, count, returnVal);
			str = "";

			//increase the current character in the source. avoid word loops!
			hash[i]++;
		}
	}

	return returnVal;
}

void buildTrieWords(TrieNode* root, std::vector<std::string> wordList)
{
	for (auto i : wordList)
	{
		insert(root, i);
	}
}
