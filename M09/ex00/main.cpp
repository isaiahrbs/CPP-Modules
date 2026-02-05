#include <fstream>
#include "bitcoin.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: You must provide 2 arguments" << std::endl;
		return 1;
	}

	// call the constructor with argument
	bitcoinExchange btc = bitcoinExchange(argv[1]);

	//
	try {
		// build the data base
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

}