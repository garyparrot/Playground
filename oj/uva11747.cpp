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

int unions[2000];

bool same(int a,int b){
    while(unions[a] != a) a = unions[a];
    while(unions[b] != b) b = unions[b];

    return a == b;
}
void merge(int a,int b){
    while(unions[a] != a) a = unions[a];
    while(unions[b] != b) b = unions[b];
    unions[b] = a;
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int n,m;
    while(cin >> n >> m && !(n == 0 && m == 0)){

        for(int i = 0;i < n;i++) unions[i] = i;

        typedef pair<int, pair<int,int>> edge;
#define weight first
#define src second.first
#define dst second.second
        vector<edge> vec(m);
        for(int i = 0;i < m;i++){ cin >> vec[i].src >> vec[i].dst >> vec[i].weight; }

        sort(vec.begin(), vec.end());

        vector<edge> others;

        for(const edge& e: vec){
            if(same(e.src, e.dst))
                others.push_back(e);
            else
                merge(e.src, e.dst);
        }

        if(others.size() == 0)
            cout << "forest" << endl;
        else{
            for(int i = 0;i < others.size();i++)
                cout << (i == 0 ? "" : " ")<< others[i].weight;
            cout << endl;
        }
    }
}
