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

long long int merge_sort(vector<int> &vec, int l, int r){
    if(r - l <= 1) return 0;
    
    long long int sum = 0;
    sum += merge_sort(vec, l, (l+r)/2);
    sum += merge_sort(vec, (l+r)/2, r);

    vector<int> sep(r - l);
    int i = l, m = (l+r)/2, j = m, k = 0;
    while(i < m && j < r)
        if(vec[i] <= vec[j])
            sep[k++] = vec[i++];
        else 
            sep[k++] = vec[j++], sum += m - i;
    while(i < m)
        sep[k++] = vec[i++];
    while(j < r)
        sep[k++] = vec[j++];

    for(int i = 0; i < sep.size();i++)
        vec[l+i] = sep[i];

    return sum;
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n && n != 0){
        vector<int> vec(n);
        for(int i = 0;i < n;i++)
            cin >> vec[i];

        cout << merge_sort(vec, 0, vec.size()) << endl;
    }
}
