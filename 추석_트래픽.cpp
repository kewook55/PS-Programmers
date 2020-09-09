#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int ans = 1;
    vector<int> start, end;
    
    for(int i = 0;i < lines.size();i++){
        int e = 0, t = 0;
        
        e += (stoi(lines[i].substr(11,2)) * 3600 *1000);
        e += (stoi(lines[i].substr(14,2)) * 60 * 1000);
        e += (stoi(lines[i].substr(17,2)) * 1000);
        e += (stoi(lines[i].substr(20,3)));

        double time = stod(lines[i].substr(24, lines[i].size() - 25));
        t = (int)(time*1000);
        start.push_back(e-t+1);
        end.push_back(e);
    }
    
    for(int i = 0;i < lines.size();i++){
        int cnt = 1;
        for(int j = i + 1;j < lines.size();j++)if(end[i] + 999 >= start[j])++cnt;
        ans = max(ans, cnt);
    }

    return ans;
}