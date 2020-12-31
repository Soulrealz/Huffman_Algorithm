#include <fstream>
#include "HuffmanCompression.h"

struct FileManagement
{
	static void readFile(char* argv[], std::string& str, const char* filename)
	{
		std::ifstream infile(filename, std::ios::in | std::ios::beg | std::ios::ate);
		if (!infile)
			throw std::invalid_argument("Cannot open file");
		std::size_t size = infile.tellg();

		char* chars = new char[size + 1];

		infile.seekg(0, std::ios::beg);
		infile.read(chars, size);
		chars[size] = '\0';

		str.clear();
		str.append(chars);
		std::cout << "Your input is:\n" << str << "\n";
		delete[] chars;
	}
	static bool setFile(std::string& filename, std::string condition)
	{
		// should be +1 but we do -3 to offset "-i "
		// so 1 - 3 => -2
		char* chars = new char[filename.size() - 2];
		if (filename != "\n" && filename.size() > 3 && filename.substr(0, 3) == condition)
		{
			// macros inserted to turn off strncpy warnings
			//_CRT_SECURE_NO_DEPRECATE 
			//_CRT_NONSTDC_NO_DEPRECATE
			filename = filename.substr(3, filename.size());

			strncpy(chars, filename.c_str(), filename.size());
			chars[filename.size()] = '\0';

			filename = chars;
			return true;
		}
		delete[] chars;
		return false;
	}
	static std::string fileName()
	{
		std::string filename = "";
		std::getline(std::cin, filename);
		return filename;
	}
};


void compression(char* argv[], std::string& str)
{
	// Fill Table
	Compression::fillTableWithCharacters(str);

	// Demonstrate proper element arrangement
	Compression::arrangeElements();
	//Compression::printTable();
	//std::cout << "\n\n\n";

	// Demonstrate proper heap filling
	Compression::fillHeap();
	//Compression::printHeap();
	//std::cout << "\n\n\n";

	// Demonstrate proper tree construction
	Compression::constructTree();
	//Compression::printTree();
	//std::cout << "\n\n\n";

	// Demonstrate proper Compression
	Compression::compressTree();
	//Compression::printCompressedTable();
	//std::cout << "\n\n\n";

	// Showing only the compression
	//std::cout << Compression::binaryText(str);
	std::string binary = Compression::binaryText(str);
	std::ofstream outfile(argv[2], std::ios::out, std::ios::trunc);
	outfile << binary;

	std::cout << "\n\nThe compression has saved " << str.size() * 8 - binary.size() << " bits.\n";
	std::cout << str.size() * 8 - binary.size() - Compression::decompressInformation() << " bits if we count bits for tree.";
}

char mainLoop()
{
	char symbol;
	do
	{
		std::cout << "Choose program:\n";
		std::cout << "1 - Insert text from console\n";
		std::cout << "2/c - Input text from file\n";
		std::cout << "3/d - Decode from file with encoded data and saved tree\n";
		std::cout << "4 - Exit\n";

		std::cout << "\nEnter option: ";
		std::cin >> symbol;
	} while (symbol != '1' && symbol != '2' && symbol != '3' && symbol != '4' && symbol != 'c' && symbol != 'd');

	return symbol;
}

void caseOne(char* argv[], std::string& str);
void caseTwo(char* argv[], std::string& str);
void caseThree(char* argv[], std::string& str);

Table Compression::table;
TreeVector Compression::heap;
HuffmanTree* Compression::tree = new HuffmanTree();
int main(int argc, char* argv[])
{	
	std::string str = "";
	switch (mainLoop())
	{
	case '1':
	{		
		caseOne(argv, str);
	}
	break;
	case '2':
	case 'c':
	{
		caseTwo(argv, str);
	}
	break;
	case '3':
	case 'd':
	{
		caseThree(argv, str);
	}
	break;
	default: std::cout << "Exiting...";
		break;
	}
	
	
	return 0;
}

void caseOne(char* argv[], std::string& str)
{
	{
		std::cout << "Enter text to compress: ";
		std::cin.ignore();
		std::getline(std::cin, str);

		Compression::fillTableWithCharacters(str);
		compression(argv, str);
	}
}
void caseTwo(char* argv[], std::string& str)
{
	std::cout << "-i <name_of_input_file>, press Enter if you want to use default Input.txt\n";
	std::cin.ignore();
	std::string inputFileName = FileManagement::fileName();
	std::cout << "-o <name_of_output_file, press Enter if you want to use default Output.txt\n";
	std::string outputFileName = FileManagement::fileName();

	char* chars = nullptr;
	try
	{
		if (FileManagement::setFile(inputFileName, std::string("-i ")))
		{
			chars = new char[inputFileName.size()];
			argv[1] = chars;
		}
		FileManagement::readFile(argv, str, argv[1]);
		delete[] chars;

		chars = nullptr;
		if (FileManagement::setFile(outputFileName, std::string("-o ")))
		{
			chars = new char[outputFileName.size()];
			argv[2] = chars;
		}
	}
	catch (...)
	{
		FileManagement::readFile(argv, str, argv[1]);
	}

	compression(argv, str);
	delete[] chars;
}
void caseThree(char* argv[], std::string& str)
{
	std::cout << "Reading compressed version from TreeInformation.txt\n";
	FileManagement::readFile(argv, str, argv[3]);
	Compression::decompressTree(str);

	std::cout << "\nReading compressed version from Compressed.txt\n";
	FileManagement::readFile(argv, str, argv[4]);
	std::string recreatedText = Compression::decipherTree(str);

	std::cout << "\nOriginal Text:\n" << recreatedText;
	std::ofstream original("Original.txt", std::ios::out, std::ios::trunc);
	original << recreatedText;
}