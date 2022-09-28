#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name);

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q moar-brainz");
}

void	announceZombieHorde(int n, std::string name)
{
	Zombie *zombies = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
}

int main() {
	atexit(&check_leaks);

	announceZombieHorde(5, "Alice");
	announceZombieHorde(10, "Bob");
	return (0);
}
