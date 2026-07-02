#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size() / 2;
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }
    int answer = 0;
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(n == 0){
            break;
        }
        it->second--;
        answer++;
        n--;
    }
    
    return answer;
}