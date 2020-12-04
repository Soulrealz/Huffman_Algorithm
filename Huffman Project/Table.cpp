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
		container[index].symbol = (char)index;
		container[index].numberOfOccurances = 0;
	}
}