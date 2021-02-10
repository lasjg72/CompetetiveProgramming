#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char start = '1';
    char end = '2';
    vector<int> tmp;
    for(int i = 0; i < s.size(); i++){
        if(start=='1'){
            if(s[i]>= 'A' && s[i] <= 'Z'){
                start = s[i];
                tmp.push_back(i);
            }
        }else if(end=='2'){
            if(s[i]>= 'A' && s[i] <= 'Z'){
                start = '1';
            }
        }
    }
    vector<string> word(tmp.size());
    int pos = 0;
    for(int i = 0; i< tmp.size()-1; i++){
        
        int word_size = tmp[i+1]-tmp[i];
        word[i] = s.substr(pos, word_size);
        pos = pos + word_size;
    }
    word[tmp.size()-1] = s.substr(pos, s.size()-pos);   //最後の文字列だけ別処理
    
     for(int i = 0; i< word.size(); i++){
         int size = word[i].size();
         word[i][0] = tolower(word[i][0]);
         word[i][size-1] = tolower(word[i][size-1]);
     }
    
    sort(word.begin(), word.end());
    
    for(int i = 0; i< word.size(); i++){
         int size = word[i].size();
         word[i][0] = toupper(word[i][0]);
         word[i][size-1] = toupper(word[i][size-1]);
     }
    
    string ans = word[0];
    for(int i = 1; i < word.size(); i++){
        ans.append(word[i]);
    }
    cout << ans << endl;
    return 0;
}