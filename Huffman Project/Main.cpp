#include <iostream>
#include <string>


int main()
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
