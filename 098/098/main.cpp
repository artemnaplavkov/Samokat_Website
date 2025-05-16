#include "courier.h"
#include "order.h"
#include "storage.h"
#include "time_manager.h"
#include "database_manager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


int main() {
	std::vector<abstracts::Storage> storages;
	std::vector<abstracts::Courier> couriers;
	std::vector<abstracts::Order> orders;
	DatabaseManager database;
	TimeManager time_manager;


	std::ofstream ofs;
	int stop = 0, stop2 = 0;
	std::string line;
	std::string line2;

	while (stop != 1) {
		ofs.open("../Пр/123/data/text.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		ofs.open("../Пр/123/data/text2.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		std::ifstream ini_file{ "courier.txt" };
		std::ofstream out_file{ "../Пр/123/data/courier.txt" };
		if (ini_file && out_file) {
			while (getline(ini_file, line2)) {
				out_file << line2 << "\n";
			}
		}
		else {
			printf("Cannot read File");
		}
		ini_file.close();
		out_file.close();
		std::ifstream ini_file2{ "storage.txt" };
		std::ofstream out_file2{ "../Пр/123/data/storage.txt" };
		if (ini_file2 && out_file2) {
			while (getline(ini_file2, line2)) {
				out_file2 << line2 << "\n";
			}
		}
		else {
			printf("Cannot read File");
		}
		ini_file2.close();
		out_file2.close();
		std::ifstream ini_file3{ "order.txt" };
		std::ofstream out_file3{ "../Пр/123/data/order.txt" };
		if (ini_file3 && out_file3) {
			while (getline(ini_file3, line2)) {
				out_file3 << line2 << "\n";
			}
		}
		else {
			printf("Cannot read File");
		}
		ini_file3.close();
		out_file3.close();
		std::cout
			<< "\n1-save"
			<< "\n2-read"
			<< "\n3-time shift"
			<< "\n4-print storages"
			<< "\n5-add storage"
			<< "\n6-remove storage"
			<< "\n7-print couriers"
			<< "\n8-add courier"
			<< "\n9-remove courier"
			<< "\n10-print orders"
			<< "\n11-add order"
			<< "\n";
		int key;
		do {
			stop2 = 0;
			std::ifstream in("../Пр/123/data/text.txt");
			if (in.is_open())
			{
				if (std::getline(in, line)) {
					key = stoi(line);
					in.close();
					std::ofstream ofs;
					ofs.open("../Пр/123/data/text.txt", std::ofstream::out | std::ofstream::trunc);
					ofs.close();
					stop2 = 1;
				}
			}
			in.close();
		} while (stop2 == 0);
		switch (key) {
		case 1:
			database.save(storages);
			database.save(couriers);
			database.save(orders);
			break;
		case 2:
			database.read(storages);
			database.read(couriers);
			database.read(orders);
			break;
		case 3: {
			std::cout << "hours=";
			int hours;
			do {
				stop2 = 0;
				std::ifstream in("../Пр/123/data/text2.txt");
				if (in.is_open())
				{
					if (std::getline(in, line)) {
						hours = stoi(line);
						in.close();
						stop2 = 1;
					}
				}
				in.close();
			} while (stop2 == 0);
			time_manager.time_shift(hours, storages, couriers, orders);
			break;
		}
		case 4:
			std::cout << "storages:\n";
			for (int i = 0; i < storages.size(); i++) {
				storages[i].print();
				std::cout << "\n";
			}
			break;
		case 5: {
			database.add_storage(storages);
			break;
		}
		case 6: {
			std::cout << "removing storage id=";
			int id;
			do {
				stop2 = 0;
				std::ifstream in("../Пр/123/data/text2.txt");
				if (in.is_open())
				{
					if (std::getline(in, line)) {
						id = stoi(line);
						in.close();
						stop2 = 1;
					}
				}
				in.close();
			} while (stop2 == 0);
			std::cout << id << std::endl;
			database.remove_storage(storages, couriers, orders, id);
			break;
		}
		case 7: {
			std::cout << "couriers from storage id=";
			int storage_id;
			std::cin >> storage_id;
			for (int i = 0; i < couriers.size(); i++) {
				if (couriers[i].storage_id == storage_id) {
					couriers[i].print();
					std::cout << "\n";
				}
			}
			break;
		}
		case 8: {
			database.add_courier(couriers, storages);
			break;
		}
		case 9: {
			std::cout << "removing courier id=";
			int id;
			do {
				stop2 = 0;
				std::ifstream in("../Пр/123/data/text2.txt");
				if (in.is_open())
				{
					if (std::getline(in, line)) {
						id = stoi(line);
						in.close();
						stop2 = 1;
					}
				}
				in.close();
			} while (stop2 == 0);
			std::cout << id << std::endl;
			database.remove_courier(couriers, id);
			break;
		}
		case 10:
			std::cout << "orders:\n";
			for (int i = 0; i < orders.size(); i++) {
				if (orders[i].state != abstracts::completed) {
					orders[i].print();
					std::cout << "\n";
				}
			}
			break;
		case 11: {
			database.add_order(orders, storages);
			break;
		}
		default:
			std::cout << "bye\n";
			stop = 1;
			break;
		}
	}

}