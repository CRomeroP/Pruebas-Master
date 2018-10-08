#include "String.h"

String::String()
{
	word = new char[0];
	size = 0;
}

String::String(const char * str)
{
	if (str)
	{
		unsigned n = 0;
		while (str[n] != '\0') n++;
		size = n;
		word = new char[n];
		for (unsigned j = 0; j < n; j++)
			word[j] = str[j];
	}
	else
	{
		size = 0;
		word = new char[0];
	}
}

String::~String()
{
}

int String::length() const
{
	return size;
}

void String::clear()
{
	size = 0;
	word = nullptr;
}

std::ostream& operator<< (std::ostream& os, const String& str)
{
	if (str.length() > 0)
	{
		for (int j = 0; j < str.length(); j++)
			os << str[j];
	}
	else os << "";

	return os;
}

std::istream& operator>> (std::istream& is, String& str)
{
	char* c = new char[1000];
	is >> c;
	str = String(c);
	delete[] c;

	return is;
}

String String::operator+ (const String& rhs)
{
	int length = size + rhs.length();
	std::cout << length << std::endl;
	char* aux = new char;
	std::cout << *aux << std::endl;

	for (int j = 0; j < size; ++j)
	{
		std::cout << j << " " << word[j] << std::endl;
		aux[j] = word[j];
	}
	std::cout << *aux << std::endl;
	for (int i = 0; i < rhs.length(); ++i)
		aux[size + i] = rhs[i];
	std::cout << *aux << std::endl;
	String retVal(aux);

	return retVal;
}

bool operator== (const String& lhs, const String& rhs)
{
	if (lhs.length() != rhs.length()) return false;

	int cap = lhs.length();
	int   n = 0;
	while ((n < cap) && (lhs[n] == rhs[n])) n++;
	return (n == cap);
}

char String::operator[] (int j) const
{
	if (j >= size) throw 1;
	return word[j];
}

char& String::operator[] (int j)
{
	if (j >= size) throw 1;
	return word[j];
}
