#include "bitcoinExchange"

bitcoinExchange::bitcoinExchange() {
	_btcPath = "data.csv";
}

bitcoinExchange::bitcoinExchange(std::string bitcoinFile) {
	_btcPath = bitcoinFile;
}

bitcoinExchange& bitcoinExchange::operator=(const bitcoinExchange& src) {
	if (this != &src) {
		_btcPath = src._btcPath;
		_container = src._container;
	}
	return *this;
}

void	bitcoinExchange::build_data_base() {
	std::ifstream openedFile(_btcPath.c_str());

	if (!openedFile.isopen()) {
		throw Error_DataBaseFile();
	}
	// left off here
}

const char* bitcoinExchange::Error_DataBaseFile::what() const throw() {
	return "Cannot open file!";
	
}