#pragma once
#include <iostream>

// Struct to track each symbol and its occurances
struct Pair
{
	char symbol;
	unsigned int occuranceCount;

	Pair(char _symbol = '^', unsigned int _number = 0) : symbol(_symbol), occuranceCount(_number) {}
	Pair(const Pair& other) : symbol(other.symbol), occuranceCount(other.occuranceCount) {}

	Pair& operator=(const Pair& other) 
	{
		if (this != &other)
		{
			symbol = other.symbol;
			occuranceCount = other.occuranceCount;
		}

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Pair& element)
	{
		out << element.symbol << " " << element.occuranceCount << "\n";
		return out;
	}
};
