#include<iostream>
#include<math.h>

template <class Vector3>
class Vec3 {
	Vector3 x, y, z;
public:
	Vec3()
	{
		x = y = z = 0;
	}
	Vec3(Vector3 first, Vector3 second, Vector3 third)
	{
		x = first; y = second; z = third;
	}
	/*Vec3(Vector3 copy)
	{
		a = copy.a; b = copy.b; c = copy.c;
	}*/

	void normalize();
	void distanceTo(const Vec3<Vector3> &distVec);
	Vec3<Vector3> operator+(const Vec3<Vector3> &vector) const
	{
		return Vec3<Vector3>(x + vector.x, y + vector.y, z + vector.z);
	}
	void print();
};

template <class Vector3>
void Vec3<Vector3>::normalize()
{
	Vector3 length;
	length = sqrt((x*x)+(y*y)+(z*z));
	if (length != 0)
	{
		x = x / length;
		y = y / length;
		z = z / length;
	}
	else std::cout << "No se puede normalizar" << std::endl;
}
template <class Vector3>
void Vec3<Vector3>::distanceTo(const Vec3<Vector3> &distVec)
{
	float dist = sqrt((distVec.x - x)^2 + (distVec.y - y)^2 + (distVec.z - z)^2);
	std::cout << dist << std::endl;
}

template <class Vector3>
void Vec3<Vector3>::print()
{
	std::cout << "(" << x << " " << y << " " << z << ")" << std::endl;
}

int main() {
	Vec3<int> voidVec();
	Vec3<int> firstVec(1, 1, 0);
	Vec3<int> distVec(2, 1, 2);
	Vec3<int> secondVec(firstVec);
	Vec3<float> floatVec(2.0, 2.0, 2.0);
	Vec3<int> sumVec = firstVec + secondVec;
	std::cout << "Vec3<int> firstVec(1,1,0) -> ";
	firstVec.print();
	std::cout << "Vec3<int> secondVec(firstVec) -> ";
	secondVec.print();
	std::cout << "Vec3<float> floatVec(2.0,2.0,2.0) Normalizado -> ";
	floatVec.normalize();
	floatVec.print();
	std::cout << "Vec3<int> sumVec = firstVec + secondVec -> ";
	sumVec.print();
	std::cout << "Distancia entre vector (1,1,0) y vector (2,1,2) -> ";
	firstVec.distanceTo(distVec);
	std::cin.ignore();
	return 0;
}