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

    int n,m;

    while(scanf("%d%d", &n, &m) && !(n == 0 && m == 0)){

        vector<int> vec(n);
        for(int i = 0;i < n;i++) vec[i] = i;

        for(int i = 0;i < m;i++){
            int a,b;
            scanf("%d%d", &a, &b);
            a--;
            b--;

            // trace the root of a
            int root = a;
            while(root != vec[root])
                root = vec[root];
            int root2 = b;
            while(root2 != vec[root2])
                root2 = vec[root2];

            // now they are the same religion
            vec[root] = root2;
            // printf("Religion: %d %d share %d\n",a,b,root);
        }

        int counter = 0;
        vector<int> finds(n,0);
        for(int i = 0;i < n;i++){
            int trace = i;
            while(trace != vec[trace])
                trace = vec[trace];
            if(!finds[trace])
                counter++, finds[trace] = 1;
        }

        printf("Case %d: %d\n", Case++, counter);

    }
}
