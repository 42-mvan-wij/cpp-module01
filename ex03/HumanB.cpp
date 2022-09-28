#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(const HumanB &src) : weapon(src.weapon), name(src.name) {}

HumanB &HumanB::operator=(HumanB const &rhs) {
	this->weapon = rhs.weapon;
	this->name = rhs.name;
	return *this;
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon == NULL) {
		std::cout << name << " attacks with their \x1b[1;3mimaginary weapon\x1b[0m" << std::endl;
	}
	else {
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}
