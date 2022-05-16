#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = nullptr;
}

HumanB::HumanB(const HumanB &src) {
	*this = src;
}

HumanB &HumanB::operator=(HumanB const &rhs) {
	this->weapon = rhs.weapon;
	return *this;
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon == nullptr) {
		std::cout << name << " attacks with their nothing" << std::endl;
	}
	else {
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}
