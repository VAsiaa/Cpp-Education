/*
 Разработать класс для работы с двумерными векторами.Методы для сложения, скалярного
 произведения векторов, вычисления длины вектора, умножения вектора на число.
 Реализовать перегруженный оператор << для вывода информации в поток.
*/ 



#include <iostream>
#include "Vect2D.h"

int main()
{
    double x = 3.14;
    double y = 6.18;

    Vect2D v2D(x,y);
    Vect2D v2D2(y,x);
    std::cout << "Vect 1 \n";
    std::cout << v2D << "\n";

    std::cout << "Vect 2 \n";
    std::cout << v2D2 << "\n";

    std::cout << "Vect 3 = vect 1 + vect 2: \n";
    Vect2D v2D3 = v2D + v2D2;
    std::cout << v2D3 << "\n";

    std::cout << "Size of vect 3: \n";
    std::cout << v2D3.getSize() << "\n";


    std::cout << "\n" << "Multiplying vect 3 by a number (2):" << "\n";
    std::cout << v2D3 * 2 << "\n";

    std::cout << "Scalar product (vect3 * vect 2): \n";
    std::cout << v2D3 * v2D2;
}

