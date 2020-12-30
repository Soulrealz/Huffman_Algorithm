#include "HuffmanTree.h"

void HuffmanTree::destroy(Node * node)
{
	if (!node)
		return;

	destroy(node->leftNode);
	destroy(node->rightNode);
	delete node;
	node = nullptr;
}

void HuffmanTree::encode(Node* node, std::string code)
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

std::size_t HuffmanTree::saveTreeInformation() const
{
	std::string codedTree = "";
	saveTreeInformation(root, codedTree);
	std::ofstream outfile("treeInformation.txt", std::ios::out, std::ios::trunc);
	outfile << codedTree;
	return codedTree.size();
}
void HuffmanTree::saveTreeInformation(Node* node, std::string& string) const
{
	if (node == nullptr)
		return;
	
	string += node->data.symbol;
	string += "(";
	if (!node->leftNode->leftNode && !node->leftNode->rightNode)
	{
		string += node->leftNode->data.symbol;
	}
	else saveTreeInformation(node->leftNode, string);

	string += ",";
	if (!node->rightNode->leftNode && !node->rightNode->rightNode)
	{
		string += node->rightNode->data.symbol;
	}
	else saveTreeInformation(node->rightNode, string);
	string += ")";
}
