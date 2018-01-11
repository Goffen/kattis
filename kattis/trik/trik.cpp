#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++)

int main(void) {
   string s;
   cin >> s;
   int ballAt = 1;

   int swaps[3][2] = {{1,2},{2,3},{3,1}};
   REP(i, 0, s.size()) {
      int swapIndex = s[i] - 65;
      int c1 = swaps[swapIndex][0];
      int c2 = swaps[swapIndex][1];
      if(ballAt == c1) {
         ballAt = c2;
      }
      else if(ballAt == c2) {
         ballAt = c1;
      }
   }
   cout << ballAt << endl;
   return 0;
}