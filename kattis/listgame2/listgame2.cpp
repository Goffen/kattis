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

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

/* Creates list of primes in [0..upperboud] */
void sieve(vll& primes, ll upperbound) {
	bitset<10000010> bs;
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

int main(void) {
	ll x;
	cin >> x;
	vll primes;
	sieve(primes, pow(10,7));
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
		nrOfUniques[fact] = uniques;
	}
	for(map<ll,int>::iterator it = nrOfUniques.begin(); it != nrOfUniques.end(); it++) {
		ll fact = it->first;
		int uniques = it->second;
		
		if(uniques > 1) {
			int pows = 1;
			int nrOfFactSums = 0;
			while(uniques - nrOfFactSums > 0) {
				nrOfFactSums = addSum(++pows);
			}
			/*cout << "uniques: " << uniques << endl;
			cout << "nrOfFactSums: " << nrOfFactSums << endl;
			cout << "pows: " << pows << endl;
			cout << "fact: " << fact << endl;*/
			if(uniques - nrOfFactSums < 0) {
				int powToMany = uniques - addSum(pows - 2);
				REP(k, 1, pows - 1) {
					uniqueFactors.push_back(pow(fact, k));
				}
				uniqueFactors.push_back(pow(fact, powToMany));
			}
			else if(uniques - nrOfFactSums == 0) {
				REP(k, 1, pows+1) {
					uniqueFactors.push_back(pow(fact, k));
				}
			}
		}
		else {
			uniqueFactors.push_back(fact);
		}
	}

	REP(i, 0, uniqueFactors.size()) {
		cout << uniqueFactors[i] << endl;
	}
	
	//cout << uniqueFactors.size() << endl;

	return 0;
}

/*

2^40 -> 1099511627776

2^5 * 2^2 * 2^3 * 2^4

*/