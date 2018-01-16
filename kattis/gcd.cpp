#include <iostream>
#include <math.h>
using namespace std;

/*
	Solves: x*p + y*q = gcd(p,q)

	i.e.  Linear Diophantine Equation

Suppose a housewife buys apples and oranges at a total cost of 8.39 SGD. 
If an apple is 25 cents and an orange is 18 cents, how many of each type of fruit does she buys?

 */
long gcd(long p, long q, long *x, long *y) {
	long x1, y1;
	long g;
	if(q > p) return gcd(q,p,y,x);
	if(q == 0) {
		*x = 1;
		*y = 0;
		return p;
	}
	g = gcd(q, p%q, &x1, &y1);
	*x = y1;
	*y = (x1-floor(p/q)*y1);
	return g;
}

int main(void) {
	long p, q, x, y;
	
	long r = gcd(34398, 2132, &x, &y);
	cout << "gcd: " << r << ". x: " << x << ", y: " << y << endl;
	return 0;
}

/* 

20^2 = 400

3 20
0 2
2 0
2 1

x*p + y*q = gcd(p,q)

*/