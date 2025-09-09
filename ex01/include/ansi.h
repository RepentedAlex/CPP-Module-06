#ifndef ANSI_H
#define ANSI_H

#include <iostream>

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define BLUE	"\033[1;95m"
#define CYAN	"\033[36m"
#define YELLOW	"\033[4;33m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << std::endl << BLUE "=== " x " ===" RESET << std::endl; \
} while (0)


#define PRINT_SUBSECTION(x) \
do { \
	std::cout << std::endl << CYAN "~ " x " ~" RESET << std::endl; \
} while (0)

#define PRINT_TEST(x) \
do { \
	std::cout << YELLOW x RESET << std::endl; \
} while (0)

#endif // !ANSI_H
