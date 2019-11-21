#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <numeric>

using namespace std;

struct node{
    node *r,*l;
    int pri;
    int k;
};

node* merge(node* a, node* b){
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri){
        a->r = merge(a->r, a);
        return a;
    }
    b->l = merge(a, b->l);
    return b;
}
void split(node* s, int k, node*& a, node*& b){
    if(!s){
        a = b = nullptr;
    }else if (s->k <= k){
        a = s;
        split(s->r, k, a->r, b);
    }else{
        b = s;
        split(s->l, k, a, b->l);
    }
}

node* insert(node* r, node* n){
    node *a, *b;
    split(r, n->k, a, b);
    a = merge(a,n);
    a = merge(a,b);
    return a;
}

node* remove(node* r, int key){
    node *a, *b;
    split(r, key, a ,b);
    if(a->k == key)
        return merge(merge(b,a->r), a->l);
    return merge(a,b);
}

node* find(node* r, int key){
    if(r == nullptr) return nullptr;
    return (key > r->k) ? find(r->r, key) : (key < r->k) ? find(r->l, key) : r;
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    node nodes[100] = {0};
    node *res = nullptr;
    for(int i = 0;i < 100;i++){
        cout << "Insert nodes(pri,k): ";
        cin >> nodes[i].pri >> nodes[i].k;
        if(nodes[i].pri == 0)
            break;
        res = insert(res, nodes + i);
    }

    int k;
    string instruction;
    while(cin >> instruction >> k){
        if(instruction == "insert"){
            node *n = (node*)malloc(sizeof(node));
            n->pri = k;
            n->k = k;
            res = insert(res, n);
        }
        if(instruction == "query"){
            cout << (find(res, k) ? "Found" : "Not Found") << endl;
        }
        if(instruction == "remove"){
            cout << (( res = remove(res,k) ) ? "Removed" : "Not Found") << endl;
        }
    }
}
