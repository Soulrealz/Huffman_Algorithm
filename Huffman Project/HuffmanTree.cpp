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
