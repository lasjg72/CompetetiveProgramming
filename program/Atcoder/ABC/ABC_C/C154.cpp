#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> a;
    int tmp = 0;
    bool flag = false;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        a[tmp]++;
        if(a[tmp] != 1) flag = true;
    }

    if(flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}