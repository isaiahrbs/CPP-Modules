#include <iostream>
#include <fstream>
#include <string>
#include <map>


class bitcoinExchange {
	private:
		std::string _btcPath;
		std::map<std::string, float> _container;

	public:
		bitcoinExchange();
		bitcoinExchange(std::string btc);
		bitcoinExchange& operator=(const bitcoinExchange& src);

		void build_data_base();

		class Error_DataBaseFile : public std::exeption {
			public:
				virtual const char *what() const throw();
		};
};