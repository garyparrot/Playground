/*
 * Disclaimer : I don't want to handle Presentation Error, this is stupid.
 *              I mean, the question didn't talk about the right output format.
 *              and they except we make the presentation right = =, what the freak.
 */
#include <bits/stdc++.h>
#define MAX_INT std::numeric_limits<int>::max()
#define MAX_INT64 std::numeric_limits<int>::max()
#define ESP 1e-6

using namespace std;

int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    
    int n;
    while(cin >> n && n){
        int perm[] = {0,1,2,3,4,5,6,7,8,9};
        int counter = 0;
        do{
            #define merge(array) (array[0] * 10000 + array[1] * 1000 + array[2] * 100 + array[3] * 10 + array[4])
            int first = merge(perm);
            int second = merge((&perm[0] + 5));
            if(second * n == first)
            {
                cout << perm[0] << perm[1] << perm[2] << perm[3] << perm[4] << " / " 
                     << perm[5] << perm[6] << perm[7] << perm[8] << perm[9] << " = "
                     << n << endl;
                counter+=1;
            }
        }while(std::next_permutation(perm, perm+10));

        if(counter == 0)
            cout << "There are no solutions for " << n << ".\n";
    }
}
