#include "storage.h"
#include <iostream>
#include <fstream>
#include <string>

namespace abstracts {
	void Storage::print() {
		std::cout << "id=" << id << "; ";
		pos.print();
	}
	void Storage::input() {
		std::cout << "id=";
		int stop2;
		std::string line;
		do {
			stop2 = 0;
			std::ifstream in("../��/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(0, line.find(' '));
					id = stoi(s2);
					in.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << id << std::endl;
		pos.input();
	}
	void Storage::save(std::ofstream& os) {
		os << id << " ";
		pos.save(os);
	}
	void Storage::read(std::ifstream& is) {
		is >> id;
		pos.read(is);
	}
}
