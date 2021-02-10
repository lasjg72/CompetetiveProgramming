#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    map<int, int> num;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b(n);
    b = a;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i]-d < a[0]){
            num[a[i]] = 0;
            continue;
        }
        int itr = upper_bound(a.begin(), a.end(), a[i]-d)-a.begin();
        num[a[i]] = itr;
    }
    for(int i = 0; i < n; i++){
        cout << num[b[i]] << endl; 
    }
    return 0;
}