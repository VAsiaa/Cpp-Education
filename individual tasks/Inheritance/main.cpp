//Кольцо.Конструктор принимает точку центра и пару радиусов : внешней и внутренней
//окружности соответственно.Центром фигуры считаются центры окружностей

/*
Создать файл point.h, содержащий определение структуры Point, представляющей
собой точку на плоскости. Координаты должны храниться в полях x и y.
2. Создать файл shape.h, содержащий определение абстрактного класса Shape. Этот класс
должен предоставлять следующие методы:
• getArea вычисление площади
• scale изотропное масштабирование фигуры относительно её центра с указанным
коэффициентом
• getCenter получение точки центра фигуры
• getName получение названия фигуры (RECTANGLE, CIRCLE и т.д.), метод использовать
при выводе
3. Реализовать класс Rectangle, производный от Shape, в файлах rectangle.h и
rectangle.cpp, соответственно (см. раздел «Фигуры»).
4. Реализовать фигуру, указанную в варианте (см. раздел «Фигуры»).
5. Перегрузить оператор сравнения < для класса Shape. Сравнение проводить по площади
фигуры.
6. Реализовать функцию, сортирующую массив указателей на фигуры в порядке неубывания
их площадей (алгоритм сортировки выберите на ваше усмотрение).
7. Написать программу, в которой:
• Создать массив указателей на фигуры (не менее 5 фигур)
• Отсортировать фигуры по неубыванию площадей
• Вывести информацию о фигурах на экран (имя, координаты центра, площадь)
• Выполнить масштабирование всех фигур на заданный коэффициент
• Вывести информацию о фигурах на экран ещё раз

Фигуры:
• У каждой фигуры должен быть конструктор, принимающий определённые параметры.
• Классы должны контролировать свои данные и не допускать создания объектов с
некорректным состоянием (можно выбрасывать исключения с помощью throw).
• Объявление класса должно быть в заголовочном файле (.h, не забывайте про header guard), а
определения методов в файле реализации (.cpp).
Прямоугольник. Конструктор принимает две точки: левый нижний и правый верхний углы.
Считается, что стороны прямоугольника параллельны осям координат. Центром фигуры считается
точка пересечения диагоналей.
*/

#include "shape.h"
#include "rectangle.h"
#include "ring.h"
#include <iostream>


int main()
{
	const int SIZE = 5;
	Shape* shapes[SIZE]{ nullptr };
	
	Point x = { 0.0,0.0 }; //left bottom
	Point y = { 4.0,2.0 }; //right top

	Point x2 = { 2.0,2.0 };
	Point y2 = { 6.0,5.0 };

	Point x3 = { 2.0,-1.0 };
	Point y3 = { 2.0,2.0 };

	Point centre = { 0,0 };

	try 
	{
		shapes[0] = new Rectangle(x,y);
		shapes[1] = new Rectangle(x2,y2);
		shapes[2] = new Rectangle(x3,y3);
		shapes[3] = new Ring(centre,2.0,4.0);
		shapes[4] = new Ring(centre,2.0,3.0);

		//shapes[2] = new Rectangle(y, x);         //incorrect input value 
		//shapes[3] = new Ring(centre, 4.0, 2.0);  //incorrect input value 
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
		for (int i = 0; i < SIZE; ++i)
		{
			delete shapes[i];
			shapes[i] = nullptr;
			return 0;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " << shapes[i]->getArea() << "\n";
	}
	std::cout << "---------------------------------------------------- \n";


	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = 0; j < SIZE - 1-i; j++)
		{
			if (*shapes[j + 1] < *shapes[j])
			{
				std::swap(shapes[j], shapes[j + 1]);
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " <<  shapes[i]->getArea() <<"\n";
	}

	std::cout << "---------------------------------------------------- \n";
	std::cout << "Scale shapoes on 2.0 \n";

	for (int i = 0; i < SIZE; i++)
	{
		try
		{
			shapes[i]->scale(2.0);
			//shapes[i]->scale(0.0);  //incorrect factor value 
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
			for (int i = 0; i < SIZE; ++i)
			{
				delete shapes[i];
				shapes[i] = nullptr;
				return 0;
			}
		}

	}

	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " << shapes[i]->getArea() << "\n";
	}

	for (int i = 0; i < SIZE; ++i)
	{
		delete shapes[i];
		shapes[i] = nullptr;
	}
	return 0;
}

