#include <bits/stdc++.h>
using namespace std;

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Day{
    int month, day; // 0-index

    void next(){ 
        day++;
        if(day == days[month])
            day = 0, month = (month + 1) % 12;
    }
    bool operator==(const Day day2) const { return month == day2.month && day == day2.day; }
    pair<int,int> getValue(){
        return make_pair(month + 1, day + 1);
    }
    Day(int m, int d) : month(m), day(d){
    }
};

int eval(Day day){
    pair<int,int> p = day.getValue();
    int m = p.first; 
    int d = p.second;

    if(m == 4 && d == 4) return 0;
    int sum[10] = {0,0,0,0,0,0,0,0,0,0};

    sum[m % 10]++; 
    sum[m / 10 % 10]++;
    sum[d % 10]++;
    sum[d / 10 % 10]++;

    return count_if(sum ,sum + 10, [](const int& val) -> bool { return val > 0; }) <= 2;
}

int main(void){
    int t ; cin >> t;
    while(t--){
        string s1,s2; cin >> s1 >> s2;
        for(char& c : s1) if(c == '/') c = ' ';
        for(char& c : s2) if(c == '/') c = ' ';
        stringstream ss1(s1), ss2(s2);

        int m0,d0, m1, d1; 
        ss1 >> m0 >> d0; ss2 >> m1 >> d1;
        Day dd0(m0-1,d0-1);
        Day dd1(m1-1,d1-1);

        int counter = 0;
        while(!(dd0 == dd1)){
            counter += eval(dd0);
            dd0.next();
        }
        counter += eval(dd1);        

        cout << counter << endl;
    }
}
