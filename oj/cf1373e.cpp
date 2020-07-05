#include <bits/stdc++.h>

using namespace std;

int f(int x){
    int sum = 0;
    while(x) sum += x % 10, x /= 10;
    return sum;
}

int main() {

    int Cases; cin >> Cases;

    while(Cases--) {
        bool solved = false;
        int n, k;
        cin >> n >> k;

        // Brute search 0 ~ 999 Answer
        for(int i = 0; i <= 999; i++){
            int total = 0;
            for(int j = 0;j <= k;j++)
                total += f(i + j);
            if(total == n)
            {
                solved = true;
                cout << i << endl;
                break;
            }
        }

        if(solved) continue;

        // Crazy method
        int average_digits = n / (k+1);
        int possible_start_digits = average_digits - k / 2;
        int middle_9 = 0;
        while(possible_start_digits - (middle_9 * 9) > (9+9-k)) middle_9++;
        int rest_digits = possible_start_digits - (middle_9 * 9);
        int last_digit  = 9 - k;
        int first_digit = rest_digits - last_digit;

        if(first_digit <= 0) { cout << -1 << endl; continue;};

        cout << first_digit << string(middle_9, '9') << last_digit << endl;

    }
}
