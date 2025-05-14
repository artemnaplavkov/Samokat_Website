#pragma once
#include "point.h"
#include "order.h"
#include "point_manager.h"
#include <fstream>

namespace abstracts {
	/*!
		\authors Наплавков Артем
		\brief Абстракция, хранящая в себе информацию о курьере
		Хранит в себе информацию о курьере: идентификатор, скорость, идентификатор склада и текущего заказа, позиция
		Может выводить, загружать обьекты класса и коммуницироввать с базами банных
	!*/
	struct Courier {
		int id;
		double speed_kmh;
		int storage_id;
		int current_order_id;
		Point pos;

		
		void print();///выводит информацию в консоль
		
		void input();///вводит новые данные через клавиатуру
		
		void save(std::ofstream& os);///сохраняет сущность в файл
		
		void read(std::ifstream& is);///загружает данные из файла
		/*
		void set_order(abstracts::Order* order);///устанавливает новый заказ по абстракции
		
		void set_order(int order_id);///устанавливает новый заказ по идентификатору
		
		void set_point(Point point);///устанавливает точку положения
		
		int get_order();///дает идентификатор заказа
		*/
	};
}