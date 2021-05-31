#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
   int n;
   cin >> n;
   string s, t;
   cin >> s >> t;
   int n0 = 0, n1 = 0;
   for(int i = 0; i < n; i++){
       if(s[i] == '1') n1++;
       else if(s[i] == '0') n0++;

       if(t[i] == '1') n1--;
       else if(t[i] == '0') n0--;
   }
   if(n1 != 0 || n0 != 0){
       cout << -1 << endl;
       return 0;
   }

   int pos1 = -1, pos2 = -1;
   int ans = 0;
   for(int i = 0; i < n; i++){
       if(t[i] == '0' && s[i] != '0'){
           pos2 = i;
           if(pos1 )
       }
   }
   return 0;
}