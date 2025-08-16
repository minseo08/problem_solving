#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define MAX 10000001
using namespace std;
int prime[MAX];
bool visited[11];
vector<string> ans;
int res[11];
int cnt;

void init(){
    for(int i = 0; i < 11; i++)
        visited[i] = false;
}

void dfs(string &num, int index, int k){
    if(k == cnt){
        string tmp;
        for(int i = 0; i < cnt; i++)
            tmp += res[i];
        ans.push_back(tmp);
        return;
    }
    for(int i = 0; i < num.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            res[k] = num[i];
            dfs(num, i, k + 1);
            visited[i] = false;
        }
    }
}

bool isprime(int num){
    int cnt = 0;
    for(int i = 2; i <= num; i++){
        for(int j = i; j <= num; j += i){
            prime[j]++;
        }
    }
    if(prime[num] == 1)
        return true;
    else{
        return false;
    }
}

int solution(string numbers) {
    set<int> s;
    
    for(int i = 1; i <= numbers.size(); i++){
        cnt = i;
        dfs(numbers, 0, 0);
        init();
    }
    for(int i = 0; i < ans.size(); i++)
        s.insert(stoi(ans[i]));
    
    set<int>::iterator it;
    int answer = 0;
    for(it = s.begin(); it != s.end(); it++){
        answer += isprime(*it);
    }
    return answer;
}