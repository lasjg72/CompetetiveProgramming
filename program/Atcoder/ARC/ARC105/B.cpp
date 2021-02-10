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
        int a = 0;
        cin >> a;
        st.insert(a);
    }
    int mx = *st.rbegin();
    int mi = *st.begin();
    //cout << "ko" << endl;
    while(mx != mi){
        int tmp = mx - mi;
        st.insert(tmp);
        st.erase(mx);
        mx = *st.rbegin();
        mi = *st.begin();
    }
    cout << mx << endl;
    return 0;
}