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
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        h = h-a[i];
    }
    if(h <=0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}