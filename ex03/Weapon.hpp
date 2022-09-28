#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	public:
		Weapon(std::string type);
		Weapon(Weapon const &src);
		~Weapon();

		Weapon &operator=(Weapon const &rhs);

		std::string const &getType(void);
		void setType(std::string type);

	private:
		Weapon();
		std::string type;

};

#endif
