#pragma once
#include "Node.h"
#include <unordered_map>
#include <string>

class HuffmanTree
{
public:
	HuffmanTree() : root(nullptr) {}
	HuffmanTree(Node* source) : root(source) {}
	~HuffmanTree() { destroy(root); }

	void encode()
	{
		encode(root);
	}

	// Print pre compressed tree
	void print() const
	{
		print(root);
	}
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
	void encode(Node* node, std::string code = "")
	{
		if (!node)
			return;
		// If there is no left&&right that means element is leaf
		if (!node->leftNode && !node->rightNode)
		{
			map[node->data.symbol] = code;
			return;
		}

		if (node->leftNode)
		{
			code += '0';
			encode(node->leftNode, code);
		}
		if (node->rightNode)
		{
			//popping 1 element to remove the last added '0'
			code.pop_back();
			code += '1';
			encode(node->rightNode, code);
		}
	}
};
