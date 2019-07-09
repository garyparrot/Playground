#include <bits/stdc++.h>
using namespace std;

double value(double x,double y, double z){
    return x*y*z/(x*y+y*z+z*x);
}

int main(void){
    // Iterate y z, use binary search for x
    // O(n^2 logn)

    int t; cin >> t;
    while(t--){
        int k;
        cin >> k;

        int counter = 0;
        for(int z = 3*k; 1.0/z < 1.0/k; z--){
            for(int y = floor((2*k*z)/(z-k)); 1.0/y < (1.0/k - 1.0/z); y--){
                if( z > y ) continue;
                int b = z * y - z * k - k * y;
                int a = k * y * z;
                if( b == 0 || a % b != 0 ) continue;
                int x = a / b;

                if(x*y*z != k * (x*y + y*z + z*x))
                    cout << "SHIT" << x << " " << y  << " " << z << endl;

                counter++;
            }
        }

        cout << counter << endl;
    }
}
