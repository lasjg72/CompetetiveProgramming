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
   ll k, n, m;
   cin >> k >> n >> m;
   vector<ll> a(k);
   //ll r = 0;
   for(int i = 0; i < k; i++) {
      cin >> a[i];
      //r = max(r, m*a[i]);
   }
   ll l = 0, r = 1001001001;
   while(r-l > 1){
      ll tar = (l+r)/2;
      ll nl = 0, nr = 0;
      for(int i = 0; i < k; i++){
         nl += ceil(((double)m*(double)a[i]-(double)tar)/(double)n);
         nr += (m*a[i]+tar)/n;
      }
      //cout << "nl: " << nl << " nr: " << nr << " m: " << m << endl;
      if(nl <= m && m <= nr){
         r = tar;
      }else{
         l = tar;
      }
      //cout << r << endl;
   }
   ll tot = 0;
   vector<ll> ans(k);
   for(int i = 0; i < k; i++){
      ans[i] = ceil(((double)m*(double)a[i]-(double)r)/(double)n);
      tot += ans[i];
   }
   //cout << "-- " << endl;
   for(int i = 0; i < k; i++){
      ll tmp = (m*a[i]+r)/n - ans[i];
      if(tmp+tot > m){
         ans[i] += m-tot;
         tot += m-tot;
      }else{
         ans[i] = (m*a[i]+r)/n;
         tot += tmp;
      }
      cout << ans[i] << " ";
   }
   return 0;
}