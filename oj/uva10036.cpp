#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int M, N, K; cin >> M;
    while(M--){

        vector<bool> possible(100);

        cin >> N >> K;
        int first; cin >> first; first = (first%K + K) % K;

        possible[first] = true;

        for(int i = 1;i < N;i++){
            int a; cin >> a; a = abs(a) % K;
            vector<bool> possible2(100);
            for(int i = 0;i < K;i++)
                if(possible[i])
                    possible2[(i+a+K)%K] = true, possible2[(i-a+K)%K] = true;

            // swap content of two vector
            possible.swap(possible2);
        }

        cout << (possible[0] ? "Divisible" : "Not divisible") << endl;
    }
}
