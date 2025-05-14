#include "point.h"
#include <iostream>
#include<math.h>
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
					x = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
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
					y = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << y << std::endl;
	}
	void Point::print() {
		std::cout << "x=" << x << "; " << "y=" << y<<"; ";
	}
	void Point::save(std::ofstream& os) {
		os << x << " " << y << " ";
	}
	void Point::read(std::ifstream& is) {
		is >> x >> y;
	}

	/*
	double Point::length(Point first,Point second) { 
		std::cout << pow(first.x - second.x, 2) << std::endl << pow(first.y - second.y, 2) << std::endl << sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2)) << std::endl;
		return (sqrt(pow(first.x - second.x, 2)+ pow(first.y - second.y, 2)));
	 }
	 */
}
