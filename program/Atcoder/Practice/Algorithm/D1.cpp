#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int tmp;
    for(int i = 0; i<n;i++){
        cin >> tmp;
        a[tmp-1]++;
    }

    int b=0, c=0;
    for(int i = 0; i< n; i++){
        if(a[i] == 0) b = i+1;
        if(a[i] == 2) c = i+1;
    }
    if(b == 0 && c == 0) cout << "Correct" << endl;
    else cout << c << " " << b << endl;
    return 0;
}