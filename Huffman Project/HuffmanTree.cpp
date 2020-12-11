#include "HuffmanTree.h"

void HuffmanTree::copy(const Node* source, Node* node)
{
	if (!source)
		return;

	node = new Node(source->data, source->leftNode, source->rightNode);
	copy(source->leftNode, node->leftNode);
	copy(source->rightNode, node->rightNode);
}

void HuffmanTree::destroy(Node* node)
{
	if (!node)
		return;

	destroy(node->leftNode);
	destroy(node->rightNode);

	delete node;
	node = nullptr;
}
