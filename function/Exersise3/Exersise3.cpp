#include <iostream>
#include <iomanip>

/// <summary>
/// Функция
/// </summary>
/// <param name="x">- аргумент функции</param>
/// <returns></returns>
double f(double x)
{
    return x * x;
}

/// <summary>
/// Функция вычисления интеграла
/// </summary>
/// <param name="a">Нижняя граница</param>
/// <param name="b">Верхняя граница</param>
/// <param name="n">Кол-во отрезков на которое мы разбиваем интегрирование</param>
/// <returns></returns>
double integrate(double a, double b, int n)
{
    const double H = (b - a) / n; // Шаг стандартного "развернутого" разбиения
    double res = 0.0; 

    for (int i = 0; i < n; i++)
    {
        res += f(a + (0.5 + i) * H); // метод средних прямоугольников 
    }
    
    return res * H;
}

double findError(double a, double b, double expError)
{
    unsigned n = 1;
    double resDefaultIntegral = integrate(a, b, n);
    double resAccuracyIntegral = integrate(a, b, 2 * n);
    
    while ((resAccuracyIntegral - resDefaultIntegral) > expError)
    {
        n *= 2;
        resDefaultIntegral = integrate(a, b, n);
        resAccuracyIntegral = integrate(a, b, 2 * n);
    }

    return resDefaultIntegral;


}

int main()
{
    setlocale(LC_ALL, "Russian");

    double expError = 1e-10; // 0.0000000001

    std::cout << "Результат вычисления интеграла методом средних спрямоугольников (без указания опеределенно точности): " << std::setprecision(16) << integrate(2, 4, 1000) << "\n";
    std::cout << "Результат вычисления интеграла методом средних спрямоугольников c точностью : " << expError << "\t" << "Является:     " << findError(2, 4, expError) << "\n";

    return 0;
}

