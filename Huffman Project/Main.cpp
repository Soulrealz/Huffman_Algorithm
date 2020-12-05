// includes :
// Table.h = Pair.h, string, vector
// Pair.h = iostream
#include "Table.h"

void countChars(std::string& source)
{
	// Creating table and filling it with zeroes up to the 126th ascii inclusive
	Table table;
	table.fillTable();
	
	// Counting each occuring character
	std::size_t size = source.length();
	for (std::size_t index = 0; index < size; ++index)
	{
		table[(int)source[index]].numberOfOccurances++;
	}

	// Removing each character with an appearance time equaling 0
	table.removeZeroes();
}


int main(int argc, char* argv[])
{
	char symbol;
	do
	{
		std::cout << "Choose program:\n";
		std::cout << "1 - Insert text from console\n";
		//std::cout << "2) Input text from file\n";
		//std::cout << "3) Decode from file with encoded data and saved tree\n";
		std::cout << "4 - Exit\n";

		std::cout << "\nEnter option: ";
		std::cin >> symbol;
	} while (symbol != '1' && symbol != '2' && symbol != '3' && symbol != '4');

	std::cout << "\n\n";

	switch (symbol)
	{
	case '1':
	{
		std::string str = "";
		std::cout << "Enter text to compress:";
		std::cin >> str;
		countChars(str);
	}	
	break;		
	case '2':
		break;
	case '3':
		break;
	default: std::cout << "Exiting...";
		break;
	}
	

	return 0;
}



