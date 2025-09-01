/// @file Data.hpp
/// @brief

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

/// @class Data
class	Data {
public:
	Data();

	Data(const std::string& name);

	Data(const Data& original);

	~Data();

	const std::string&	getName() const;

	Data&				operator=(const Data& original);

private:
	std::string	name_;

};

#endif // !DATA_HPP
