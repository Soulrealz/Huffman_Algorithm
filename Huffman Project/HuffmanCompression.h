#pragma once
// includes :
// Table.h = Pair.h, string, vector, algorithm
// Pair.h = iostream
// MinHeap.h = vector, Node.h
// Node.h = Pair.h
#include "Table.h"
#include "MinHeap.h"

class Huffman
{
public:
	static void fillTableWithCharacters(std::string& source);
	static void arrangeElements();

	static void fillHeap();

	static void printTable() { table.print(); }
	static void printHeap() { heap.print(); }
private:
	static Table table;
	static MinHeap heap;

	Huffman() = default;
	Huffman(const Huffman& other) = delete;
	Huffman& operator=(const Huffman& other) = delete;
};
Table Huffman::table;
MinHeap Huffman::heap;
