#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(Zombie const &src);
		~Zombie();

		Zombie &operator=(Zombie const &rhs);

		void	announce(void);
		void	set_name(std::string name);

	private:
		std::string	name;
};

#endif
