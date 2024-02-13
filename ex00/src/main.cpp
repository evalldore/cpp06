#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>

static void printChar(int c) {
	std::cout << "Char: ";
	if (c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "Impossible";
	else {
		if (c < 32 || c > 126)
			std::cout << "Non displayable";
		else 
			std::cout << (char)c;
	}
	std::cout << std::endl;
}

static void printInt(long int num) {
	std::cout << "Int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "Impossible";
	else
		std::cout << num;
	std::cout << std::endl;
}

static void printFloat(float num) {
	std::cout << "Float: ";
	if (isnan(num) || isinf(num))
		std::cout << num;
	else {
		if (num == 0.0f)
			std::cout << "0.0";
		else {
			float whole, fractional;
			fractional = std::modf(num, &whole);
			if (fractional != 0.0f)
				std::cout << (whole + fractional);
			else
				std::cout << whole << ".0";
		}
	}
	std::cout << 'f' << std::endl;
}

static void printDouble(double num) {
	std::cout << "Double: ";
	if (isnan(num) || isinf(num))
		std::cout << num;
	else {
		if (num == 0.0f)
			std::cout << "0.0";
		else {
			double whole, fractional;
			fractional = std::modf(num, &whole);
			if (fractional != 0.0f)
				std::cout << (whole + fractional);
			else
				std::cout << whole << ".0";
		}
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	double	num;
	char	*p;

	if (argc < 2 || argc > 2) {
		std::cerr << "Invalid amount of arguments" << std::endl;
		return (1);
	}

	if (strlen(argv[1]) == 1 && !isdigit(argv[1][0]))
		num = static_cast<double>(argv[1][0]);
	else {
		num = strtod(argv[1], &p);
		if (*p)
			num = NAN;
	}

	printChar(static_cast<int>(num));
	printInt(static_cast<long int>(num));
	printFloat(static_cast<float>(num));
	printDouble(num);
	return 0;
}