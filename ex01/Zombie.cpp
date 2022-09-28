#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("Generic Zombie") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie(const Zombie &src) : name(src.name) {}

Zombie &Zombie::operator=(Zombie const &rhs) {
	this->name = rhs.name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << "Zombie \"" << this->name << "\" destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}
