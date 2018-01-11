#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++)

int main(void) {
   string s;
   cin >> s;
   bool outputNext = true;
   REP(i, 0, s.size()) {
      int c = s[i];
      if(outputNext) {
         cout << s[i];
         outputNext = false;
      }
      if(c == 45) {
         outputNext = true;
      }
   }
   cout << endl;
   return 0;
}