#include <iostream>
#include <cstdlib>

static void printChar(char c) {
	std::cout << "Char: ";
	if (c < 32 || c > 126)
	{
		std::cout << "Character is not printable!" << std::endl;
		return ;
	}
	std::cout << c << std::endl;
}

static void printInt(int num) {
	std::cout << "Int: " << num << std::endl;
}

static void printFloat(float num) {
	std::cout << "Float: " << num << 'f' << std::endl;
}

static void printDouble(double num) {
	std::cout << "Double: " << num << std::endl;
}

int main(int argc, char* argv[]) {
	if (argc < 2 || argc > 2) {
		std::cerr << "Invalid amount of arguments" << std::endl;
		return (1);
	}
	double num = strtod(argv[1], NULL);
	printChar(static_cast<char>(num));
	printInt(static_cast<int>(num));
	printFloat(static_cast<float>(num));
	printDouble(num);
	return 0;
}