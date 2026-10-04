#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    map<int, int> mp;
    elements.insert(elements.end(), elements.begin(), elements.end());
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = j; k <= j + i - 1; k++){
                sum += elements[k];
            }
            mp[sum]++;
            //j부터 i개의 합
        }
    }
    //1 : 0 1 2 ... n-1
    //2 : 01 12 ... n-2n-1 0n-1
    //3 : 012 123 ... n-3n-2n-1 0n-2n-1 01n-1
    //4 : 0123 1234 ... n-4n-3n-2n-1 0n-3n-2n-1 01n-2n-1 012n-1
    // ...
    //n : 0123...n
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
        answer++;
    
    return answer;
}