#pragma once
#include "point.h"
#include <fstream>

namespace abstracts {
	/*!
		\authors Наплавков Артем
		Абстракция, хранящая в себе информацию о складе: идентификатор, положение
		Коммуницирует с базами данных
	!*/
	struct Storage {
		int id;
		Point pos;

		void print(); ///выводит данные в консоль
		void input(); ///вводит новые данные с клавиатуры
		void save(std::ofstream &os); ///сохраняет данные в файл
		void read(std::ifstream& is); ///загружает данные из файла
	};
}