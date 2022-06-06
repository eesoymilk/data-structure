> g++ -std=c++2a .\main.cpp .\Polynomial.cpp -o main
> .\main.exe
> p1: x+1
> p2: 3x^2+2x+7
> Now, p3 = p1 + p2, p4 = p1 _ p2.
> p3: 3x^2 + 3x + 8
> p4(6.9) = 1292.68
> .\main.exe
> Enter two polynomials p1 and p2,
> p1: 5x+8
> p2: 10x^2+4x+1
> Now, p3 = p1 + p2, p4 = p1 _ p2.
> p3: 10x^2 + 9x + 9
> p4: 50x^3 + 100x^2 + 37x + 8
> Finally, let's evaluate p4(x) at x = 1
> p4(1) = 195

> g++ -std=c++2a .\main.cpp .\SparseMatrix.cpp -o main
> .\main.exe
> Enter two sparse matrice sm1 and sm2 with the same dimension
> sm1:
> Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
> 3 2 3
> Now, enter each term's row, col, and value: (seperating them whith a white space)
> #1: 0 0 7
> #2: 1 1 6
> #3: 2 0 9
> sm2:
> Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
> 3 2 2
> Now, enter each term's row, col, and value: (seperating them whith a white space)
> #1: 0 0 6
> #2: 1 0 1

Enter one sparse matrice sm3 with the same rows as sm1's columns
sm3:
Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
2 3 2
Now, enter each term's row, col, and value: (seperating them whith a white space)
#1: 0 0 2
#2: 0 2 4

Now, sm4 = sm1 + sm2, sm5 = sm1 \* sm3.
sm4:
#1: (0, 0, 13)
#2: (1, 0, 1)
#3: (1, 1, 6)
#4: (2, 0, 9)
sm5:
#1: (0, 0, 14)
#2: (2, 0, 36)

Finally, let's transpose sm5.
sm5^T:
#1: (0, 0, 14)
#2: (0, 2, 36)

> g++ -std=c++2a .\main.cpp .\SparseMatrix.cpp -o main
> .\main.exe
> Enter two sparse matrice sm1 and sm2 with the same dimension
> sm1:
> Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
> 4 5 6
> Now, enter each term's row, col, and value: (seperating them whith a white space)
> #1: 0 0 7
> #2: 0 4 3
> #3: 1 2 3
> #4: 1 3 5
> #5: 2 4 6
> #6: 3 4 5
> sm2:
> Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
> 4 5 3
> Now, enter each term's row, col, and value: (seperating them whith a white space)
> #1: 0 3 4
> #2: 1 3 7
> #3: 2 3 4

Enter one sparse matrice sm3 with the same rows as sm1's columns
sm3:
Enter the number of rows, cols, and terms in the sparse matrix in sequence: (seperating them whith a white space)
5 3
4
Now, enter each term's row, col, and value: (seperating them whith a white space)
#1: 1 1 3
#2: 2 2 5
#3: 3 0 1
#4: 4 2 4

Now, sm4 = sm1 + sm2, sm5 = sm1 \* sm3.
sm4:
#1: (0, 0, 7)
#2: (0, 3, 4)
#3: (0, 4, 3)
#4: (1, 2, 3)
#5: (1, 3, 12)
#6: (2, 3, 4)
#7: (2, 4, 6)
#8: (3, 4, 5)
sm5:
#1: (2, 0, 24)

Finally, let's transpose sm5.
sm5^T:
#1: (0, 2, 24)

> g++ -std=c++2a .\main.cpp .\String.cpp -o main
> .\main.exe
> Enter 4 arbitrary strings
> s1: hello
> s2: contradiction
> s3: hello
> s4: specifically
> String::operator==
> s1 == s3: 1
> String::operator!
> !s1: 0
> String::Length():
> s1.Length() = 5
> s2.Length() = 13
> String::Concat():
> s1.Concat(s2) = hellocontradiction
> s3.Concat(s4) = hellospecifically

Enter a string pat to test FastFind
pat: ll
s3.FastFind(pat) = 2
s4.FastFind(pat) = 9

Enter a 2 integer start and l to test Delete
start: 1 5
l: s1.Delete(start, l) = h
s2.Delete(start, l) = cdiction

Enter a char c and test CharDelete
c: l
s3.CharDelete(c) = heo
s4.CharDelete(c) = specificay
