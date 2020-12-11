#pragma once
#include "Pair.h"
#include <vector>
#include <string>
#include <algorithm>

class Table
{
public:
	Table() : container(ASCII) { fillTable(); }
	Table(const Table& other) : container(other.container) {}

	Table& operator=(const Table& other);
	Pair& operator[](const int& index);

	void fillTable();
	void removeZeroes();

	void print() const;
	void sort();
private:
	std::vector<Pair> container;
	// Supporting only standard ASCII
	const std::size_t ASCII = 127;
};
