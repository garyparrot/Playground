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
#include <iomanip>

using namespace std;

string unit[] = { "shata", "hajar", "lakh", "kuti" };
int numbers[] = { 1, 2, 2, 2 };
int cutting[] = { 10, 100, 100, 100 };

void doit(long long num, int step){
    if(num == 0) return;
    doit(num / cutting[step % 4], step+1);
    
    if(num % cutting[step % 4] == 0){
        if(step % 4 == 3)
            cout << " " << unit[step % 4];
        return;
    }

    cout << " " << num % cutting[step % 4] << " " << unit[step % 4];
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);


    long long num; int Case = 1;
    while(cin >> num){
        cout << setw(4) << right << Case << setw(0) << left << ".";
        doit(num / 100, 0);
        if(num % 100)
            cout << " " << num % 100;
        if(num == 0)
            cout << " " << 0;
        cout << endl;
        Case++;
    }

}
