#pragma once
#include "Pair.h"
#include <vector>
#include <string>

class Table
{
public:
	Table() : container(ASCII) {}
	Table(const Table& other) : container(other.container) {}

	Table& operator=(const Table& other)
	{
		if (this != &other)
		{
			container = other.container;
		}

		return *this;
	}

	void fillTable()
	{
		for (std::size_t index = 0; index < ASCII; ++index)
		{
			container[index].symbol = (char)index;
			container[index].numberOfOccurances = 0;
		}
	}
private:
	std::vector<Pair> container;
	const std::size_t ASCII = 127;
};
