#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define INF 10000000
#define SQRT10_15 31622777
#define SQRT10_15_EXTRA 31722777

#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++)

void sieve(vll& primes, ll upperbound) {
   bitset<SQRT10_15_EXTRA> bs;
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
         primes.push_back((ll)i);
      }
   }
}

vll primeFactors(ll n, vll& primes) {
   vll factors;
   int nrFactors = 0;
   int indx = 0;
   ll pf = 2;

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
bool contains(vi& p, int f) {
   REP(i, 0, p.size()) {
      if(p[i] == f) {
         return true;
      }
   }
   return false;
}

vi distinctify(vll& a) {
	vector<bool> used;
	int aLength = a.size();
	int unused = aLength;
	REP(i, 0, aLength) { used.push_back(false);}
	vi facts;
	while(unused != 0) {
		ll minFact = INF;
		vi indxUsed;
		REP(nrOfMuls, 1, aLength + 1) {
			REP(j, 0, aLength - nrOfMuls) {
				ll mul = 1;
				int mulC = 0;
				vi is;
				for(int k=j; mulC < nrOfMuls; k++) {
					if(k == aLength || mul > minFact) break;
					if(used[k]) continue;
					mul *= a[k];
					is.push_back(k);
					//cout << k << "," << j << "," << mulC << "," << mul << endl;
					mulC++;
				}
				if(is.size() == nrOfMuls && mul < minFact && !contains(facts, mul)) {
					minFact = mul;
					indxUsed = is;
				}
			}
		}
		if(minFact == INF) {
			vi indexOfUsed;
			REP(i, 0, used.size()) {
				if(!used[i]) {
					facts[facts.size() - 1] *= a[i];
				}
			}
			break;
		}
		else {
			facts.push_back(minFact);
			REP(i,0,indxUsed.size()) {
				used[indxUsed[i]] = true;
				unused--;
			}
		}
	}
	return facts;
}

/*
   Mål 1: 2^5 + 3^2 borde bli 2*3*6*8=4
   Mål 2: 2^40 borde bli 2*4*8*16*32*64*128*4096=8
 */
int main(void) {
   ll x;
   cin >> x;
   vll primes;
   sieve(primes, round(sqrt(x)));
   vll factors = primeFactors(x, primes);
   //REP(i,0,factors.size()) { cout << factors[i] << endl;}
   //cout << "---" << endl;
   vi facts = distinctify(factors);
   //REP(i,0,facts.size()) { cout << facts[i] << endl;}
   cout << facts.size() << endl;
   return 0;
}