#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int num = 0;
    while(n >= k){
        n = n/k;
        num++;
    }
    cout << num+1 << endl;
    return 0;
}