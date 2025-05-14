#pragma once
#include "storage.h"
#include "courier.h"
#include "order.h"
#include <vector>
#include <string>

struct DatabaseManager {
	/*!
		\authors Наплавков Артем
		\brief Менеджер базы данных, управляет базами данных и их содержанием
		Этот класс осуществляет работу с базами данных складов, курьеров и заказов
		Обладает функциями добавления, удаления сущностей, а также сохранением каждой базы данных в текстовый файл
	!*/
	std::string storage_file_name = "./storage.txt";
	std::string order_file_name = "./order.txt";
	std::string courier_file_name = "./courier.txt";

	
	void save(std::vector<abstracts::Storage> &storages);///сохраняет базу данных склада в файл
	
	void read(std::vector<abstracts::Storage>& storages);///загружает базу данных склада в файл
	
	void add_storage(std::vector<abstracts::Storage>& storages);///добавляет новый склад в базу данных
	
	void remove_storage(
		std::vector<abstracts::Storage>& storages, 
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders,
		int storage_id);///удаляет склад из базы данных

	
	void save(std::vector<abstracts::Courier>& couriers);///сохраняет базу данных курьеров в файл
	
	void read(std::vector<abstracts::Courier>& couriers);///загружает базу данных курьеров в файл
	
	void add_courier(
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Storage>& storages);///добавляет нового курьера в базу данных
	
	void remove_courier(
		std::vector<abstracts::Courier>& couriers,
		int courier_id);///удаляет курьера из базы данных

	
	void save(std::vector<abstracts::Order>& orders);///сохраняет базу данных заказов в файл
	
	void read(std::vector<abstracts::Order>& orders);///загружает базу данных заказов в файл
	
	void add_order(
		std::vector<abstracts::Order>& orders,
		std::vector<abstracts::Storage>& storages);///добавляет новый заказ в базу данных

};