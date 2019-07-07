#include <bits/stdc++.h>

using namespace std;

struct node { node *lc, *rc; int value; };

node* build_tree(){
    int i; cin >> i; if(i == 0) return nullptr;
    node* n = new node();

    n->value = i;
    n->lc = build_tree();
    n->rc = build_tree();

    return n;
}

bool dfs(node* n, const int S, int sum){
    if(n == nullptr) return false;
    if(n->lc == nullptr && n->rc == nullptr) return sum + n->value == S;

    return dfs(n->lc, S, sum + n->value) || dfs(n->rc, S, sum + n->value);
}

int main(void){
    int q; cin >> q;
    while(q--){
        node *root = build_tree();
        int S; cin >> S;
        cout << ( dfs(root, S, 0) ? "True" : "False" ) << endl;
    }
}
