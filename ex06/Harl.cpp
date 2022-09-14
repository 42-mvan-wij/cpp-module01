#include <iostream>
#include "Harl.hpp"

const std::string Harl::levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

Harl::Harl() {
	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
}

Harl::Harl(std::string filter_level_str) {
	int filter_level = 0;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == filter_level_str) {
			filter_level = i;
			break;
		}
	}

	funcs[0] = &Harl::silent;
	funcs[1] = &Harl::silent;
	funcs[2] = &Harl::silent;
	funcs[3] = &Harl::silent;
	switch (filter_level) {
		case 0:
			funcs[0] = &Harl::debug;
		case 1:
			funcs[1] = &Harl::info;
		case 2:
			funcs[2] = &Harl::warning;
		case 3:
			funcs[3] = &Harl::error;
		default:
			break ;
	}
}

Harl::Harl(const Harl &src) {
	*this = src;
}

Harl &Harl::operator=(Harl const &rhs) {
	(void)rhs;
	return *this;
}

Harl::~Harl() {

}

void Harl::silent(void) {
}

void Harl::insignificant(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs[i])();
		}
	}
}
