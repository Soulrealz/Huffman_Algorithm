#include "Table.h"

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		container = other.container;
	}

	return *this;
}

void Table::fillTable()
{
	for (std::size_t index = 0; index < ASCII; ++index)
	{
		container.emplace_back((char)index, 0);
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

void Table::print() const
{
	std::size_t size = container.size();
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << container[i];
	}
}

void Table::sort()
{	
	std::sort(container.begin(), container.end(), [](Pair a, Pair b) { return a.numberOfOccurances < b.numberOfOccurances; });
}
