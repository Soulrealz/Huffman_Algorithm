#pragma once
#include "Node.h"

class HuffmanTree
{
public:
	HuffmanTree() : root(nullptr) {}
	HuffmanTree(Node* source) { copy(source, root); }
	HuffmanTree(const HuffmanTree& source) { copy(source.root, root); }
	~HuffmanTree() { destroy(root); }

private:
	Node* root;
	void copy(const Node* source, Node* node);
	void destroy(Node* node);
};
