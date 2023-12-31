﻿// Ilia Shemiakin, 2023
// Функции

// В представленных ниже примерах ошибки ввода для краткости НЕ обрабатываются
// и могут вызвать некорректное повдение программы!

#include <iostream>

// глобальная переменная
int globalVariable = 1;

// Объявления функций  (определения в конце файла)
// Имена параметров при объявлении можно опускать  , но лучше указывать, т.к. это улучшает читаемость. 

// функция, возводящая base в целую степень pow
double power(double base, int pow);

// функция, возвращающая значение модуля числа;
inline double absolute(double n);

// функция, возвращающая значение корня n-ной (целой) степени числа number с точностью error
double nRoot(double number, int n, double error);

// рекурсивная функция, возвращающая наибольший общий делитель (НОД, англ. GCD) двух чисел
int gcd(int n1, int n2);

// функция, обменивающая значения аргументов
void swap(int &n1, int &n2);

// функция, возвращающая ссылку
int & strange();

int main()
{
    int choice = 1;
    while (choice != 0)
    {
        std::cout << "Select function:\n"
            << " 1 - power\n"
            << " 2 - nRoot\n"
            << " 3 - gcd\n"
            << " 0 - exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Exit\n";
            break;
        case 1:
        {
            std::cout << "Enter base: ";
            // эта переменная объявлена внутри блока {...} и существует только внутри него
            double base = 0.0;
            std::cin >> base;

            std::cout << "Enter power: ";
            int pow = 0;
            std::cin >> pow;

            std::cout << "The number " << base << " to the power of " << pow << " is "
                << power(base, pow) << '\n';

            break;
        }
        case 2:
        {
            std::cout << "Enter base: ";
            // переменная с именем base уже есть в case 1,
            // но т.к. содержимое каждого case находится в собственном блоке {...},
            // в них могут быть объявлены локальные переменные с совпадающими именами
            double base = 0.0;
            std::cin >> base;

            std::cout << "Enter root degree: ";
            int rootDegree = 0;
            std::cin >> rootDegree;

            std::cout << "Enter error: ";
            double error = 0.0;
            std::cin >> error;

            std::cout << "The root " << rootDegree << " degrees of " << base << " is "
                << nRoot(base, rootDegree, error) << '\n';

            break;
        }
        case 3:
        {
            std::cout << "Enter first number: ";
            int a = 0;
            std::cin >> a;

            std::cout << "Enter second number: ";
            int b = 0;
            std::cin >> b;

            std::cout << "Numbers " << a << " and " << b << " have greatest common divisor "
                << gcd(a, b) << '\n';

            break;
        }
        default:
            std::cout << "Try again\n";
        }
    }

    std::cout << '\n';

    // Ссылки

    // Ссылку можно рассматривать как еще одно имя объекта.
    // В основном ссылки используются для задания параметров функций и возвращаемых функциями значений,
    // а также для перегрузки операций. 
    // Запись T& обозначает ссылку на переменную типа T. 
    int  i = 1;
    int &r = i;     // r и i  ссылаются на одно и то же целое (т.е. r становится как бы вторым именем i)

    int  x = r;     // x = 1
    std::cout << "variable i=" << i << "; reference r=" << r << "; variable x(=r)=" << x << '\n';

    r = 2;          // i = 2;
    std::cout << "variable i=" << i << "; reference r=" << r << '\n';

    // Ссылка должна быть инициализирована, т.е. должно быть нечто, что она может обозначать.
    // Следует помнить, что инициализация ссылки совершенно отличается от операции присваивания,
    // хотя можно указывать операции над ссылкой, ни одна из них на саму ссылку не действует.
    int  ii = 0;
    int &rr = ii;   // инициализация ссылки обязательна, иначе будет ошибка
    std::cout << "variable ii=" << ii << "; reference rr=" << rr << '\n';

    ++rr;           // ii увеличивается на 1
    std::cout << "variable ii=" << ii << "; reference rr=" << rr << '\n';

    // Здесь операция ++ допустима, но ++rr не увеличивает саму ссылку rr. 
    // Вместо этого ++ применяется к переменной ii.
    // Следовательно, после инициализации ссылка всегда указывает на тот объект, к которому была привязана.

    std::cout << '\n';

    // применение функции swap, обменивающей значения аргументов
    int n1 = 5;
    int n2 = 10;

    std::cout << "Before: n1=" << n1 << ", n2=" << n2 << '\n';
    swap(n1, n2);
    std::cout << "After swap(n1, n2) : n1=" << n1 << ", n2=" << n2 << '\n';

    std::cout << '\n';

    // теперь небольшая "интересность", попытайтесь понять, почему так происходит

    std::cout << "before globalVariable=" << globalVariable << '\n';

    strange() = 5;	// используем функцию слева от оператора присваивания О_о

    std::cout << "after globalVariable=" << globalVariable << '\n'; // значение globalVariable изменилось

    // в то же время нашу функцию можно использовать и привычным образом,
    // всё дело в том, что strange() возвращает не значение а ссылку на globalVariable, 
    // т.е. её можно использовать вместо этой переменной
    std::cout << "normal usage strange(): " << strange() << '\n';

    return 0;
}

