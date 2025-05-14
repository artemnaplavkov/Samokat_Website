#pragma once
#include "point.h"
namespace singletones {
	/*!
		\authors Кукош Таисия
		Менеджер точки, сравнивает точки на равенство, вычисляет дистанцию между точками и создает новые абстракции
	!*/
	struct PointManager{
		static double get_distance(abstracts::Point& a, abstracts::Point& b); ///вычисляет дистанцию от точки а до точки б
		static bool equal(abstracts::Point& a, abstracts::Point& b); ///сравнивает на равенство две точки
		static abstracts::Point new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh); ///создает новую точку

	};
}