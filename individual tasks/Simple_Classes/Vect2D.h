#ifndef INDV_3_VECT2D_H_
#define INDV_3_VECT2D_H_

#include <vector>
#include <iostream>


class Vect2D
{
public: 

	Vect2D(const double x, const double y);

	Vect2D operator+(const Vect2D& v2d2) const;

	Vect2D operator*(double value) const;

	friend std::ostream& operator<<(std::ostream& stream, const Vect2D& vect2D);

	double operator*(const Vect2D& v2d2) const;

	double getSize() const;


private:
	double x_;
	double y_;
};
#endif

