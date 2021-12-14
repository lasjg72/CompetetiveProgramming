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
    int l, q;
    cin >> l >> q;
    set<int> st;
    st.insert(0);
    st.insert(l);
    while(q--){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            st.insert(x);
        }else{
            auto pos = st.lower_bound(x);
            int num = *(pos--)-*pos;
            cout << num << endl;
        }
    }
    return 0;
}