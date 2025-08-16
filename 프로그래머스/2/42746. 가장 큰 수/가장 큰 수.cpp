#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    if(a.size() == b.size())
        return a > b;
    else{
        string tmp_a = a;
        string tmp_b = b;
        return tmp_a + b > tmp_b + a;
    }
}

string solution(vector<int> numbers) {
    vector<string> strings;
    for(int i = 0; i < numbers.size(); i++){
        string a = to_string(numbers[i]);
        strings.push_back(a);
    }
    sort(strings.begin(), strings.end(), compare);

    string tmp = "";
    bool flag = false;
    for(int i = 0; i < strings.size(); i++){
        if(stoi(strings[i]))
            flag = true;
        if(flag)
            tmp += strings[i];
    }
    if(!flag)
        return "0";
    return tmp;
}