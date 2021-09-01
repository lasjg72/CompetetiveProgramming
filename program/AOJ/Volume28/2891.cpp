#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <stack> 
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> used, finish;
stack<int> st;
//vector<int> cy;
int pos = -1;

void dfs(int x, int p){
    used[x] = true;
    st.push(x);
    for(int to : g[x]){
        if(to == p || finish[to]) continue;
        if(used[to]){
            pos = to;
            return;
        }
        dfs(to, x);
        if(pos != -1) return;
    }
    //cout << "st.pop: " << st.top() << endl;
    st.pop();
    finish[x] = true;
}

// bool bs(int l, int r, int x){
//     while(r-l > 1){
//         int mid = (l+r)/2;
//         if(cy[mid] >= x){
//             r = mid;
//         }else{
//             l = mid;
//         }
//     }
//     if(cy[r] == x) return true;
//     else return false;
// }

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    finish.resize(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    int q;
    cin >> q;
    set<int> cy;
    //cout << "st.size: " << st.size() << endl;
    while(!st.empty()){
        int t = st.top(); st.pop();
        cy.insert(t);
        if(t == pos) break;
    }
    //sort(cy.begin(), cy.end());
    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        int l = -1, r = cy.size()-1;
        //if(bs(l, r, a) && bs(l, r, b)) cout << 2 << endl;
        if(cy.find(a) != cy.end() && cy.find(b) != cy.end()) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
}