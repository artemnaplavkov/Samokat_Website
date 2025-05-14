#include"storage_manager.h"
#include<iostream>
using namespace std;

namespace AbstractManagers {
	/*
	void Storage_manager::distribute_orders(vector<abstracts::Courier>* couriers, vector<abstracts::Order>* orders) {
		for (int i = 0; i < orders->size(); i++) {
			if ((*orders)[i].GetCondition() >= 1)
				break;
			for (int j = 0; j < couriers->size(); j++) {
				if ((*couriers)[j].get_order() == -1 && (*couriers)[i].storage_id==(*orders)[i].GetStorageID()) {
					std::cout << "courier " << (*couriers)[i].id << " got order with id " << (*orders)[i].ID() << std::endl;
					(*orders)[i].SetCondition(static_cast<abstracts::Condition>(1));
					(*couriers)[j].set_order(&(*orders)[i]);
					break;
				}
			}
			if ((*orders)[i].GetCondition() < 1)
				break;
		}
	}
	*/
}