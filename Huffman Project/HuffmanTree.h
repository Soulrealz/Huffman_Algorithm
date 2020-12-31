#pragma once
#include "Node.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <deque>

class HuffmanTree
{
public:
	HuffmanTree() : root(nullptr) {}
	HuffmanTree(Node* source) : root(source) {}
	~HuffmanTree() { destroy(root); }

	void encode() { encode(root); }
	std::size_t saveTreeInformation() const;

	std::unordered_map<char, std::string> getMap() { return map; }

	// Intentionally not making path a reference
	// Look @ definition
	void buildTree(std::deque<char> path, char symbol);

	std::string restoreFile(std::string& binaryPath);

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

	void destroy(Node* node);
	void print(Node* node) const
	{
		if (!node)
			return;

		print(node->leftNode);
		std::cout << node->data;
		print(node->rightNode);
	}
		
	void encode(Node* node, std::string code = "");
	void saveTreeInformation(Node* node, std::string& string) const;

	void buildTree(Node*& node, std::deque<char>& path, char symbol);

	void restoreFile(Node* node, std::string& binaryPath, std::string& text, std::size_t& index);
};
