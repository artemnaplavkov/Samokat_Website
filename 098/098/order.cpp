#include "order.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace abstracts {
	void Order::print() {
		string line;
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
	/*
	int Order::GetCondition() { return static_cast<int>(_condition); }
	void Order::SetCondition(Condition condition) { _condition = condition; }

	int Order::GetStorageID() { return storage_id; }
	void Order::SetStorageID(int storage) { storage_id = storage; }

	Point Order::GetPoint() { return _point; }

	int Order::ID() { return id; }

	void Order::print() {
		cout << "condition id: " << this->GetCondition() << endl;
		cout << "order id: " << id << endl;
		cout << "storage id: " << storage_id << endl;
		cout << "order position: " << endl << "x: " << _point.x << endl << "y: " << _point.y << endl;
		cout << "time to end: " << time_to_complete << endl;
	}
	void Order::input() {
		std::cout << "id=";
		std::cin >> id;
		std::cout << "storage_id=";
		std::cin >> storage_id;
		_condition = Condition::dontgot;
		time_to_complete = 0.f;
		_point.input();
	}
	void Order::save(std::ofstream& os) {
		os << id << " "
			<< storage_id << " "
			<< this->GetCondition() << " "
			<< time_to_complete << " ";
		_point.save(os);
	}
	void Order::read(std::ifstream& is) {
		int cond_id;
		is >> id >> storage_id >> cond_id >> time_to_complete;
		SetCondition(static_cast<Condition>(cond_id));
		_point.read(is);
	}
	void Order::set_time(float time) {
		time_to_complete = time;
	}
	void Order::time_gone(float time) {
		time_to_complete -= time;
	}
	float Order::get_time() {
		return time_to_complete;
	}
	*/
}