// Функция, возвращающая значение модуля числа (понадобится в следующих функциях)
// Ключевое слово inline даёт компилятору рекомендацию заменить вызов функции кодом из тела этой функции
inline double absolute(double n)
{
    return n < 0 ? -n : n;
}

// Функция, возводящая base в целую степень pow
// При возведении нуля в нулевую или отрицательную степень результат не определён
// https://ru.wikipedia.org/wiki/%D0%92%D0%BE%D0%B7%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B2_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D1%8C#%D0%A6%D0%B5%D0%BB%D0%B0%D1%8F_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D1%8C

double power(double base, int pow)
{
    double res = 1.0;
    int powAbs = absolute(pow);
    for (int i = 0; i < powAbs; ++i)
    {
        res *= base;
    }
    return (pow > 0) ? res : (1.0 / res);
}

// Функция, возвращающая значение корня n-ной (целой положительной) степени числа number с точностью error
// чтобы написать функцию воспользуемся алгоритмом нахождения корня n-ной степени
// http://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%BD%D0%B0%D1%85%D0%BE%D0%B6%D0%B4%D0%B5%D0%BD%D0%B8%D1%8F_%D0%BA%D0%BE%D1%80%D0%BD%D1%8F_n-%D0%BD%D0%BE%D0%B9_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D0%B8
// алгоритм (посмотрите ссылку выше, там формула выглядит понятнее):
// 1. задать произвольное X(0)
// 2. задать X(k+1) = ((N-1)*X(k) + M/X(k)^(N-1)) / N, где M - число, из которого необходимо извлечь корень
//														   N - степень корня
//														   X(k) - значение X на текущей итерации
//														   X(k+1) - значение X на следующей итерации
//														   ^(N-1) - возведение в степень N-1
// 3. повторять шаг 2, пока не будет достигнута необходимая точность.
// Так для квадратного корня формула принимает вид X(k+1) = (X(k) + M/X(k)) / 2 - итерационная формула Герона
// Точность будем определять так:
// для указанной точности e результат функции res должен удовлетворять условию |(res^N) - M| < e,
// т.е. результат, возведённый в степень корня, должен отличаться от исходного числа не более, 
// чем на e

double nRoot(double number, int n, double error)
{
    // если функция вызвана с некорректными аргументами - выбросим исключение;
    // об исключениях рассказывается в другом примере
    if (number < 0 || n <= 0 || error <= 0)
    {
        throw std::invalid_argument("Invalid argument");
    }
    double res = number;	// примем X(0) = number
    // повторяем пока модуль больше допустимой ошибки
    while (absolute(power(res, n) - number) > error)
    {
        res = ((n - 1) * res + number / power(res, n - 1)) / n;
    }
    return res;
}

// Рекурсивная функция, возвращающая наибольший общий делитель двух чисел (НОД)
// Алгоритм Евклида:
// Пусть a и b — целые числа, не равные одновременно нулю, и последовательность чисел
//    a > b > r1 > r2 > r3 > r4 > ... >rn
// определена тем, что каждое rk — это остаток от деления предпредыдущего числа на предыдущее,
// а предпоследнее делится на последнее нацело, то есть
//    a = b * q0 + r1
//    b = r1 * q1 + r2
//    r1 = r2 * q2 + r3
//	...
//    r{k-2} = r{k-1} * q{k-1} + rk
//	...
//    r{n-1} = rn * qn
// Тогда НОД(a,b), наибольший общий делитель a и b, равен rn, т.е. последнему ненулевому члену этой последовательности.
// Отсюда вытекают три факта:
// 1)НОД(n1,n2)=НОД(n2,n1)
// 2)НОД(0,n2)=n2
// 3)НОД(n1,n2)=НОД(n2,n3), где n3=n1%n2
//
// Из этих правил можно построить небольшую рекурсивную функцию

int gcd(int n1, int n2)
{
    if (n1 == 0)
    {
        return n2;
    }
    return gcd(n2 % n1, n1);
}

// Функция, обменивающая значения аргументов.
// При передаче аргументов по ссылке значения аргументов не копируются,
// вместо этого функция работает с настоящими переменными и может изменять их значения
void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

// Функция, возвращающая ссылку
int & strange()
{
    return ::globalVariable;
}