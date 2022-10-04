#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	public:
		Harl();
		~Harl();

		void complain(std::string level);

	private:
		typedef void (Harl::*complain_fn)();
		static const complain_fn funcs[4];
		static const std::string levels[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
