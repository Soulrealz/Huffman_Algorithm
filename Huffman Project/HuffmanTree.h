#pragma once
#include "Node.h"
#include <unordered_map>
#include <string>
#include <fstream>

class HuffmanTree
{
public:
	HuffmanTree() : root(nullptr) {}
	HuffmanTree(Node* source) : root(source) {}
	~HuffmanTree() { destroy(root); }

	void encode() { encode(root); }

	std::unordered_map<char, std::string>& getMap() { return map; }
	std::size_t saveTreeInformation() const;

	// Print pre compressed tree
	void print() const { print(root); }
	// Print each symbol with its code
	void printCodeTable() const
	{
		for (auto it : map)
		{
			std::cout << it.first << " " << it.second << "\n";
		}
	}
private:
	Node* root;
	std::unordered_map<char, std::string> map;

	// Free used memory
	void destroy(Node* node);
	void print(Node* node) const
	{
		if (!node)
			return;

		print(node->leftNode);
		std::cout << node->data;
		print(node->rightNode);
	}
		

	//Run in release to force string optimisation below <14 characters.
	void encode(Node* node, std::string code = "");
	void saveTreeInformation(Node* node, std::string& string) const;
};
