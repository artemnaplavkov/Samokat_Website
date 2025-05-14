#include "point.h"
#include <iostream>
namespace abstracts {
	void Point::input() {
		std::cout << "x=";
		std::cin >> x;
		std::cout << "y=";
		std::cin >> y;
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
}
