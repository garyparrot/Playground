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
#include <cstring>

using namespace std;

typedef pair<pair<int,int>,pair<int,int>> state;
#define aaa second.second
#define bbb first.second
#define ccc second.first
#define step first.first
#define generate_state(x,y,z,r) (make_pair(make_pair(r,y),make_pair(z,x)))

int limits[3];

state pour(state s, int src, int dst){
    int cool[3] = { s.aaa, s.bbb, s.ccc };
    int pour = min(cool[src] + cool[dst],limits[dst]) - cool[dst];
    cool[src] -= pour;
    cool[dst] += pour;

    return generate_state(cool[0],cool[1],cool[2], s.step + pour);
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        limits[0] = a;
        limits[1] = b;
        limits[2] = c;

        priority_queue<state, vector<state>, greater<state>> que;
        state orig = generate_state(0,0,c,0);
        que.push(orig);

        static int record[205][205][205];
        for(int i =0;i <= a;i++)
            for(int j = 0;j <= b;j++)
                for(int k = 0;k <= c;k++)
                    record[i][j][k] = -1;

        int cloest = 0;

        state answer;
        while(!que.empty()){
            state stat = que.top(); que.pop();

            if(record[stat.aaa][stat.bbb][stat.ccc] == -1)
                record[stat.aaa][stat.bbb][stat.ccc] = stat.step;
            else
                continue;
            // cout << stat.aaa << " " << stat.bbb << " " << stat.ccc << " " << stat.step << endl;

            if(stat.aaa == d || stat.bbb == d || stat.ccc == d){
                cloest = d;
                answer = stat;
                break;
            }
            if(stat.aaa <= d && cloest < stat.aaa) cloest = stat.aaa, answer = stat;
            if(stat.bbb <= d && cloest < stat.bbb) cloest = stat.bbb, answer = stat;
            if(stat.ccc <= d && cloest < stat.ccc) cloest = stat.ccc, answer = stat;

            que.push(pour(stat, 0, 1));
            que.push(pour(stat, 0, 2));
            que.push(pour(stat, 1, 2));
            que.push(pour(stat, 1, 0));
            que.push(pour(stat, 2, 0));
            que.push(pour(stat, 2, 1));
        }

        cout << answer.step << " " << cloest << endl;
    }
}
