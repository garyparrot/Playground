#include <bits/stdc++.h>
using namespace std;

#define arr_string(s,t,title) (accumulate(s,t-1,string(title), [](string s, const auto item) -> string{ return s + to_string(item) + " "; }) + to_string(*(t-1)))

int main(int argc, char *argv[])
{
    int arr[] = {1,3,4,5,12,13,45,56,78,93,99,125,250,305,500,600,704,832};
    int n = sizeof(arr) / sizeof(int);
    int target = 704;

    int k = 0;
    for(int b = n / 2; b >= 1; b /= 2)
        while(k + b < n && arr[k + b] <= target) 
            k += b;
    if(arr[k] == target)
        cout << "Found " << target << " at " << k << "."<< endl;

    return 0;
}
