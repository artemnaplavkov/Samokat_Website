#include "point.h"
#include <iostream>
#include <fstream>
#include <string>

namespace abstracts {
	void Point::input() {
		std::cout << "x=";
		int stop2;
		std::string line;
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(line.find(' ') + 1, line.find('@'));
					x = stoi(s2);
					in.close();
					std::ofstream ofs;
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << x << std::endl;
		std::cout << "y=";
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(line.find('@') + 1, line.find('|'));
					y = stoi(s2);
					in.close();
					std::ofstream ofs;
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << y << std::endl;
	}
	void Point::print() {
		std::cout << "x=" << x << "; " << "y=" << y << "; ";
	}
	void Point::save(std::ofstream& os) {
		os << x << " " << y << " ";
	}
	void Point::read(std::ifstream& is) {
		is >> x >> y;
	}
}
