#include <iostream>
#include "Harl.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q harlFilter");
}

int main(int argc, char *argv[]) {
	atexit(&check_leaks);
	Harl *harl;
	if (argc == 2) {
		std::string level(argv[1]);
		if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return (0);
		}
		harl = new Harl(level);
	}
	else if (argc > 2) {
		std::cout << "Usage: " << argv[0] << " [filter_level]" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		harl = new Harl();
	}

	harl->complain("DEBUG");
	harl->complain("INFO");
	harl->complain("WARNING");
	harl->complain("INFO");
	harl->complain("ERROR");
	harl->complain("DEBUG");
	harl->complain("WARNING");
	harl->complain("ERROR");

	delete harl;
	return (0);
}
