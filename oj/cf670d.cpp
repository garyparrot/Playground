#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; long long k; cin >> n >> k;
    vector<long long> ing_cost(n);
    vector<long long> ing_own(n);
    for(int i = 0; i < n;i++) cin >> ing_cost[i]; 
    for(int i = 0; i < n;i++) cin >> ing_own[i]; 

    long long cooked = 0ll;
    for(long long i = 31; i >= 0; i--){
        long long guess = cooked + (1ll << i);

        // test if we can cook that much.

        bool fucked = false;
        long long current_magic = k;
        for(int i = 0; i < n;i++){
            // cout << current_magic << " " << ing_cost[i] * guess << " " << guess << endl;
            if(current_magic >= ing_cost[i] * guess - ing_own[i])
                current_magic -= max(ing_cost[i] * guess - ing_own[i], 0ll);
            else
            {
                fucked = true;
                break;
            }
        }

        if(!fucked)
            cooked = guess;
    }

    cout << cooked << endl;

}
