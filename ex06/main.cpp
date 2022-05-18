#include <iostream>
#include "Harl.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q harlFilter");
}

int main(int argc, char *argv[]) {
	Harl *harl;
	if (argc == 2) {
		harl = new Harl(argv[1]);
	}
	else if (argc > 2) {
		std::cout << "Usage: " << argv[0] << " [filter_level]" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		harl = new Harl();
	}

	// harl->complain("DEBUG");
	// harl->complain("INFO");
	// harl->complain("WARNING");
	// harl->complain("WARNING");
	// harl->complain("WARNING");
	// harl->complain("WARNING");
	// harl->complain("ERROR");
	harl->complain("uhaehounsaehou");

	delete harl;
	return (0);
}
