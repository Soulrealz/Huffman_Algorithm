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
	Pair& operator[](const int& index) { return container[index]; }

	void fillTable();
	void removeZeroes();

	void print() const;
	void sort();
	std::size_t size() const { return container.size(); }
private:
	std::vector<Pair> container;
	// Supporting only standard ASCII
	const std::size_t ASCII = 256;
};
