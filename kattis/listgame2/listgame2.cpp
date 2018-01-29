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
#define SQRT10_15 31622777
#define SQRT10_15_EXTRA 31722777

#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++)

/* Creates list of primes in [0..upperboud] */
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

int addSum(int n) {
   return ((n * (n+1)) / 2);
}

int dfsFactorize(ll n, ll sum, vi& multiples, int st, int depth) {
   if(sum > n) { return -1;}
   if(sum == n) { 
      return depth;
   }
   int m = -1;
   int maxMul = -1;
   REP(i, st, multiples.size()) {
      int r = dfsFactorize(n, sum * multiples[i], multiples, i + 1, depth + 1);
      if(r != -1 && r > m) {
      	maxMul = multiples[i];
      }
      m = max(m, r);
   }
   /*if(maxMul != -1) {
   	cout << m << ", " << maxMul << endl;
   }*/
   return m;
}
/*
   Mål 1: 2^5 + 3^2 borde bli 2*3*6*8=4
   Mål 2: 2^40 borde bli 2*4*8*16*32*64*128*4096=8
 */
int primeFactorsBfs(ll n) {
   vi factors;
   vi multiple;
   REP(i,1,20) { multiple.push_back(pow(2, i));};
   REP(i,1,10) { multiple.push_back(pow(3, i));};
   REP(i,1,10) { multiple.push_back(pow(5, i));};
   REP(i,1,10) { multiple.push_back(3*2*i);};
   sort(multiple.begin(), multiple.end());
   return dfsFactorize(n, 1, multiple, 0, 0);
}

int main(void) {
   ll x;
   cin >> x;
   vll primes;
   sieve(primes, round(sqrt(x)));
   vll factors = primeFactors(x, primes);
   vll uniqueFactors;
   map<ll, int> nrOfUniques;
   REP(i,0, factors.size()) { 
      int uniques = 1;
      ll fact = factors[i];
      REP(j, 0, factors.size()) {
         if(i != j && fact == factors[j]) {
            uniques++;
         }
      }
      cout << fact << endl;
      nrOfUniques[fact] = uniques;
   }
   //cout << "---- " << endl;
   ll prodOfUniques = 1;
   int notDuplicates = 0;
   for(map<ll,int>::iterator it = nrOfUniques.begin(); it != nrOfUniques.end(); it++) {
      ll fact = it->first;
      int uniques = it->second;
      if(uniques > 1) {
         prodOfUniques *= pow(fact, uniques);
      }
      else {
         notDuplicates++;
      }
   }
   int duplicateFactorized = primeFactorsBfs(prodOfUniques);
   cout << (duplicateFactorized + notDuplicates) << endl;

   return 0;
}