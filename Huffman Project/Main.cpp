#include "HuffmanCompression.h"

Table Compression::table;
MinHeap Compression::heap;
HuffmanTree* Compression::tree;

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
		std::cout << "Enter text to compress: ";
		std::cin >> str;

		Compression::fillTableWithCharacters(str);
	}	
	break;		
	case '2':
		break;
	case '3':
		break;
	default: std::cout << "Exiting...";
		break;
	}
	
	// Demonstrate proper element arrangement
	Compression::arrangeElements();
	Compression::printTable();
	std::cout << "\n\n\n";
	// Demonstrate proper heap filling
	Compression::fillHeap();
	Compression::printHeap();
	std::cout << "\n\n\n";
	// Demonstrate proper tree construction
	Compression::constructTree();
	Compression::printTree();
	std::cout << "\n\n\n";
	// Demonstrate proper Compression
	Compression::compressTree();
	Compression::printCompressedTable();
	return 0;
}



