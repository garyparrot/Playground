#include <bits/stdc++.h>
using namespace std;

int placed[15];   // is this queen placed, the row id
int who[15];
int b0[20];       // block
int b1[20];       // block
int n, rq, cq, ro, co;

int get_b0(int r, int c){ return n - 1 - r + c; }
int get_b1(int r, int c){ return r + c; }

void print_board(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(who[i] == j)
                cout << "Q";
            else if(i == ro && j == co)
                cout << "!";
            else if(i == rq && j == cq)
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> current;
int track(int stage){
    if(stage == n) { /*print_board();*/ return 1; }
    if(rq == stage){ current.push_back(cq); int sol = track(stage+1); current.pop_back(); return sol; }

    int sol = 0;
    for(int i = 0;i < n;i++){
        // this queen is available and no fucking roadblock here.
        if(placed[i] == -1 && !(ro == stage && co == i) && !b0[get_b0(stage, i)] && !b1[get_b1(stage, i)]){
            // try to put this queen over there
            
            // update config
            b0[get_b0(stage,i)] = true;
            b1[get_b1(stage,i)] = true;
            who[stage] = i;
            current.push_back(i);
            placed[i] = stage;
            // next stage
            sol += track(stage+1);
            // remove config
            b0[get_b0(stage,i)] = false;
            b1[get_b1(stage,i)] = false;
            who[stage] = -1;
            current.pop_back();
            placed[i] = -1;
        }
    }

    return sol;
}

int main(void){
    int t; cin >> t;
    while(t--){
        cin >> n >> rq >> cq >> ro >> co;

        fill(placed, placed + 15, -1);
        fill(who, who+15, -1);
        fill(b0, b0+20, false);
        fill(b1, b1+20, false);
        current.clear();

        // replace
        placed[cq] = true;
        b0[get_b0(rq,cq)] = true;
        b1[get_b1(rq,cq)] = true;
        who[rq] = cq;
            
        cout << track(0) << endl;
    }
}
