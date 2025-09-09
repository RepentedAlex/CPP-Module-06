#include <cstdlib>

#include "ansi.h"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int		seed = std::rand() % 3;
	switch (seed) {
		case 0:
			std::cout << "Generated A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generated C" << std::endl;
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "It's an A!" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "It's a B!" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "It's a C!" << std::endl;
	}
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "It's an A!" << std::endl;
	} catch (const std::exception& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "It's a B!" << std::endl;
		} catch (const std::exception& e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "It's a C!" << std::endl;
			} catch (const std::exception& e) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int	main(void) {
	std::srand(clock());

	PRINT_SECTION("Testing type identification");
	{
		Base*	array[5];
		PRINT_SUBSECTION("First generation");
		{
			PRINT_TEST("Generating");
			array[0] = generate();
			Base&	a0 = *array[0];
			PRINT_TEST("Identifying");
			identify(array[0]);
			PRINT_TEST("Identifying through reference");
			identify(a0);
		}
		PRINT_SUBSECTION("Second generation");
		{
			PRINT_TEST("Generating");
			array[1] = generate();
			Base&	a1 = *array[1];
			PRINT_TEST("Identifying");
			identify(array[1]);
			PRINT_TEST("Identifying through reference");
			identify(a1);
		}
		PRINT_SUBSECTION("Thrid generation");
		{
			PRINT_TEST("Generating");
			array[2] = generate();
			Base&	a2 = *array[2];
			PRINT_TEST("Identifying");
			identify(array[2]);
			PRINT_TEST("Identifying through reference");
			identify(a2);
		}
		PRINT_SUBSECTION("Fourth generation");
		{
			PRINT_TEST("Generating");
			array[3] = generate();
			Base&	a3 = *array[3];
			PRINT_TEST("Identifying");
			identify(array[3]);
			PRINT_TEST("Identifying through reference");
			identify(a3);
		}
		PRINT_SUBSECTION("Fifth generation");
		{
			PRINT_TEST("Generating");
			array[4] = generate();
			Base&	a4 = *array[4];
			PRINT_TEST("Identifying");
			identify(array[4]);
			PRINT_TEST("Identifying through reference");
			identify(a4);
		}
		for (int i = 0; i < 5; i++) {
			delete array[i];
		}
	}
	return (0);
}
