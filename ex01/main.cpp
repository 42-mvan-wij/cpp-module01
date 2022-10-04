#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"
#include "zombieHorde.hpp"

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

	std::cout << "5 Alice zombies:" << std::endl;
	announceZombieHorde(5, "Alice");
	std::cout << std::endl;
	std::cout << "10 Bob zombies:" << std::endl;
	announceZombieHorde(10, "Bob");
	std::cout << std::endl;
	std::cout << "0 Carl zombies:" << std::endl;
	announceZombieHorde(0, "Carl");
	return (0);
}
