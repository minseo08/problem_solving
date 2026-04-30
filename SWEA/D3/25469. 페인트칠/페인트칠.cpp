#include<iostream>
#include<string>
#include<algorithm>
#define INF 987654321

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        int c, r;
        char arr[51][51];
        bool row[51] = {false, false, };
        bool column[51] = {false, false, };
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(arr[i][j] == '#' && !row[i] && j == 0){
                    int tmp_c = j + 1;
                    while(tmp_c < c){
                        if(arr[i][tmp_c] != '#')
                            break;
                        tmp_c++;
                    }
                    if(tmp_c == c)
                        row[i] = true;
                }
                if(arr[i][j] == '#' && !column[j] && i == 0){
                    int tmp_r = i + 1;
                    while(tmp_r < r){
                    	if(arr[tmp_r][j] != '#')
                            break;
                        tmp_r++;
                    }
                    if(tmp_r == r)
                        column[j] = true;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < 51; i++){
            if(row[i])
                sum++;
        }
        for(int i = 0; i < 51; i++){
            if(column[i])
                sum++;
        }
        if(sum == r + c){
            cout << min(r, c) << "\n";
            continue;
        }
        cout << sum << "\n";


	}
	return 0;
}