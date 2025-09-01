#include "ScalarConverter.hpp"

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

static bool	isChar(const std::string& s);
static bool	isDouble(const std::string& s);
static bool	isFloat(const std::string& s);
static bool	isInt(const std::string& s);
static bool	isPseudoLiteral(const std::string& s);
static void	printChar(double value);
static void	printDouble(double value);
static void	printFloat(double value);
static void	printInt(double value);

static std::string	pseudoLiterals[] = {"-inf", "+inf", "-inff", "+inff", "nan", "nanf"};

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& original) {
	*this = original;
}

ScalarConverter::~ScalarConverter() {
}

static bool	isChar(const std::string& s) {
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'') {
		return (true);
	}
	return (false);
}

static bool	isDouble(const std::string& s) {
	char*	ptr;
	double	num;

	(void)num;
	if (s.empty()) {
		return (false);
	}
	errno = 0;
	num = std::strtod(s.c_str(), &ptr);
	if (*ptr != '\0' || errno == ERANGE) {
		return (false);
	}
	return (true);
}

static bool	isFloat(const std::string& s) {
	std::string	floatStr = s.substr(0, s.length() - 1);
	char*		ptr;

	if (s.empty()) {
		return (false);
	}
	if (s[s.length() - 1] != 'f' && s[s.length() - 1] != 'F') {
		return (false);
	}
	errno = 0;
	std::strtof(floatStr.c_str(), &ptr);
	if (*ptr != '\0' || errno == ERANGE) {
		return (false);
	}
	return (true);
}

static bool	isInt(const std::string& s) {
	char*	ptr;
	size_t	i = 0;

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
	errno = 0;
	std::strtol(s.c_str(), &ptr, 10);
	if (*ptr != '\0' || errno == ERANGE) {
		return (false);
	}
	return (true);
}

static bool	isPseudoLiteral(const std::string& s) {
	for (size_t i = 0 ; i < 6 ; i++) {
		if (s == pseudoLiterals[i]) {
			return (true);
		}
	}
	return (false);
}

static void	printChar(double value) {
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0  || value > 127) {
		std::cout << "impossible" << std::endl;
	} else if (value < 32 || value == 127) {
		std::cout << "non displayable" << std::endl;
	} else {
		std::cout << static_cast<char>(value) << std::endl;
	}
}

static void	printDouble(double value) {
	std::cout << "double: ";

	if (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value)) {
		if (value > 0) {
			std::cout << "+inf" << std::endl;
		} else {
			std::cout << "-inf" << std::endl;
		}
	} else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
}

static void	printFloat(double value) {
	std::cout << "float: ";

	if (std::isnan(value)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(value)) {
		if (value > 0) {
			std::cout << "+inff" << std::endl;
		} else {
			std::cout << "-inff" << std::endl;
		}
	} else {
		errno = 0;
		float	f = static_cast<float>(value);
		if (errno == ERANGE) {
			std::cout << "impossible" << std::endl;
		} else {
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
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
	if (isPseudoLiteral(literal)) {
		if (literal == "nan" || literal == "nanf") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (literal == "+inf" || literal == "+inff") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else if (literal == "-inf" || literal == "-inff") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	} else if (isChar(literal)) {
		char	c = literal[1];
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
	} else if (isFloat(literal)) {
		float	f = std::atof(literal.c_str());
		printChar(static_cast<double>(f));
		printInt(static_cast<double>(f));
		printFloat(static_cast<double>(f));
		printDouble(static_cast<double>(f));
	} else if (isDouble(literal)) {
		double	d = std::strtod(literal.c_str(), NULL);
		printChar(static_cast<double>(d));
		printInt(static_cast<double>(d));
		printFloat(static_cast<double>(d));
		printDouble(static_cast<double>(d));
	}
	else {
		std::cout << "Error: Invalid literal" << std::endl;
	}
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& original) {
	(void)original;
	return (*this);
}
