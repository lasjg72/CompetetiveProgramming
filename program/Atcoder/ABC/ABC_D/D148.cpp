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
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    int num = 1;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
        if(a[i] == num) num++;
    }
    if(num == 1){
        cout << -1 << endl;
        return 0;
    }
    cout << n-num+1 << endl;    
    return 0;
}