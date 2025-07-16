#include <iostream>
#include <fstream>
#include <string>


/*
	ifstream c'est comme open en C
	ofstream ca cree un fichier (s'il n'existe pas) et ca louvre pret pour utilisation
	mais si il existe deja il va just louvrir
*/

// Remplace toutes les occurrences de s1 par s2 dans le fichier filename
int replaceAndWrite(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open the input file." << std::endl;
        return 1;
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create the output file." << std::endl;
        inputFile.close();
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string result;
        size_t start = 0;
        while (true) {
            size_t found = line.find(s1, start);
            if (found == std::string::npos) {
                result += line.substr(start);
                break;
            }
			/*
			result est egal a tout ce qui ya entre le debut dla phrase
			jusquau debut du mot trouvé
			en gros je fais found - start pour savoir combien de chars jai parcouru
			*/
            result += line.substr(start, found - start);
            result += s2;
            start = found + s1.length();
        }
        outputFile << result << '\n';
    }
    inputFile.close();
    outputFile.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./main <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt") {
        std::cerr << "Error: filename must end with .txt" << std::endl;
        return 1;
    }
    if (s1.empty()) {
        std::cerr << "Error: <s1> must not be empty" << std::endl;
        return 1;
    }
	replaceAndWrite(filename, s1, s2);
	return 0;
}