#pragma once
#include <iostream>

struct Pair
{
	char symbol;
	int numberOfOccurances;

	Pair(char _symbol = '!', int _number = -1) : symbol(_symbol), numberOfOccurances(_number) {}
	Pair(const Pair& other) : symbol(other.symbol), numberOfOccurances(other.numberOfOccurances) {}

	Pair& operator=(const Pair& other) 
	{
		if (this != &other)
		{
			symbol = other.symbol;
			numberOfOccurances = other.numberOfOccurances;
		}

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Pair& element)
	{
		out << element.symbol << " " << element.numberOfOccurances << "\n";
		return out;
	}

	bool operator>(const Pair& other)
	{
		return numberOfOccurances > other.numberOfOccurances;
	}
};
