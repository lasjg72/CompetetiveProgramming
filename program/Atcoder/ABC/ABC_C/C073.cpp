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
    set<int> st;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(st.find(a) != st.end()){
            st.erase(a);
        }else{
            st.insert(a);
        }
    }
    cout << st.size() << endl;
    
    // int a[1000000001];
    // for(int i = 0; i < n; i++){
    //     int num;
    //     cin >> num;
    //     a[num]++;
    // }
    // int ans = 0;
    // for(int i = 1; i <= 1000000000; i++){
    //     if(a[i]%2) ans++; 
    // }
    //cout << ans << endl;
    return 0;
}