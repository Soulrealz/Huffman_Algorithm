#include "Table.h"

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		container = other.container;
	}

	return *this;
}

Pair& Table::operator[](const int & index)
{
	return container[index];
}

void Table::fillTable()
{
	for (std::size_t index = 0; index < ASCII; ++index)
	{
		container[index].symbol = (char)index;
		container[index].numberOfOccurances = 0;
	}
}

void Table::removeZeroes()
{
	int counter = 0;
	std::size_t size = container.size();
	for (std::size_t index = 0; index < size; ++index)
	{
		if (container[index].numberOfOccurances != 0)
		{
			counter++;
		}
	}

	std::vector<Pair> tmp(counter);
	counter = 0;
	for (std::size_t index = 0; index < size; ++index)
	{
		if (container[index].numberOfOccurances != 0)
		{
			tmp[counter++] = container[index];
		}
	}

	container = tmp;
}
