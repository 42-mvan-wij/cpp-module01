#include <iostream>
#include <cstdlib>
#include "Harl.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q harl");
}

int main() {
	atexit(&check_leaks);
	Harl harl;

	std::cout << "DEBUG:   "; harl.complain("DEBUG");
	std::cout << "INFO:    "; harl.complain("INFO");
	std::cout << "WARNING: "; harl.complain("WARNING");
	std::cout << "ERROR:   "; harl.complain("ERROR");

	std::cout << "nothing: "; harl.complain("nothing"); std::cout << std::endl;

	std::cout << "WARNING: "; harl.complain("WARNING");
	std::cout << "DEBUG:   "; harl.complain("DEBUG");
	std::cout << "INFO:    "; harl.complain("INFO");
	return (0);
}
