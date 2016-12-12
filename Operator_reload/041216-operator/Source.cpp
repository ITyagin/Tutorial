#include <iostream>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

class Fraction {
private:
	double numerator;
	double denominator;

	void simplify() {
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
		if (abs(numerator) < 2) return;
		int gcd = getGCD(abs(numerator), denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
public:
	Fraction(int n, int d) : numerator(n), denominator(d) {
		simplify();
	}

	Fraction() : numerator(0), denominator(1) {}
	Fraction(const Fraction &other) : numerator(other.getNumerator()), denominator(other.getDenominator()) {}

	Fraction(int value) : numerator(value), denominator(1) {}

	double getNumerator() const { return numerator; }
	double getDenominator() const { return denominator; }

	double getValue() const {
		return static_cast<double>(getNumerator()) / static_cast<double>(getDenominator());
	}

	int compareTo(const Fraction &other) const {
		return getNumerator() * other.getDenominator() - getDenominator() * other.getNumerator();
	}

	int getGCD(int a, int b) {
		while (a != b) {
			if (a > b) a -= b; else b -= a;
		}
		return a;
	}

	Fraction operator-() {
		return Fraction(-getNumerator(), getDenominator());
	}

	Fraction operator+(const Fraction &a) {
		int commonDenominator = a.getDenominator() * getDenominator();
		int commonNumerator = a.getNumerator() * getDenominator() + getNumerator() * a.getDenominator();
		return Fraction(commonNumerator, commonDenominator);
	}

	Fraction operator-(const Fraction &a) {
		int commonDenominator = a.getDenominator() * getDenominator();
		int commonNumerator = a.getNumerator() * getDenominator() - getNumerator() * a.getDenominator();
		return Fraction(commonNumerator, commonDenominator);
	}

	Fraction operator*(const Fraction &a) {
		return Fraction(getNumerator() * a.getNumerator(), getDenominator() * a.getDenominator());
	}

	Fraction operator/(const Fraction &a) {
		return Fraction(getNumerator() * a.getDenominator(), getDenominator() * a.getNumerator());
	}

	Fraction operator=(const int &b) {
		return Fraction(b, 1);
	}

	Fraction operator+(const int &b) {
		Fraction q = b;
		return *this+q;
	}

	Fraction operator-(const int &b) {
		Fraction q = b;
		return *this - q;
	}

	Fraction operator*(const int &b) {
		Fraction q = b;
		return *this * q;
	}

	Fraction operator/(const int &b) {
		Fraction q = b;
		return *this / b;
	}

	bool operator==(const Fraction &a) { return compareTo(a) == 0; }
	bool operator<(const Fraction &a)
	{
		 double a1 = this->numerator / this->denominator;
		 double a2 = a.numerator / a.denominator;
		 if (a1 < a2)
			 return 1;
		 else return 0;
	}

	bool operator>(const Fraction &a)
	{
		double a1 = this->numerator / this->denominator;
		double a2 = a.numerator / a.denominator;
		if (a1 > a2)
			return 1;
		else return 0;
	}

	bool operator<=(const Fraction &a)
	{
		double a1 = this->numerator / this->denominator;
		double a2 = a.numerator / a.denominator;
		if (a1 <= a2)
			return 1;
		else return 0;
	}

	bool operator>=(const Fraction &a)
	{
		double a1 = this->numerator / this->denominator;
		double a2 = a.numerator / a.denominator;
		if (a1 >= a2)
			return 1;
		else return 0;
	}
};

std::ostream &operator<<(std::ostream &stream, const Fraction& a) {
	return stream << a.getNumerator() << "/" << a.getDenominator();
}

Fraction power(const Fraction &fraction, int power) {
	return (power < 0) ?
		Fraction((int)pow((double)fraction.getDenominator(), -power), (int)pow((double)fraction.getNumerator(), -power)) :
		Fraction((int)pow((double)fraction.getNumerator(), power), (int)pow((double)fraction.getDenominator(), power));
}

int main(int argc, char **argv) {
	Fraction a(-4, 7), b(1, 3), c(0, 4);
	Fraction q = 5;
	Fraction f(2, 3), g(2, 4);
	bool y = f > g;
	std::cout <<"f, g="<<f<<", "<<g<<"compare f>g"<<y;
	system("pause");
	//std::cout << (a < b) << " " << power(Fraction(1, 4), -1) << std::endl;
}