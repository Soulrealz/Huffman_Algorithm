#pragma once
#include "Pair.h"
#include <vector>

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

private:
	std::vector<Pair> container;
	const std::size_t ASCII = 256;
};
