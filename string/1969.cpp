#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, cnt;
vector<string> str;
vector<int> sum(4,0);
vector<char> DNA;
string answer = "";
int main(){
    cin >> n >> m;
    DNA.push_back('A');
    DNA.push_back('C');
    DNA.push_back('G');
    DNA.push_back('T');
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }
    for (int i = 0; i < m; i++){
        int Max = 0;
        int maxIdx = 0;
        for (int j = 0; j < n; j++){
            if (str[j][i] == 'A'){
                sum[0]++;
            }
            else if (str[j][i] == 'C'){
                sum[1]++;
            }
            else if (str[j][i] == 'G'){
                sum[2]++;
            }
            else if (str[j][i] == 'T'){
                sum[3]++;
            }
        }
        for (int k = 0; k < 4; k++){ 
            if (Max < sum[k]){
                Max = sum[k];
                maxIdx = k;
            }
            else if (Max == sum[k]){
                continue;
            }
        }
        answer += DNA[maxIdx];
        sum.assign(4,0);
    }
    cout << answer << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(answer[j] != str[i][j]){  
                cnt++;
            }
        }
    }
    cout << cnt;
}