#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::Weapon(const Weapon &src) {
	*this = src;
}

Weapon &Weapon::operator=(Weapon const &rhs) {
	this->type = rhs.type;
	return *this;
}

Weapon::~Weapon() {

}

std::string const &Weapon::getType() {
	return type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
