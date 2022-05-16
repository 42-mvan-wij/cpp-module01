#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	public:
		Harl();
		Harl(std::string filter_level);
		Harl(Harl const &src);
		~Harl();

		Harl &operator=(Harl const &rhs);

		void complain(std::string level);

	private:
		int filter_level;
		typedef void (Harl::*complain_fn)();
		complain_fn funcs[4];
		static const std::string levels[4];
		void insignificant(void);
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
