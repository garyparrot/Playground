// This data structure required O(nlogn) preprocessing for constructing 劃分樹
// After that it allowed you to query the k-th large number at specific range [l,r) by O(logn)

#include <bits/stdc++.h>

using namespace std;
using namespace std::placeholders;

int tree[50][100];
int toleft[50][100];

int arr[10]  = {0,1,2,3,4,5,6,7,8,9};
int sorted[10] = {0,1,2,3,4,5,6,7,8,9};

void build_tree(int l, int r, int dep){
    if(l == r) return;
    
    // This is kinda stupid, they use the variable to balance
    // the middle number between left and right tree
    // int middleOccurance = (l+r)/2 - l + 1 - count_if(arr + l, arr + r, bind(std::less<int>(), _2, sorted[(l+r)/2]));
    int mid    = (l+r)/2;
    int middle = sorted[mid];
    int same   = mid - l + 1;
    int lpos   = l;
    int rpos   = mid + 1;
    for(int i = l; i <= r; i++) 
        if(tree[dep][i] < sorted[mid])
            same--;

    for(int i = l; i <= r; i++) 
    {
        if(tree[dep][i] < sorted[mid])
            tree[dep+1][lpos++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same > 0)
            tree[dep+1][lpos++] = tree[dep][i], same--;
        else
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1] + lpos - l;
    }

    build_tree(l    , mid, dep+1);
    build_tree(mid+1, r  , dep+1);
}

int query(int L, int R, int l, int r, int dep, int k){
    if(l == r) return tree[dep][l];

    int mid = (L+R) / 2;
    int cnt = toleft[dep][r] - toleft[dep][l-1];

    if (cnt >= k) {
        int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
        int newr = newl + cnt - 1;
        return query(L, mid, newl, newr, dep + 1, k);
    } else {
        int newr = r + toleft[dep][R] - toleft[dep][r];
        int newl = newr - (r-l-cnt);
        return query(mid+1, R, newl, newr, dep+1, k-cnt);
    }
}

int main() {

}
