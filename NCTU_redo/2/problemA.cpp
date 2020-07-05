#include <bits/stdc++.h>

using namespace std;

int main() {
    for(string str; getline(cin, str) && str != "0" ; ){
        string first, last;
        if(str.find('.') != string::npos)
            first = str.substr(0, str.find('.')),
            last  = str.substr(str.find('.') + 1);
        else
            first = str, last = "0";

        long long value1 = atoll(last.c_str());
        long long value2 = 1;
        for(int i = 0;i < last.size() ; i++)
            value2 *= 10;

        while(value1 % 2 == 0 && value2 % 2 == 0)
            value1 /=2, value2 /= 2;
        while(value1 % 5 == 0 && value2 % 5 == 0)
            value1 /=5, value2 /= 5;

        value1 += atoll(first.c_str()) * value2;

        cout << value1 << "/" << value2 << endl;
    }
}
