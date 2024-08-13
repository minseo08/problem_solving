#include <iostream>
#include <string>
using namespace std;

int palindrome(int left, int right, string s, bool is_usa) {
    while (left < right) {
        if (s[left] != s[right]) {
            if (is_usa) {
                if (palindrome(left+1, right, s, false) == 0 || palindrome(left, right-1, s, false) == 0) return 1;
            }
            return 2;
        }
        left++; right--;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        cout << palindrome(0, str.size() - 1, str, true) << "\n";
    }
}