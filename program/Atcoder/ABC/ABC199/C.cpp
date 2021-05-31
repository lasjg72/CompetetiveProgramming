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
    int n, q;
    string s;
    
    cin >> n >> s >> q;
    string t1(n, 'a'), t2(n, 'a');
    for(int i = 0; i < n; i++){
        t1[i] = s[i];
    }
    for(int i = 0; i< n; i++){
        t2[i] = s[i+n];
    }
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            a--; b--;
            if(a >= n) {
                a -= n;
                b -= n;
                char tmp = t2[a];
                t2[a] = t2[b];
                t2[b] = tmp;    
            }else if(b >= n){
                b -= n;
                char tmp = t1[a];
                t1[a] = t2[b];
                t2[b] = tmp;
            }else{
                char tmp = t1[a];
                t1[a] = t1[b];
                t1[b] = tmp;
            }
        }else{
            swap(t1, t2);
        }
        //cout << t1+t2 << endl;
    }
    cout << t1+t2 << endl;
    return 0;
}