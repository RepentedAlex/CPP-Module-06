#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "stdint.h"

#include "Data.hpp"

/// @class Serializer
class	Serializer {
public:
	/// @brief
	/// @param raw The pointer address we want to deserialise.
	/// @return A pointer to a Data instance.
	static Data*		deserialize(uintptr_t raw);

	/// @brief
	/// @param ptr Pointer to the Data instance we want to serialise.
	/// @return
	static uintptr_t	serialize(Data* ptr);

private:
	Serializer();

	Serializer(const Serializer& original);

	~Serializer();

	Serializer&	operator=(const Serializer& original);
};

#endif // !SERIALIZER_HPP
