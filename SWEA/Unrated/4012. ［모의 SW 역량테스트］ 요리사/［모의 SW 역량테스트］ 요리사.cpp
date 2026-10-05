/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int arr[17][17];
bool visited[17][17];

int calc(vector<int> a, vector<int> b, int num){
    int t = a.size();
    int sum_a = 0;
    int sum_b = 0;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            if(i == j)
                continue;
            sum_a += arr[a[i]][a[j]];
            sum_b += arr[b[i]][b[j]];
        }
    }
    int result = abs(sum_a - sum_b);
    return result;
}

int func(int num){
    int result = INF;
    vector<int> mask;
    for(int i = 0; i < num/2; i++){
        mask.push_back(0);
    }
    for(int i = num/2; i < num; i++){
        mask.push_back(1);
    }
    do{
        vector<int> vec_a;
        vector<int> vec_b;
        for(int i = 0; i < mask.size(); i++){
            if(mask[i] == 0)
                vec_a.push_back(i);
            else
                vec_b.push_back(i);
        }
        result = min(result, calc(vec_a, vec_b, num));
    }while(next_permutation(mask.begin(), mask.end()));
    return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        cout << "#" << test_case << " " << func(n) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}