// includes :
// Table.h = Pair.h, string, vector, algorithm
// Pair.h = iostream
// MinHeap.h = vector, Node.h
// Node.h = Pair.h
#include "Table.h"
#include "MinHeap.h"

class Huffman
{
public:
	
	static void fillTableWithCharacters(std::string& source)
	{
		// Counting each occuring character
		std::size_t size = source.length();
		for (std::size_t index = 0; index < size; ++index)
		{
			table[(int)source[index]].numberOfOccurances++;
		}		
	}
	static void arrangeElements()
	{
		// Removing each character with an appearance time equaling 0
		table.removeZeroes();
		// Sort by number of occurances
		table.sort();
	}

	static void fillHeap()
	{
		std::size_t size = table.size();
		for (std::size_t i = 0; i < size; i++)
		{
			heap.push(Node(table[i], nullptr, nullptr));
		}
	}

	static void printTable()
	{		
		table.print();
	}
	static void printHeap()
	{
		heap.print();
	}
private:
	 static Table table;
	 static MinHeap heap;

	 Huffman() = default;
	 Huffman(const Huffman& other) = delete;
	 Huffman& operator=(const Huffman& other) = delete;
};
Table Huffman::table;
MinHeap Huffman::heap;

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

		Huffman::fillTableWithCharacters(str);
	}	
	break;		
	case '2':

		break;
	case '3':
		break;
	default: std::cout << "Exiting...";
		break;
	}
		
	Huffman::arrangeElements();
	Huffman::printTable();
	std::cout << "\n\n\n";
	Huffman::fillHeap();
	Huffman::printHeap();

	return 0;
}



