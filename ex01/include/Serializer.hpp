/// @file Serializer.hpp
/// @brief

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include "Data.hpp"

/// @class Serializer
class	Serializer {
public:
	/// @brief
	/// @param raw
	/// @return
	static Data*		deserialize(uintptr_t raw);

	/// @brief
	/// @param ptr
	/// @return
	static uintptr_t	serialize(Data* ptr);

private:
	Serializer();

	Serializer(const Serializer& original);

	~Serializer();

	Serializer&	operator=(const Serializer& original);
};

#endif // !SERIALIZER_HPP
