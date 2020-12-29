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
	~Compression()
	{
		delete tree;
	}

	// Functions to fill table and sort them whilst removing 0s
	static void fillTableWithCharacters(std::string& source);
	static void arrangeElements();

	// Function to fill heap
	static void fillHeap();

	// Functions to construct HuffmanTree and compress text
	static void constructTree() { tree = new HuffmanTree(&buildTree()); }
	static void compressTree() { tree->encode(); }

	// Utility Functions to demonstrate progress
	static void printTable() { table.print(); }
	static void printHeap() { heap.print(); }
	static void printTree() { tree->print(); }
	static void printCompressedTable() { tree->printCodeTable(); }
private:
	static Table table;
	static MinHeap heap;
	static HuffmanTree* tree;

	Compression() = default;
	Compression(const Compression& other) = delete;
	Compression& operator=(const Compression& other) = delete;	

	// Actual building function for HuffmanTree
	static Node& buildTree();
};


