#include "order.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace abstracts {
	void Order::print() {
		std::cout
			<< "id=" << id
			<< "; storage_id=" << storage_id
			<< "; state=" << state << "; ";
		target.print();
	}
	void Order::input() {
		std::cout << "id=";
		int stop2;
		string line;
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(0, line.find('/'));
					id = stoi(s2);
					in.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		cout << id << endl;
		std::cout << "storage_id=";
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(line.find('/') + 1, line.find(' '));
					storage_id = stoi(s2);
					in.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << storage_id << std::endl;
		state = not_processed;
		target.input();

	}
	void Order::save(std::ofstream& os) {
		os << id << " "
			<< storage_id << " "
			<< state << " ";
		target.save(os);
	}
	void Order::read(std::ifstream& is) {
		is >> id >> storage_id >> state;
		target.read(is);
	}
}