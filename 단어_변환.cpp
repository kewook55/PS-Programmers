#include <string>
#include <vector>

using namespace std;

int ans = 100;
bool check[51];

void dfs(int cnt, string str, string begin, string target, vector<string> words){
    if(str == target){
        ans = ans > cnt ? cnt : ans;
        return;
    }
    
    for(int i = 0;i < words.size();i++){
        if(check[i])continue;
        
        int diff = 0;
        for(int j = 0;j<begin.size();j++)if(str[j] != words[i][j])diff++;
        
        if(diff == 1){
            check[i] = true;
            dfs(cnt+1, words[i], begin, target, words);
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(0, begin, begin, target, words);
    if(ans == 100)return 0;
    else return ans;
}

///python3 코드///
/*

ans = 100
check = []

def init(words) :
    for i in range(len(words)):
        check.append(0)

def dfs(cnt, hist, begin, target, words) :
    global ans
    if(hist == target):
        if(ans > cnt) :
            ans = cnt
        return
    
    for i in range(len(words)):
        if(check[i]) :
            continue
            
        diff = 0
        for j in range(len(hist)):
            if(hist[j] != words[i][j]):
                diff+=1
        
        if(diff == 1):
            check[i] = 1
            dfs(cnt+1, words[i], begin, target, words)
            check[i] = 0
    
def solution(begin, target, words):
    init(words)
    dfs(0, begin, begin, target, words)
    
    if(ans == 100):
        return 0
    else :
        return ans
    return answer
*/