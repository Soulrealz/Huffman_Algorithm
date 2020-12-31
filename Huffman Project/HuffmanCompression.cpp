#include "HuffmanCompression.h"

void Compression::fillTableWithCharacters(std::string& source)
{
	// Counting each occuring character
	std::size_t size = source.length();
	for (std::size_t index = 0; index < size; ++index)
	{
		table[(int)source[index]].occuranceCount++;
	}
}
void Compression::arrangeElements()
{
	// Removing each character with an appearance time equaling 0
	table.removeZeroes();
	// Sort by number of occurances
	table.sort();
}

void Compression::fillHeap()
{
	std::size_t size = table.size();
	for (std::size_t i = 0; i < size; i++)
	{
		heap.push(Node(table[i], nullptr, nullptr));
	}
}
void Compression::constructTree()
{
	if (tree)
		delete tree;
	tree = new HuffmanTree(&buildTree());
}
Node& Compression::buildTree()
{
	Node* root;
	while (heap.getSize() != 1)
	{
		// Take two smallest elements and combine their occurance count
		Node* first = new Node(heap[0]);
		Node* second = new Node(heap[1]);

		heap.pop();
		heap.sort();		
		heap.pop();
		heap.sort();

		Node* newEl = new Node(Pair('^', first->data.occuranceCount + second->data.occuranceCount), first, second);
		heap.push(*newEl);
		heap.sort();
	}

	root = &heap[0];

	return *root;
}

std::string Compression::binaryText(std::string & source)
{
	std::unordered_map<char, std::string> map = tree->getMap();
	std::string binary = "";
	std::size_t size = source.size();

	for (std::size_t i = 0; i < size; ++i)
	{
		binary += map[source[i]];
	}

	return binary;
}

void Compression::decompressTree(std::string& treeString)
{
	std::size_t index = 0;
	std::size_t size = treeString.size();
	std::deque<char> path;

	while (index < size)
	{
		if (treeString[index] == '(')
		{
			path.push_back('l');
		}
		else if (treeString[index] == ',')
		{
			path.pop_back();
			path.push_back('r');
		}
		else if (treeString[index] == ')')
		{
			path.pop_back();
		}
		else
		{
			tree->buildTree(path, treeString[index]);
		}

		++index;
	}
}
