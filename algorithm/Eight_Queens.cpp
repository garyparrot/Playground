#include <bits/stdc++.h>

using namespace std;

int get_lr_index(int size, int x,int y){
    return x + y;
}
int get_rl_index(int size, int x, int y){
    return (size - 1) - x + y;
}

int solve(int size, int step, int* selection, int* available_queen, int* mark_lr, int* mark_rl){

    if(step == size){
        // we got a feasible solution.
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                cout << (selection[i] == j) ? '@' : '+';
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    clog << "Current State: " << accumulate(selection, selection + size, string(""), [] (string str, int sel) -> string {return str + to_string(sel) + ",";}) << endl;
    clog << "Current MarkLR: " << accumulate(mark_lr, mark_lr + size * 2, string(""), [] (string str, int sel) -> string {return str + to_string(sel) + ",";}) << endl;
    clog << "Current MarkRL: " << accumulate(mark_rl, mark_rl + size * 2, string(""), [] (string str, int sel) -> string {return str + to_string(sel) + ",";}) << endl;

    int sum = 0;
    for(int i = 0;i < size;i++){
        if(available_queen[i]){
            clog << "Queen " << i << "," << step << ": " << get_lr_index(size,i,step) << "," << get_rl_index(size,i,step) << endl;
            if(mark_lr[get_lr_index(size,i,step)] != 0)
                continue;
            if(mark_rl[get_rl_index(size,i,step)] != 0)
                continue;

            // Set 
            mark_lr[get_lr_index(size,i,step)] = 1;
            mark_rl[get_rl_index(size,i,step)] = 1;
            available_queen[i] = false;
            selection[step] = i;

            // Solve it recursively
            sum += solve(size,step+1,selection,available_queen,mark_lr,mark_rl);

            // Reset
            mark_lr[get_lr_index(size,i,step)] = 0;
            mark_rl[get_rl_index(size,i,step)] = 0;
            available_queen[i] = true;
            selection[step] = -1;
        }
    }

    return sum;
}

int main(int argc, const char* argsp[]){
    clog.rdbuf(NULL);
    // Input the size of Chestboard
    int size; cin >> size;

    int* mark_lr = new int[size * 2];
    int* mark_rl = new int[size * 2];
    int* available_queen = new int[size];
    int* selection = new int[size];
    for(int i = 0;i < size;i++)
    {
        available_queen[i] = true;
        mark_lr[i] = false;
        mark_rl[i] = false;
        selection[i] = -1;
    }

    // Searching in the Solution Space
    int result = solve(size, 0, selection, available_queen, mark_lr, mark_rl);
    cout << "Solution: " << result << endl;

}
