#include <iostream>
#include "Harl.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q harl");
}

int main() {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("uhaehounsaehou");
	return (0);
}
