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
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n;i++){
        if(i != 0){
            if(a[i] == a[i-1]) cout << "stay" << endl;
            if(a[i] < a[i-1]) cout << "down " << a[i-1] - a[i] << endl;
            if(a[i] > a[i-1]) cout << "up " << a[i] - a[i-1] << endl;
        }
    }
    return 0;
}