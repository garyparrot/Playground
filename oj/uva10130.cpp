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
int dp[40];
int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    for(cin >> Case; Case--;){
        int N; cin >> N;
        vector<pair<int,int>> items(N);
#define weight first
#define value  second
        for(int i = 0;i < N;i++)
            cin >> items[i].value >> items[i].weight;

        int G; cin >> G;
        vector<int> vec(G);
        for (int i = 0; i < G; ++i) cin >> vec[i];

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++)
            for(int j = 30; j >= items[i].weight;j--){
                dp[j] = max(dp[j-items[i].weight] + items[i].value, dp[j]);
            }

        int sum = 0;
        for(int i = 0;i < G;i++)
            sum += dp[vec[i]];

        cout << sum << endl;
    }
}
