#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::Weapon(const Weapon &src) : type(src.type) {}

Weapon &Weapon::operator=(Weapon const &rhs) {
	this->type = rhs.type;
	return *this;
}

Weapon::~Weapon() {
	std::cout << "Weapon [" << this->type << "] destroyed" << std::endl;
}

std::string const &Weapon::getType() {
	return type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
