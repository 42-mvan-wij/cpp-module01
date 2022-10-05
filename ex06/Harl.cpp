#include <iostream>
#include "Harl.hpp"

const std::string Harl::levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

const Harl::complain_fn Harl::funcs[4] = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error,
};

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

ssize_t Harl::get_level_index(std::string level) {
	for (ssize_t i = 0; i < 4; i++) {
		if (levels[i] == level) {
			return i;
		}
	}
	return -1;
}

void Harl::complain(std::string level) {
	ssize_t level_index = get_level_index(level);
	if (level_index != -1) {
		(this->*funcs[level_index])();
	}
}
