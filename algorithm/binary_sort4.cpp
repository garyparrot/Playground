#include<bits/stdc++.h>

using namespace std;

double f(double a){ return -a*a + 3*a + 3; }
double f2(double a){ return -(a*a*a + a*a - sqrt(a) + a*log10(a)); }
int main(int argc, char *argv[])
{
    // find the first hill of -x^2
    double maxi = 1000000;
    double x = 1e-3;
    for(double b = maxi/2 ; b >= 1e-4;b /=2){
        while(f2(x+b) <= f2(x+b+1e-4))
        {
            x += b;
        }
    }
    cout << "Maximum value at " << x << " f(x)=" << f2(x) << endl;
    return 0;
}
