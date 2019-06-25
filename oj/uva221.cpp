/*
 * What the hell is wrong with udebug ? 
 * It provide a wrong answer for me 
 * WHAT THE FREAK IS GOING ON WITH UVA OJ???
 */
#include <bits/stdc++.h>
#define append push_back
#define MAX_INT std::numeric_limits<int>::max()
#define MAX_INT64 std::numeric_limits<int>::max()
#define ESP 1e-6

using namespace std;

struct building{
    int x,y,w,d,h, index;
    building(int x,int y,int w,int d,int h,int index) : x(x), y(y), w(w), d(d), h(h), index(index) {}
};

int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    
    for(int n,Case = 1; cin >> n && n != 0; Case++){
        vector<building> vec;
        for(int i = 0;i < n;i++){
            int x,y,w,d,h;
            cin >> x >> y >> w >> d >> h;
            vec.append(building(x,y,w,d,h, i+1));
        }

        // sort it by y then x
        sort(vec.begin(), vec.end(), [](const building& a, const building& b) -> bool { return a.y < b.y || a.y == b.y && a.x < b.x; });
        
        // xpos
        vector<int> xpos;
        for(building& b : vec)
            xpos.append(b.x), xpos.append(b.x + b.w);
        sort(xpos.begin(), xpos.end());
        xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());

        bool visible[200] = {false};
        for(int i = 1;i < xpos.size() ; i++){
            int x0 = xpos[i-1];
            int x1 = xpos[i];
            int lower_h = 0;

            for(building& b : vec){
                if(b.x <= x0 && x1 <= b.x + b.w && b.h > lower_h){
                    visible[b.index] = true;
                    lower_h = b.h;
                }
            }
        }

        // sort it by x then y
        sort(vec.begin(), vec.end(), [](const building& a, const building& b) -> bool { return a.x < b.x || a.x == b.x && a.y < b.y; });

        if(Case != 1) cout << endl;
        cout << "For map #" << Case << ", the visible buildings are numbered as follows:" << endl;
        for(int i = 0, fucking_space_presentation_error_screw_you = false; i < vec.size(); i++)
            if(visible[vec[i].index]){
                cout << ((fucking_space_presentation_error_screw_you) ? " " : "") << vec[i].index;
                fucking_space_presentation_error_screw_you = true;
            }
        cout << endl;
    }
}
