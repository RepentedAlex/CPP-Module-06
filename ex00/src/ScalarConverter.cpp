#include "ScalarConverter.hpp"

#include <stdlib.h>

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>

static bool	isChar(const std::string& s);
static bool	isInt(const std::string& s);
static void	printChar(double value);
static void	printDouble(double value);
static void	printFloat(double value);
static void	printInt(double value);

static std::string	pseudoLiterals[] = {"-inf", "+inf", "nan"};

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& original) {
	*this = original;
}

ScalarConverter::~ScalarConverter() {
}

static bool	isChar(const std::string& s) {
	if (s.length() == 1) {
		return (true);
	}
	return (false);
}

static bool	isInt(const std::string& s) {
	char	*ptr;
	long	num;
	size_t	i = 0;
	int		min_int = std::numeric_limits<int>::min();
	int		max_int = std::numeric_limits<int>::max();

	if (s.empty()) {
		return (false);
	}
	if (s[0] == '+' || s[0] == '-') {
		i++;
		if (s.length() == i) {
			return (false);
		}
	}

	for (; i < s.length() ; i++) {
		if (!std::isdigit(s[i])) {
			return (false);
		}
	}

	num = std::strtol(s.c_str(), &ptr, 10);
	if (*ptr != '\0') {
		return (false);
	}
	if (num < min_int || num > max_int) {
		return (false);
	}
	return (true);
}

static void	printChar(double value) {
	std::cout << "char: ";
	if ((value >= 0 && value <= 32) || value == 127) { //< Is the character printable ?
		std::cout << "non displayable" << std::endl;
	} else if (value < 0 || value > 127) { //< Is the character outside of the ASCII table ?
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<char>(value) << std::endl;
	}
}

static void	printDouble(double value) {
	double	min_double = std::numeric_limits<double>::min();
	double	max_double = std::numeric_limits<double>::max();

	std::cout << "double: ";

	if (value < min_double || value > max_double) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
}

static void	printFloat(double value) {
	float	min_float = std::numeric_limits<float>::min();
	float	max_float = std::numeric_limits<float>::max();

	std::cout << "float: ";

	if (value < min_float || value > max_float) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

static void	printInt(double value) {
	int	min_int = std::numeric_limits<int>::min();
	int	max_int = std::numeric_limits<int>::max();

	std::cout << "int: ";

	if (value < min_int || value > max_int) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& literal) {
	if (isChar(literal)) {
		char	c = literal[0];
		printChar(static_cast<double>(c));
		printInt(static_cast<double>(c));
		printFloat(static_cast<double>(c));
		printDouble(static_cast<double>(c));
	} else if (isInt(literal)) {
		int	i = std::atoi(literal.c_str());
		printChar(static_cast<double>(i));
		printInt(static_cast<double>(i));
		printFloat(static_cast<double>(i));
		printDouble(static_cast<double>(i));
	}
	else {
		std::cout << "Error: Invalid literal" << std::endl;
	}
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& original) {
	(void)original;
	return (*this);
}
