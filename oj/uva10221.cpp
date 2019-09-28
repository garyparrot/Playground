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

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    const long double pi = 2*acosl(0);
    int s,a; string unit;
    while(cin >> s >> a >> unit){
        long double radius = (unit == "deg") ? 
                    ( (long double)a * 2 * pi / 360.0l ) :
                    ( (long double)a / 60 * 2 * pi / 360.0l );
        radius = min(radius, 2*pi - radius);
        cout.precision(6); 
        cout << fixed << (6440 + s) * radius << " ";
        cout << 2 * (6440 + s) * sin(radius/2) << endl;
    }
}
