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
    int cases, x, n;
    for (cin >> cases ; cases ; --cases) {

        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0 ; i < n ; i++) { cin >> v[i]; }

        int odd = 0, even = 0;
        for (int i = 0 ; i < n ; i++) 
            odd += v[i] % 2 == 1,
            even += v[i] % 2 == 0;

        bool ok = false;

        if(odd)
            x -= 1, ok = true, odd -= 1;
        x -= 2 * min(x/2, odd/2);
        x -= min(x, even);

        cout << (ok && x == 0 ? "Yes" : "No") <<endl;

    }
}
