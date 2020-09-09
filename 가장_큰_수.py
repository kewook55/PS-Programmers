from functools import cmp_to_key

def compare(str1, str2) :
    a = (int)(str1 + str2)
    b = (int)(str2 + str1)
    
    if a > b :
        return 1
    elif a < b :
        return -1
    else :
        return 0

def solution(num):
    ans = ''
    ans = list(map(str, num))
    
    ans = sorted(ans, key = cmp_to_key(compare), reverse = True)
    #0이 연속으로 붙어있는 경우가 생길 수 있으니 integer로 한번 변경해주자
    ans = str(int("".join(ans)))
    return ans


###### c++ code ######

"""
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string str1, string str2){
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    string ans = "";
    
    vector<string> str;
    for(auto num : numbers)str.push_back(to_string(num));
    sort(str.begin(), str.end(), cmp);
    
    if(str[0] == "0")return "0";
    else {
        for(auto s : str)ans += s;
        return ans;
    }
}
"""