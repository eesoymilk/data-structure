#include "String.h"

// Constructor that initializes *this to string init of length m.
String::String(char *init, int m)
{
	int l;
	for (l = 0; init[l] != '\0' && l < m; l++) ;
	str = new char[l + 1];
	for (int i = 0; i < l; i++) str[i] = init[i];
	str[l] = '\0';
	f = new int[l];
	FailureFunction();
}

// Destructor for String.
String::~String()
{
	delete[] str;
}

// Compute the failure function for the pattern *this
void String::FailureFunction()
{
	int l = Length();
	f[0] = -1;
	for (int j = 1; j < l; j++) {
		int i = f[j - 1];
		while (i >= 0 && (str[j] != str[i + 1])) i = f[i];
		if (str[j] == str[i + 1]) f[j] = f[j - 1] + 1;
		else f[j] = -1;
	}
}

// If the string represented by *this equals t, return true;
// else return false.
bool String::operator==(const String& t)
{
	const int l = Length();
	if (t.Length() != l)
		return false;
	for (int i = 0; i < l; i++)
		if (str[i] != t.str[i])
			return false;
	return true;
}

// If *this is empty then return true; else return false.
bool String::operator!()
{
	if (str == nullptr || Length() == 0) return true;
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
String String::Concat(const String& t)
{
	int i = 0, l1 = Length(), l2 = t.Length();
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
	if (i + j > Length()) throw "invalid substring.";

	char *buf = new char[j + 1];
	for (int idx = i; idx < i + j; idx++) buf[idx - i] = str[idx];
	buf[j] = '\0';
	String subStr(buf, j);
	delete[] buf;
	return subStr;
}

// Return an index i such that pat matches the substring of *this that
// begins at position i. Return -1 if pat is either empty of not a
// substring of *this.
// This function is implemented by FastFind.
int String::FastFind(String pat)
{
	int pat_idx = 0, str_idx = 0, pat_length = pat.Length(), str_length = Length();
	while ((pat_idx < pat_length) && (str_idx < str_length)) {
		if (pat.str[pat_idx] == str[str_idx]) {
			pat_idx++;
			str_idx++;
		} else {
			if (pat_idx == 0) str_idx++;
			else pat_idx = pat.f[pat_idx - 1] + 1;
		}
	}
	if (pat_idx < pat_length) return -1;
	return str_idx - pat_length;
}

// Return a new string that is equivalent to *this, except that "length"
// characters beginning at "start" have been removed.
String String::Delete(int start, int length)
{
	String delStr = Substr(0, start);
	if (start + length < Length()) {
		int i = start + length, j = Length() - i;
		return delStr.Concat(Substr(i, j));
	}
	return delStr;
}

// Return the string with all occurrence of c removed.
String String::CharDelete(char c)
{
	int idx = 0, l = Length();
	char *buf = new char[l + 1];
	for (int i = 0; i < l; i++) if (str[i] != c) buf[idx++] = str[i];
	buf[idx] = '\0';
	String charDelStr(buf, idx);
	delete[] buf;
	return charDelStr;
}

// If *this = x = (x_0, x_1, ..., x_m-1), and y = (y_0, y_1, ..., y_n-1)
// are strings, where x_i and y_i are letters of the alphabet, then x < y
// then x < y if x_i = y_i for 0 <= i < j and x_j < y_j
// or if x_i = y_i for 0 <= i <= m and m < n.
// Compare two strings with the rule above and return either -1, 0, or +1
// if x < y, x == y, or x > y, respectively.
int String::Compare(String y)
{
	int m = Length(), n = y.Length(), i;
	for (i = 0; i < m && i < n; i++) {
		if (str[i] > y.str[i]) return 1;
		if (str[i] < y.str[i]) return -1;
	}
	if (m > n) return 1;
	if (m < n) return -1;
	return 0;
}

// input function
std::istream &operator>>(std::istream &in, String &s)
{
	char buf[1000];
	in >> buf;
	// std::cout << "buf: " << buf << '\n';
	s = String(buf, 1000);
	return in;
}

// output function
std::ostream &operator<<(std::ostream &out, const String &s)
{
	out << s.str;
	return out;
}