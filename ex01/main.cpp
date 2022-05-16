#include <iostream>
#include "Zombie.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks moar-brainz");
}

Zombie *zombieHorde(int n, std::string name);
int main() {
	Zombie *zombies = zombieHorde(10, "Bob");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
