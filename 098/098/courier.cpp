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
					id = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
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
					speed_kmh = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
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
					storage_id = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
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
	/*
	void Courier::set_order(abstracts::Order* order) {
		current_order_id = (*order).ID();
		Point sec_pos = order->GetPoint();
		(*order).set_time(singletones::PointManager::get_distance(pos,sec_pos)/speed_kmh);
	}
	void Courier::set_order(int order_id) {
		current_order_id = order_id;
	}
	void Courier::set_point(abstracts::Point point) {
		pos = point;
	}
	int Courier::get_order() {
		return current_order_id;
	}
	*/
}