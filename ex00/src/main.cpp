#include "ScalarConverter.hpp"

#include <iostream>

#define BLUE	"\033[1;95m"
#define CYAN	"\033[36m"
#define YELLOW	"\033[4;33m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << std::endl << BLUE "=== " x " ===" RESET << std::endl << std::endl; \
} while (0)


#define PRINT_SUBSECTION(x) \
do { \
	std::cout << CYAN "~ " x " ~" RESET << std::endl; \
} while (0)

#define PRINT_TEST(x) \
do { \
	std::cout << YELLOW x RESET << std::endl; \
} while (0)

#define PRINT(x) do { std::cout << x << std::endl; } while (0)

int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <argument>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
