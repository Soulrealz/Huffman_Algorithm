#pragma once
// direct includes :
// Table.h = Pair.h, string, vector, algorithm
// MinHeap.h = vector, Node.h
// HuffmanTree.h = Node.h

// indirect includes
// Pair.h = iostream
// Node.h = Pair.h
#include "Table.h"
#include "MinHeap.h"
#include "HuffmanTree.h"

class Compression
{
public:
	static void fillTableWithCharacters(std::string& source);
	static void arrangeElements();

	static void fillHeap();
	
	static void constructTree() { tree = HuffmanTree(&unifyHeap()); }

	static void printTable() { table.print(); }
	static void printHeap() { heap.print(); }
private:
	static Table table;
	static MinHeap heap;
	static HuffmanTree tree;

	Compression() = default;
	Compression(const Compression& other) = delete;
	Compression& operator=(const Compression& other) = delete;

	static Node unifyHeap();
};
Table Compression::table;
MinHeap Compression::heap;
HuffmanTree Compression::tree;
