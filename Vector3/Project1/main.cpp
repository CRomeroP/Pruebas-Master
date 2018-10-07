#include<iostream>
#include<math.h>

template <class Vector3>
class Vec3 {
	Vector3 a, b, c;
public:
	Vec3()
	{
		a = b = c = 0;
	}
	Vec3(Vector3 first, Vector3 second, Vector3 third)
	{
		a = first; b = second; c = third;
	}
	/*Vec3(Vector3 copy)
	{
		a = copy.a; b = copy.b; c = copy.c;
	}*/

	void normalize();
	void distanceTo(const Vec3<Vector3> &distVec);
	Vec3<Vector3> operator+(const Vec3<Vector3> &vector) const
	{
		return Vec3<Vector3>(a + vector.a, b + vector.b, c + vector.c);
	}
	void print();
};

template <class Vector3>
void Vec3<Vector3>::normalize()
{
	Vector3 length;
	length = sqrt((a*a)+(b*b)+(c*c));
	if (length != 0)
	{
		this->a = a / length;
		this->b = b / length;
		this->c = c / length;
	}
	else std::cout << "No se puede normalizar" << std::endl;
}
template <class Vector3>
void Vec3<Vector3>::distanceTo(const Vec3<Vector3> &distVec)
{
	float dist = sqrt((distVec.a - this->a)^2 + (distVec.b - this->b)^2 + (distVec.c - this->c)^2);
	std::cout << dist << std::endl;
}

template <class Vector3>
void Vec3<Vector3>::print()
{
	std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
	Vec3<int> voidVec();
	Vec3<int> firstVec(1, 1, 0);
	Vec3<int> distVec(2, 1, 2);
	Vec3<int> secondVec(firstVec);
	Vec3<float> floatVec(2.0, 2.0, 2.0);
	Vec3<int> sumVec = firstVec + secondVec;
	firstVec.print();
	secondVec.print();
	floatVec.normalize();
	floatVec.print();
	sumVec.print();
	firstVec.distanceTo(distVec);
	std::cin.ignore();
	return 0;
}