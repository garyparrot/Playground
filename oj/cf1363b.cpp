#include <bits/stdc++.h>
using namespace std;

#define MAX_INT std::numeric_limits<int>::max()
#define MAX_INT64 std::numeric_limits<int>::max()
#define ESP 1e-6

#define to_string_array3(begin, end, title) \
    (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define to_string_array2(begin, end) \
    (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define string_array3(begin, end, title) \
    (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + item + " "; }) + *(end-1))
#define string_array2(begin, end) \
    (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + item + " "; }) + *(end-1))

int Case = 1;
int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    int cases;
    for (cin >> cases ; cases ; --cases) {
        string str;
        cin >> str;

        vector<int> sum0(str.size(), 0);
        sum0[0] = str[0] == '0';
        for (int i = 1 ; i < sum0.size(); i++) 
            sum0[i] = sum0[i-1] + (str[i] == '0');

        int m = sum0.size();
#define left0(i) (sum0[i])
#define left1(i) (i + 1 - sum0[i])
#define right0(i) (sum0[sum0.size()-1] - sum0[i])
#define right1(i) ((sum0.size() - i - 1) - (sum0[sum0.size()-1] - sum0[i]))
        // cout << to_string_array2(sum0.begin(), sum0.end());
        for (int i = 0 ; i < sum0.size() ; i++) {
            // make left 0 and make right 1
            m = min(m, int(left1(i) + right0(i)));
            // make left 1 and make right 0
            m = min(m, int(left0(i) + right1(i)));
        }

        cout << m << endl;
        
    }
}
