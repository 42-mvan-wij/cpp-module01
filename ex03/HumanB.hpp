#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		HumanB(HumanB const &src);
		~HumanB();

		HumanB &operator=(HumanB const &rhs);

		void	setWeapon(Weapon &weapon);
		void	attack(void);

	private:
		HumanB();
		Weapon *weapon;
		std::string name;
};

#endif
