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
    ll k;
    string s, t;
    cin >> k >> s >> t;
    ll T = 0, A = 0;
    map<int, int> numT, numA, num;
    for(int i = 0; i < 4; i++){
        numT[s[i]-'0']++;
        numA[t[i]-'0']++;
        num[s[i]-'0']++;
        num[t[i]-'0']++;
    }
    ll v = 0;
    ll card = (9*k-8)*(9*k-9);
    //cout << card << endl;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            num[i]++;
            num[j]++;
            if(num[i] > k || num[j] > k){
                num[i]--;
                num[j]--;
                continue;
            }
            //cout << i << "ij" << j << endl;
            
            numT[i]++;
            numA[j]++;
            for(int p = 1; p < 10; p++){
                T += p*pow(10, numT[p]);
                A += p*pow(10, numA[p]);
            } 
            if(T > A) {
                num[i]--;
                num[j]--;
                //cout << "TA" << T << "* " << A << endl;
                ll q = 0, w = 0;
                q = (k-num[i]);
                num[i]++;
                w = (k-num[j]);
                num[j]++;
                v += q*w;
                //cout << "vic" << endl;
            }
            numT[i]--;
            numA[j]--;
            num[i]--;
            num[j]--;
            T = 0;
            A = 0;
        }
    }
    //cout << v << ": " << card << endl;
    long double ans = (long double) v / (long double)card;
    cout << ans << endl;
    return 0;
}