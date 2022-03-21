#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
private:
	char *str = nullptr;
public:
    // Constructor that initializes *this to string init of length m.
    String(char *init, int m);

    // If the string represented by *this equals t, return true;
	// else return false.
    bool operator==(const String& t);

	// If *this is empty then return true; else return false.
    bool operator!();

	// Return the number of characters in *this.
    int Length() const;

	// Return a string whose elements are those of *this followed by those of t.
    String Concat(const String t);

    // Return a string containing the j characters of *this at position i,
	// i + 1, ..., i + j - 1 if those are valid position of *this; otherwise,
	// throw and exception.
    String Substr(const int i, const int j);

	// Return an index i such that pat matches the substring of *this that
	// begins at position i. Return -1 if pat is either empty of not a
	// substring of *this.
	// This function is implemented by FastFind.
    int Find(String pat);

	// Return a new string that is equivalent to *this, except that "length"
	// characters beginning at "start" have been removed.
	String Delete(int start, int length);

	// Return the string with all occurrence of c removed.
	String CharDelete(char c);

	// If *this = x = (x_0, x_1, ..., x_m-1), and y = (y_0, y_1, ..., y_n-1)
	// are strings, where x_i and y_i are letters of the alphabet, then x < y
	// if x_i = y_i for 0 <= i < j and x_j < y_j or if x_i = y_i for
	// 0 <= i <= m and m < n.
	// Compare two strings with the rule above and return either -1, 0, or +1
	// if x < y, x == y, or x > y, respectively.
	int Compare(String y);

	// input function
	friend std::istream &operator>>(std::istream &in, String &s);

	// output function
	friend std::ostream &operator<<(std::ostream &out, String &s);
};

#endif
