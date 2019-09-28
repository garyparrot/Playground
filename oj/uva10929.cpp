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

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    string str;
    while(cin >> str && str != "0"){
        int numbers[1005], len = str.length();
        memset(numbers, 0, sizeof(numbers));

        for(int i = 0; i < len; i++)
            numbers[i] = str[i] - '0';

        for(int i = len - 1; i > 0; i--){
            while(numbers[i] < 0)
                numbers[i] += 10, numbers[i-1]--;
            numbers[i-1] -= numbers[i];
            numbers[i] = 0;
        }

        bool test = numbers[0] == 0;
        cout << str << (test ? " is a multiple of 11.\n" : " is not a multiple of 11.\n");
    }
}
