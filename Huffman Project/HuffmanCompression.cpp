#include "HuffmanCompression.h"

void Compression::fillTableWithCharacters(std::string & source)
{
	// Counting each occuring character
	std::size_t size = source.length();
	for (std::size_t index = 0; index < size; ++index)
	{
		table[(int)source[index]].numberOfOccurances++;
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

Node Compression::unifyHeap()
{
	Node root;
	while (heap.getSize() != 1)
	{
		Node first = heap.top();
		heap.pop();
		Node second = heap.top();
		heap.pop();

		Node newEl = Node(Pair('!', first.data.numberOfOccurances + second.data.numberOfOccurances), &first, &second);
		heap.push(newEl);
	}
	
	root = heap.top();
	heap.pop();

	return root;
}
