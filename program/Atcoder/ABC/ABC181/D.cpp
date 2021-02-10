#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    map<int, int> num;
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'0';
        num[c]++;
    }
    if(s.size() == 1){
        if(num[8] == 1){
            cout << "Yes" << endl;
            return 0;
        }
    }else if(s.size() == 2){
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                if(num[i] > 0){
                    num[i]--;
                    if(num[j] > 0){
                        num[j]--;
                        if((10 * i + j) % 8 == 0 || (10 * j + i) % 8 == 0){
                            cout << "Yes" << endl;
                            return 0;
                        }else{
                            num[i]++;
                            num[j]++;
                        }
                    }else{
                        num[i]++;
                    }
                }
            }
        }
    }else{
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                for(int k = 1; k < 10; k++){
                    if(num[i] > 0){
                        num[i]--;
                        if(num[j] > 0){
                            num[j]--;
                            if(num[k] > 0){
                                num[k]--;
                                int tmp = 100 * i + 10 * j + k;
                                if(tmp % 2 == 0){
                                    tmp /= 2;
                                    tmp %= 100;
                                    //cout << tmp << endl;
                                    if(tmp % 4 == 0){
                                        //cout << "i: " << i << j << k;
                                        cout << "Yes" << endl;
                                        return 0;
                                    }else{
                                        num[i]++;
                                        num[j]++;
                                        num[k]++;    
                                    }
                                }else{
                                    num[i]++;
                                    num[j]++;
                                    num[k]++;
                                }
                            }else{
                                num[i]++;
                                num[j]++;
                            }
                        }else{
                            num[i]++;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}