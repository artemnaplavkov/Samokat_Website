#pragma once
#include"point.h"
#include"storage.h"
#include<fstream>

namespace abstracts {
	/*!
		\authors Соловьев Данила
		\brief Список состояний, которые может принимать заказ
	!*/
	int const not_processed = 0;
	int const in_progress = 1;
	int const completed = 2;

	/*
	enum class Condition {
		dontgot = 0,
		got = 1,
		finished = 2,
	};
	*/

	/*!
		\authors Соловьев Данила
		\brief Абстракция, хранящая в себе информацию о заказе
		Хранит в себе информацию о заказе: время до выполнения, идентификатор склада, положение, состояние, идентификатор
		Обладает функциями получения/загрузки данных, коммуницирует с базами данных
	!*/
	struct Order {
		int id;
		int storage_id;
		int state;
		Point target;

		void print();
		void input();
		void save(std::ofstream& os);
		void read(std::ifstream& is);
	};
	/*
	class Order {
	private:
		float time_to_complete;
		int storage_id;
		Point _point;
		Condition _condition;
		int id;
	public:
		
		int GetStorageID();///возвращает идентификатор склада
		
		void SetStorageID(int storage);///устанавливает новый склад по идентификатору

		
		void SetCondition(Condition condition);///устанавливает состояние заказа
		
		int ID();///возвращает идентификатор заказа
		
		
		Point GetPoint();///возвращает точку заказа
		
		int GetCondition();///возвращает идентификатор состояния заказа

		
		void input();///устанавливает новый заказ с клавиатуры
		
		void print();///выводит заказ в консоль
		
		void save(std::ofstream& os);///сохраняет заказ в файл
		
		void read(std::ifstream& is);///берет заказ из файла

		
		void set_time(float time);///устанавливает время сдачи заказа
		
		float get_time();///возвращает время до сдачи заказа
		
		void time_gone(float time);///проматывает время сдачи заказа
	};
	*/
}