//
// Created by Price Skip on 8/11/22.
//
#include <string>
#include <iostream>
#include <fstream>

int errorArg(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (fileName.empty() || s1.empty() || s2.empty() || s2.find(s1) != std::string::npos) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if(errorArg(argc, argv))
		return 1;

	std::ifstream oldFile(argv[1]);
	if (oldFile.is_open() == 0) {
		std::cout << "Error open file" << std::endl;
		return 1;
	}

	std::string newFileName = (std::string)argv[1] + ".replace";
	std::ofstream newFile(newFileName.c_str());
	if(newFile.is_open() == 0) {
		std::cout << "Error created file" << std::endl;
		return 1;
	}

	std::string buff;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	while (!oldFile.eof()) {
		getline(oldFile, buff);
		size_t pos = buff.find(s1);
		while (pos != std::string::npos)
		{
			buff.erase(pos, s1.length());
			buff.insert(pos, s2);
			pos = buff.find(s1);
		}
		newFile << buff << std::endl;
	}
	oldFile.close();
	newFile.close();
}