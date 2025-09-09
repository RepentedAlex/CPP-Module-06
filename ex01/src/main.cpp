#include "ansi.h"
#include "Data.hpp"
#include "Serializer.hpp"

int	main() {
	PRINT_SECTION("Testing serialisation and deserialisation");
	{
		Data		valid;
		Data*		invalid = NULL;
		Data*		tmp;
		uintptr_t	invalid_p;
		uintptr_t	valid_p;
		PRINT_SUBSECTION("Serialising existing instance");
		{
			std::cout << "Before serialisation" << std::endl <<
				valid.getName() << " (address: " << &valid << ')' << std::endl;
			valid_p = Serializer::serialize(&valid);
			std::cout << "After serialisation" << std::endl <<
				"Value returned: " << valid_p << std::endl;
		}
		PRINT_SUBSECTION("Deserialising a valid value");
		{
			std::cout << "Value to deserialise: " << valid_p << std::endl;
			tmp = Serializer::deserialize(valid_p);
			std::cout << "After deserialisation" << std::endl <<
				tmp->getName() << " (address: " << tmp << ')' << std::endl;
			PRINT_TEST("Does initial data address and deserialized address match ?");
			{
				if (&valid == tmp)
					std::cout << GREEN "YES" RESET << std::endl;
				else
					std::cout << RED "NO" RESET << std::endl;
			}
		}
		PRINT_SUBSECTION("Serialising null address");
		{
			std::cout << "Before serialisation" << std::endl <<
				"No name" << " (address: " << invalid << ')' << std::endl;
			invalid_p = Serializer::serialize(invalid);
			std::cout << "After serialisation" << std::endl <<
				"Value returned: " << invalid_p << std::endl;
		}
		PRINT_SUBSECTION("Deserialising a null value");
		{
			std::cout << "Value to deserialise: " << invalid_p << std::endl;
			tmp = Serializer::deserialize(invalid_p);
			std::cout << "After deserialisation" << std::endl <<
				"No name" << " (address: " << tmp << ')' << std::endl;
			PRINT_TEST("Does initial data address and deserialized address match ?");
			{
				if (invalid == tmp)
					std::cout << GREEN "YES" RESET << std::endl;
				else
					std::cout << RED "NO" RESET << std::endl;
			}
		}
	}
	return (0);
}
