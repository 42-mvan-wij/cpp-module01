#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const {
	if (weapon == NULL) {
		std::cout << name << " tries to attack, but isn't wielding any weapon" << std::endl;
	}
	else {
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}
