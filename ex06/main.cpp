#include <iostream>
#include "Harl.hpp"

int main() {
	Harl harl;

	ssize_t i = harl.get_level_index("DEBUG");
	switch (i) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return (0);
}
