#include <bits/stdc++.h>

using namespace std;

bool lower_than_sqrt179(double a){
    return a*a <= 66431;
}

int main(int argc, char *argv[])
{
    const double max = 6666666666;
    double x = 0;
    for(double b = max/2; b >= 1e-8; b/=2)
        while(lower_than_sqrt179(x+b)) x += b;

    cout << x << " " << x*x << endl; 
    
    return 0;
}
