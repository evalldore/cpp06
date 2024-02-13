#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Classes.hpp"

Base*	generate(void) {
	unsigned int r = rand() % 3;
	switch (r) {
		case (0):
			return new A();
		case (1):
			return new B();
		case (2):
			return new C();
		default:
			std::cout << "WTF HAPPENED" << std::endl;
			break;
	}
	return (NULL);
}

void	identify(Base* p) {
	std::cout << "Is a ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "invalid";
	std::cout << " type" << std::endl;
}

void	identify(Base& p) {
	std::cout << "Is a ";
	try {
		if (dynamic_cast<A*>(&p))
			std::cout << "A";
		else if (dynamic_cast<B*>(&p))
			std::cout << "B";
		else if (dynamic_cast<C*>(&p))
			std::cout << "C";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << " type" << std::endl;
}

int	main(void) {
	srand(time(NULL));
	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();

	std::cout << "Identify pointers" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(NULL);

	std::cout << "Identify references" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;
}