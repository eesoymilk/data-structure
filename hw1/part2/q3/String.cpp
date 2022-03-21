#include "String.h"

// Constructor that initializes *this to string init of length m.
String::String(char *init, int m)
{
	int l;
	for (l = 0; init[l] != '\0' && l < m; l++) ;
	str = new char[l + 1];
	for (int i = 0; i < l; i++) str[i] = init[i];
	str[l] = '\0';
}

// Destructor for String.
String::String(char *init, int m)
{
	delete[] str;
}

// If the string represented by *this equals t, return true;
// else return false.
bool String::operator==(const String& t)
{
	const int l = this->Length();
	if (t.Length() != l)
		return false;
	for (int i = 0; i < l; i++)
		if (this->str[i] != t.str[i])
			return false;
	return true;
}

// If *this is empty then return true; else return false.
bool String::operator!()
{
	if (str == nullptr || this->Length() == 0) return true;
	return false;
}

// Return the number of characters in *this.
int String::Length() const
{
	if (str == nullptr) return 0;

	int l;
	for (l = 0; str[l] != '\0'; l++) ;
	return l;
}

// Return a string whose elements are those of *this followed by those of t.
String String::Concat(String t)
{
	int i = 0, l1 = this->Length(), l2 = t.Length();
	char *buf = new char[l1 + l2 + 1];
	for ( ; i < l1; i++) buf[i] = str[i];
	for ( ; i < l1 + l2; i++) buf[i] = t.str[i - l1];
	buf[i] = '\0';
	String concatStr(buf, l1 + l2);
	delete[] buf;
	return concatStr;
}

// Return a string containing the j characters of *this at position i,
// i + 1, ..., i + j - 1 if those are valid position of *this; otherwise,
// throw and exception.
String String::Substr(const int i, const int j)
{
	if (i + j > this->Length()) throw "invalid substring.";

	char *buf = new char[j + 1];
	for (int idx = i; idx < j; idx++) buf[idx - i] = str[idx];
	buf[j] = '\0';
	String subStr(buf, j);
	delete[] buf;
	return subStr;
}

// Return an index i such that pat matches the substring of *this that
// begins at position i. Return -1 if pat is either empty of not a
// substring of *this.
// This function is implemented by FastFind.
int String::Find(String pat)
{

}

// Return a new string that is equivalent to *this, except that "length"
// characters beginning at "start" have been removed.
String String::Delete(int start, int length)
{
	String delStr = this->Substr(0, start);
	if (start + length < this->Length()) {
		int i = start + length, j = this->Length() - i;
		delStr.Concat(this->Substr(i, j));
	}
	return delStr;
}

// Return the string with all occurrence of c removed.
String String::CharDelete(char c)
{
	char *buf = new char[this->Length() + 1];
	int i = 0, idx = 0, l = this->Length();
	for ( ; i < l; i++) if (str[i] != c) buf[idx++] = str[i];
	buf[idx++] = '\0';
	String charDelStr(buf, idx);
	delete[] buf;
}

// If *this = x = (x_0, x_1, ..., x_m-1), and y = (y_0, y_1, ..., y_n-1)
// are strings, where x_i and y_i are letters of the alphabet, then x < y
// if x_i = y_i for 0 <= i < j and x_j < y_j or if x_i = y_i for
// 0 <= i <= m and m < n.
// Compare two strings with the rule above and return either -1, 0, or +1
// if x < y, x == y, or x > y, respectively.
int String::Compare(String y)
{
	int m = this->Length(), n = y.Length();
}

// input function
std::istream &operator>>(std::istream &in, String &s)
{
	return in;
}

// output function
std::ostream &operator<<(std::ostream &out, String &s)
{
	return out;
}