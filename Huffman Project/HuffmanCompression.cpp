#include "HuffmanCompression.h"

void Huffman::fillTableWithCharacters(std::string & source)
{
	// Counting each occuring character
	std::size_t size = source.length();
	for (std::size_t index = 0; index < size; ++index)
	{
		table[(int)source[index]].numberOfOccurances++;
	}
}

void Huffman::arrangeElements()
{
	// Removing each character with an appearance time equaling 0
	table.removeZeroes();
	// Sort by number of occurances
	table.sort();
}

void Huffman::fillHeap()
{
	std::size_t size = table.size();
	for (std::size_t i = 0; i < size; i++)
	{
		heap.push(Node(table[i], nullptr, nullptr));
	}
}
