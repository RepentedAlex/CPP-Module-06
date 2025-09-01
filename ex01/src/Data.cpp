#include "Data.hpp"

Data::Data() : name_("Lockne") {
}

Data::Data(const std::string& name) : name_(name) {
}

Data::Data(const Data& original) {
	*this = original;
}

Data::~Data() {
}

const std::string&	Data::getName() const {
	return (this->name_);
}

Data&	Data::operator=(const Data& original) {
	if (this != &original) {
		this->name_ = original.name_;
	}
	return (*this);
}
