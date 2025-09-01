#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int	main() {
	Data		data;

	if (&data == Serializer::deserialize(Serializer::serialize(&data))) {
		std::cout << data.getName() << std::endl;
	} else {
		std::cout << "Serialization failed." << std::endl;
	}
}
