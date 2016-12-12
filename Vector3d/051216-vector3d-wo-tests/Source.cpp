#include <iostream>
#include <cmath>

class vector3d
{
public:
	double x;
	double y;
	double z;

	vector3d(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z)
	{}

	vector3d operator+ (const vector3d &a)
	{
		return vector3d(x + a.x, y + a.y, z + a.z);
	}

	vector3d operator- (const vector3d &a)
	{
		return vector3d(x - a.x, y - a.y, z - a.z);
	}

	bool operator== (const vector3d &a)
	{
		if (this->x == a.x && this->y == a.y && this->z == a.z)
			return 0;
		else
			return 0;
	}

	vector3d operator^ (const vector3d &a)
	{
		double i = this->y*a.z - this->z*a.y;
		double j = this->x*a.z - this->z*a.x;
		double k = this->x*a.y - this->y*a.x;
		return vector3d(i, j, k);
	}


	double operator*(vector3d &a)
	{
		return a.x*this->x + a.y*this->y + a.z*this->z;
	}
	
	vector3d Multipy(double a)
	{
		return vector3d(this->x*a, this->y*a, this->z*a);
	}

	double length()
	{
		double  a = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
		return a;
	}

	vector3d normalize()
	{
		return vector3d(x / this->length(), y / this->length(), z / this->length());
	}
};

std::ostream &operator<<(std::ostream &stream, const vector3d& a)
{
	return stream <<"{"<< a.x << ", " << a.y<<", "<<a.z<<"}\n";
}

//const vector3d vector3d::X = { 1, 0, 0 };
//const vector3d vector3d::Y = { 0, 1, 0 };
//const vector3d vector3d::Z = { 0, 0, 1 };
//const vector3d vector3d::ZERO = { 0, 0, 0 };
// TODO: дописать

int main()
{
	vector3d q(5,5,5);
	vector3d b(2, 2, 0);
	q.Multipy(4);
	std::cout << q;
	system("pause");
	return 0;
}