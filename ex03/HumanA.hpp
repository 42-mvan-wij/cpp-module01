#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(HumanA const &src);
		~HumanA();

		HumanA &operator=(HumanA const &rhs);

		void	attack(void);

	private:
		Weapon *weapon;
		std::string name;

};

#endif
