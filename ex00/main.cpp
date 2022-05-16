#include <iostream>
#include "Zombie.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks brainz");
}

Zombie *newZombie(std::string name);
void randomChump(std::string name);
int main() {
	Zombie *alice = newZombie("Alice");
	alice->announce();
	delete alice;
	randomChump("Bob");
	return (0);
}
