/// @file ScalarConverter.hpp
/// @brief

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/// @class ScalarConverter
/// @brief
class	ScalarConverter {
public:
	/// @brief
	/// @param string
	static void	convert(const std::string& string);

private:
	/// @brief Default constructor.
	ScalarConverter();

	/// @brief Copy constructor.
	/// @param original
	ScalarConverter(const ScalarConverter& original);

	/// @brief Destructor.
	~ScalarConverter();

	/// @brief Assignment operator overload.
	/// @param original
	/// @return A reference to a ScalarConverter instance.
	ScalarConverter&	operator=(const ScalarConverter& original);
};

#endif // !SCALARCONVERTER_HPP
