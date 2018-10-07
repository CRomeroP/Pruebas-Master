#include"String.h"

int main()
{
	String str1("hello");
	String str2(str1);
	String str3 = str1 + str2;
	std::cout << str1 << " " << str1.length() << std::endl;
	std::cout << str2 << " " << str2.length() << std::endl;
	std::cout << str3 << " " << str3.length() << std::endl;
	if (str1 == str2)
		std::cout << "iguales" << std::endl;
	str2.clear();
	std::cout << str2 << " " << str2.length() << std::endl;
	std::cin.ignore();
}