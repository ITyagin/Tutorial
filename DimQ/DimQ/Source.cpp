#include <iostream>

using namespace std;

template <int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0, int x5 = 0, int x6 = 0, int x7 = 0>

class DimQ {


public:

	double val;



	DimQ(double x) :val(x) {};



	void show() {

		cout << val;

	}







	template <int x11, int x22, int x33, int x44, int x55, int x66, int x77>

	DimQ<x1 + x11, x2 + x22, x3 + x33, x4 + x44, x5 + x55, x6 + x66, x7 + x77> operator *(DimQ<x11, x22, x33, x44, x55, x66, x77> X) {

		DimQ<x1 + x11, x2 + x22, x3 + x33, x4 + x44, x5 + x55, x6 + x66, x7 + x77> a(val*X.val);

		return a;

	}



	template <int x11, int x22, int x33, int x44, int x55, int x66, int x77>

	DimQ<x1 - x11, x2 - x22, x3 - x33, x4 - x44, x5 - x55, x6 - x66, x7 - x77> operator /(DimQ<x11, x22, x33, x44, x55, x66, x77> X) {

		DimQ<x1 - x11, x2 - x22, x3 - x33, x4 - x44, x5 - x55, x6 - x66, x7 - x77> a(val / X.val);

		return a;

	}

	DimQ<x1, x2, x3, x4, x5, x6, x7 > operator +(DimQ<x1, x2, x3, x4, x5, x6, x7>X) {

		DimQ<x1, x2, x3, x4, x5, x6, x7 > a(val + X.val);

		return a;

	}

	DimQ<x1, x2, x3, x4, x5, x6, x7 > operator -(DimQ<x1, x2, x3, x4, x5, x6, x7>X) {

		DimQ<x1, x2, x3, x4, x5, x6, x7 > a(val - X.val);

		return a;

	}

	DimQ<x1, x2, x3, x4, x5, x6, x7 > operator -() {

		DimQ<x1, x2, x3, x4, x5, x6, x7 > a(-val);

		return a;

	}



};

typedef DimQ<1, 0, 0, 0, 0, 0, 0> Length;

typedef DimQ<0, 0, 1, 0, 0, 0, 0> Time;

typedef DimQ<1, 0, -2, 0, 0, 0, 0> Acceleration;

typedef DimQ<1, 0, -1, 0, 0, 0, 0> Velocity;





template<int x1, int x2, int x3, int x4, int x5, int x6, int x7>

ostream & operator<<(ostream & stream, const DimQ<x1, x2, x3, x4, x5, x6, x7> & X) {

	stream << X.val << " ";

	if (x1)stream << "m(" << x1 << ")";

	if (x2)stream << "kg(" << x2 << ")";

	if (x3)stream << "s(" << x3 << ")";

	if (x4)stream << "A(" << x4 << ")";

	if (x5)stream << "K(" << x5 << ")";

	if (x6)stream << "mol(" << x6 << ")";

	if (x7)stream << "cd(" << x7 << ")";

	return stream;

}





int main() {



	DimQ<1> a(2);

	DimQ<1, 0> b(3);

	DimQ<> c(5);

	a = a + b;

	c = a / b;

	a = -a;

	cout << a;
	system("pause");

	return 0;

}