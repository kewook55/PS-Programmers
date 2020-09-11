#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int ans = 0;
    int adj[27][27];
    
    memset(adj, 0, sizeof adj);
    
    for(int i = strlen(skill) - 1; i >=  0; i--){
        for(int j = i - 1; j >= 0; j--){
            adj[skill[i]- 'A'][skill[j] - 'A'] = 1;
        }
    }
   
    for(int i = 0;i < skill_trees_len;i++){
        int check[26];
        int flag = 0;
        memset(check, 0, sizeof check);
        
        for(int j = 0;j < strlen(skill_trees[i]);j++){
            check[skill_trees[i][j] - 'A'] = true;
            for(int k = j+1; k < strlen(skill_trees[i]);k++){
                if(adj[skill_trees[i][j] - 'A'][skill_trees[i][k] - 'A']){
                    flag = 1;
                    break;
                }
            }
            if(flag)break;            
            for(int k = 0; k < 26; k++){
                if(!check[k] && adj[skill_trees[i][j] - 'A'][k]){
                    flag = 1;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)++ans;
    }
    
    return ans;
}