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
    vector<int> v(n);
    vector<int> num1, num2;
    int max1 = 0, max2 =0;
    for(int i = 0 ; i < n;i++){
        cin >> v[i];
        if(i%2==0){
            num1.push_back(v[i]);
        }else{

        }
    }
    return 0;
}