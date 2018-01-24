#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++)
#define TRvi(c, it) \
   for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
   for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
   for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion


/* Creates list of primes in [0..upperboud] */
void sieve(vi& primes, ll upperbound) {
   bitset<1000010> bs;
   bs.reset(); 
   bs.flip();
   bs.set(0, false);
   bs.set(1, false); // 0, 1 is not prime
   for(ll i = 2; i <= upperbound + 1; i++) {
      if(bs.test((size_t)i)) {
         // cross out multiples starting from i*i
         for(ll j = i*i; j <= upperbound + 1; j += i) {
            bs.set((size_t)j, false);
         }
         primes.push_back((int)i);
      }
   }
}

vi primeFactors(int n, vi& primes) {
   vi factors;
   int nrFactors = 0;
   int indx = 0;
   int pf = 2;
   while(n != 1 && (pf * pf <= n)) {
      while(n % pf == 0) {
         n /= pf;
         factors.push_back(pf);
      }
      pf = primes[++indx];
   }
   if(n != 1) {
      factors.push_back(n);
   }
   return factors;
}

int main(void) {
	int x, t;
	cin >> x;
   vi primes;
   sieve(primes, pow(10,6));
   vi factors = primeFactors(x, primes);
   cout << factors.size() << endl;

	return 0;
}

/* 
2^16 = 65536
127*17*59 = 127381
*/