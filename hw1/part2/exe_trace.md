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
