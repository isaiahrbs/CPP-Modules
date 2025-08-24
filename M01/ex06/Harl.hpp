#ifndef HARL_CPP
#define HARL_CPP

#include <string>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(const std::string& level);

};

#endif