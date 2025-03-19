#include <iostream>
using namespace std;
int root[1000001];

int get_root(int cur){
    if(root[cur] == cur)
        return cur;
    else{
        root[cur] = get_root(root[cur]);
        return root[cur];
    }
}

void uni(int a, int b){
    //나만의 규칙 만들어야 함(작은 수의 root로 union)
    if(a < b)
        root[get_root(b)] = get_root(a);
    else
        root[get_root(a)] = get_root(b);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        root[i] = i;
    for(int i = 0; i < m; i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(!op){
            uni(a, b);
        }
        else{
            if(get_root(a) != get_root(b))
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}