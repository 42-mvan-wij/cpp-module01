#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::Zombie(const Zombie &src) {
	*this = src;
}

Zombie &Zombie::operator=(Zombie const &rhs) {
	this->name = rhs.name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << "Zombie \"" << this->name << "\" destructed" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}
