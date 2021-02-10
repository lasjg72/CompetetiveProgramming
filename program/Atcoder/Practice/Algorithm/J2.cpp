#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;


    int n, m;
    vector<int> bea(n+1, 0);

int binary_search(int key) {
    int left = bea[1], right = bea[n]; // 配列 a の左端と右端
    while (right >= left) {
        int mid = left + (right - left) / 2; 
        if(mid == 0) return -1;// 区間の真ん中
        if( right == 0 || left == 0){
        return -1;
    }
        if (bea[mid] == key) return mid;
        else if (bea[mid] > key) right = mid - 1;
        else if (bea[mid] < key) left = mid + 1;
    }
    
    return -1;
}

int main()
{
    cin >> n >> m;
    vector<int> a(m+1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    
    vector<int> eat(m + 1, 0);

    for (int j = 1; j <= m; j++)
    {
        int pos = binary_search(a[j]);
        bea[pos] = a[j];
        eat[j] = pos;
    }

    for (int i = 1; i <= m; i++)
    {
        cout << eat[i] << endl;
    }
    return 0;
}