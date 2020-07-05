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
    node *l, *r;
    int key, pri, value;
    int rotate, lazykey;
    int cnt;
} nodes[100005];

void say(node* root, int rotate){
    if(!root) return;
    if(root->lazykey){
        root->key += root->lazykey;
        if(root->r) root->r->lazykey += root->lazykey;
        if(root->l) root->l->lazykey += root->lazykey;
        root->lazykey = 0;
    }
    rotate ^= root->rotate;
    if(root->rotate) say(root->r, rotate); else say(root->l, rotate);
    cout << root->value << " " << root->key << endl;
    if(root->rotate) say(root->l, rotate); else say(root->r, rotate);
}
// Split {{{
void split(node* s, int k, node*& a, node*& b){
    if(!s)
    {
        a = b = nullptr;
        return;
    }

    // handle rotate operation and lazykey pogatation
    if(s)
    {
        if(s->rotate){
            if(s->l) s->l->rotate ^= 1;
            if(s->r) s->r->rotate ^= 1;
        }
        if(s->lazykey){
            if(s->l) s->l->lazykey += s->lazykey;
            if(s->r) s->r->lazykey += s->lazykey;
            s->key += s->lazykey;
            s->lazykey = 0;
        }
    }
    if(s->key <= k){
        a = s;
        if(a->r) {
            a->cnt -= a->r->cnt;
        }
        split(s->r, k, a->r, b);
        if(a->r) a->cnt += a->r->cnt;
        // if(a->r) cout << "Part " << a->r->cnt << endl; say(a->r,0);
    }else{
        b = s;
        if(b->l) {
            b->cnt -= b->l->cnt;
        }
        split(s->l, k, a, b->l);
        if(b->l) b->cnt += b->l->cnt;
        // if(b->l) cout << "Part " << b->l->cnt << endl; say(b->l, 0);
    }
}
// }}}

// Merge {{{
node* merge(node *a, node *b){
    if(!a) return b;
    if(!b) return a;

    // propagation of lazykey and rotate flag
    if(a->l){ a->l->lazykey = a->lazykey; }
    if(a->r){ a->r->lazykey = a->lazykey; }
    if(b->l){ b->l->lazykey = b->lazykey; }
    if(b->r){ b->r->lazykey = b->lazykey; }
    a->key += a->lazykey; b->key += b->lazykey;
    a->lazykey = b->lazykey = 0;
    if(a->rotate) {
        if(a->l) a->l->rotate ^= a->rotate;
        if(a->r) a->r->rotate ^= a->rotate;
    }
    if(b->rotate) {
        if(b->l) b->l->rotate ^= b->rotate;
        if(b->r) b->r->rotate ^= b->rotate;
    }
    
    if(a->pri > b->pri){
        a->r = merge(a->r, b);
        if(a->r) a->cnt += a->r->cnt;
        return a;
    }else{
        b->l = merge(a, b->l);
        if(b->l) b->cnt += b->l->cnt;
        return b; 
    }
}
// }}}

/* build tree {{{*/
int id = 1;
node* build_tree(int s, int n){
    if(s > n) return nullptr;
    node* root = nodes + s;
    // left
    root->l = build_tree(2*s, n);
    // init node
    root->key = root->pri = root->value = id++;
    root->pri = 0;
    root->lazykey = 0;
    root->rotate = 0;
    // right
    root->r = build_tree(2*s+1,n);

    if(root->l == nullptr && root->r == nullptr)
        root->cnt = 1;
    else
        root->cnt = (root->l ? root->l->cnt : 0) + (root->r ? root->r->cnt : 0) + 1;

    return root;
}
/*}}}*/


int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    node* root = build_tree(1,n);

    while(m--){
        int a,b; cin >> a >> b;

        // split that shit out
        node *p1, *p2, *pp, *p3; 
        split(root, a - 1, p1, pp);
        split(pp, b, p2, p3);

        // cout << "A1 " << p1->cnt << endl; say(p1, 0);
        // cout << "A3 " << p3->cnt << endl; say(p3, 0);

        // rotate and manipulate these shit
        p2->rotate ^= 1;
        p2->lazykey +=  p3->cnt;
        p3->lazykey += -p2->cnt;
        cout << "A2 " << p2->cnt << endl; say(p2, 0);
        
        // merge it back
        root = merge(p1, merge(p3,p2));

        say(root,0);
        cout << endl;
    }
}
