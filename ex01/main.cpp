#include <iostream>
#include "Zombie.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q moar-brainz");
}

Zombie *zombieHorde(int n, std::string name);
int main() {
	atexit(&check_leaks);
	Zombie *zombies = zombieHorde(10, "Bob");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
