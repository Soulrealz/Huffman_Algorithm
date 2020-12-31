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

// Path is not reference to preserve depth reached
void HuffmanTree::buildTree(std::deque<char> path, char symbol)
{
	if (!root)
		root = new Node(symbol);
	else
	{
		if (path.front() == 'l')
			buildTree(root->leftNode, path, symbol);
		else buildTree(root->rightNode, path, symbol);
	}
}
std::string HuffmanTree::restoreFile(std::string& binaryPath)
{
	std::string text = "";
	std::size_t index = 0;
	std::size_t size = binaryPath.size();
	while (index < size)
	{
		restoreFile(root, binaryPath, text, index);
	}
	return text;
}
// Path is reference here because we need to reach from root to node
void HuffmanTree::buildTree(Node*& node, std::deque<char>& path, char symbol)
{
	if (!node)
		node = new Node(symbol);
	else
	{
		// If path were a reference in upper function
		// this would pop progress and eventually get out of bounds exception in decompress function
		path.pop_front();
		if (path.front() == 'l')
			buildTree(node->leftNode, path, symbol);
		else buildTree(node->rightNode, path, symbol);
	}
}

void HuffmanTree::restoreFile(Node* node, std::string& binaryPath, std::string& text, std::size_t& index)
{
	if (!node->leftNode && !node->rightNode)
		text += node->data.symbol;
	else if (binaryPath[index] == '1')
		restoreFile(node->rightNode, binaryPath, text, ++index);
	else restoreFile(node->leftNode, binaryPath, text, ++index);
}
