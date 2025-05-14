#pragma once
#include <fstream>

namespace abstracts {
	/*!
		\authors Кукош Таисия
		\brief Абстракция, хранящая себе информацию о точке
		Хранит в себе положение по осям х и у, коммуницирует с базами данных
	!*/
	struct Point {
		double x;
		double y;
		
		void input(); ///вводит новые данные с клавиатуры
		void print(); ///выводит данные в консоль
		void save(std::ofstream& os); ///сохраняет данные в файл
		void read(std::ifstream& is); ///загружает данные из файла
	};
}