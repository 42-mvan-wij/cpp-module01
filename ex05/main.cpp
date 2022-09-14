#include <iostream>
#include "Harl.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q harl");
}

int main() {
	atexit(&check_leaks);
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("uhaehounsaehou");
	return (0);
}
