#include<iostream>

class String
{
private:
	char* word;
	int size;
public:
	String();
	String(const char* str);
	~String();
	int length() const;
	void clear();
	friend std::ostream& operator<< (std::ostream& so, const String& s);
	friend std::istream& operator>> (std::istream& so, String& s);
	String operator+ (const String& rhs);
	friend bool operator== (const String& lhs, const String& rhs);
	char  operator[] (int j) const;
	char& operator[] (int j);
};
