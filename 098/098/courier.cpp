#include "courier.h"
#include <iostream>
#include <fstream>
#include <string>

namespace abstracts {
	void Courier::print() {
		std::cout
			<< "id=" << id
			<< "; speed_kmh=" << speed_kmh
			<< "; storage_id=" << storage_id
			<< "; current_order_id=" << current_order_id << "; ";
		pos.print();
	}
	void Courier::input() {
		std::cout << "id=";
		int stop2;
		std::string line;
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
		std::cout << id << std::endl;
		std::cout << "speed_kmh=";
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(line.find('/') + 1, line.find('-'));
					speed_kmh = stoi(s2);
					in.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << speed_kmh << std::endl;
		std::cout << "storage_id=";
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text2.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					std::string s2 = line.substr(line.find('-') + 1, line.find(' '));
					storage_id = stoi(s2);
					in.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		std::cout << storage_id << std::endl;
		current_order_id = 0;
		pos.input();
	}
	void Courier::save(std::ofstream& os) {
		os << id << " "
			<< speed_kmh << " "
			<< storage_id << " "
			<< current_order_id << " ";
		pos.save(os);
	}
	void Courier::read(std::ifstream& is) {
		is >> id >> speed_kmh >> storage_id >> current_order_id;
		pos.read(is);
	}
}