#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q brainz");
}

int main() {
	atexit(&check_leaks);
	Zombie *alice = newZombie("Alice");
	alice->announce();
	delete alice;
	randomChump("Bob");
	return (0);
}
