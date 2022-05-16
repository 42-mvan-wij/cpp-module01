#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}

HumanA::HumanA(const HumanA &src) {
	*this = src;
}

HumanA &HumanA::operator=(HumanA const &rhs) {
	this->weapon = rhs.weapon;
	return *this;
}

HumanA::~HumanA() {

}

void HumanA::attack() {
	std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}
