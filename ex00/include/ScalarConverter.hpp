#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/// @class ScalarConverter
/// @brief Class implementing a static function to convert C++ literals interchangeably.
class	ScalarConverter {
public:
	/// @brief Converts a C++ literal to char, int, float and double.
	/// @param string The C++ literal passed as a string.
	static void	convert(const std::string& string);

private:
	/// @brief Default constructor.
	ScalarConverter();

	/// @brief Copy constructor.
	/// @param original The ScalarConverter we want to copy from.
	ScalarConverter(const ScalarConverter& original);

	/// @brief Destructor.
	~ScalarConverter();

	/// @brief Assignment operator overload.
	/// @param original The ScalarConverter instance we want to assign from
	/// @return A reference to a ScalarConverter instance.
	ScalarConverter&	operator=(const ScalarConverter& original);
};

#endif // !SCALARCONVERTER_HPP
