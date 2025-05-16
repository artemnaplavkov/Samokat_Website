#pragma once
#include <fstream>

namespace abstracts {

	struct Point {
		double x;
		double y;
		void input();
		void print();
		void save(std::ofstream& os);
		void read(std::ifstream& is);
	};
}