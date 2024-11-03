#include <iostream>
using namespace std;
pair<char, char> tree[30];

void preorder(char cur){
    if(cur == '.')
        return;
    cout << cur;
    preorder(tree[cur - 'A'].first);
    preorder(tree[cur - 'A'].second);
}
void inorder(char cur){
    if(cur == '.')
        return;
    inorder(tree[cur - 'A'].first);
    cout << cur;
    inorder(tree[cur - 'A'].second);
}
void postorder(char cur){
    if(cur == '.')
        return;
    postorder(tree[cur - 'A'].first);
    postorder(tree[cur - 'A'].second);
    cout << cur;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        tree[a - 'A'].first = b;
        tree[a - 'A'].second = c;
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    
    return 0;
}