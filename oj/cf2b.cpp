#include <bits/stdc++.h>

using namespace std;

int zero_state[1000][1000];
int least2 [1000][1000][2];
int least5 [1000][1000][2];
char src[1000][1000];

int main() {

    int n; cin >> n;

    vector<vector<int>> vec (n, vector<int>(n));

    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
            least2[i][j][0] = 1000;
            least2[i][j][1] = 1000;
            least5[i][j][0] = 1000;
            least5[i][j][1] = 1000;
        }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            if(!zero_state[i][j]){
                int value = vec[i][j];
            }
        }

}
