#include <bits/stdc++.h>
using namespace std;

void dprintf(const char* fmt, ...){
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    va_end(va);
}

typedef long long ll;
struct item { ll weight; ll price; };
struct state {
    ll lower, upper, w, i, p; 

    bool operator<(const state& s2) const {
        if(lower != s2.lower) return lower < s2.lower;
        return upper < s2.upper;
    }

    state(ll l, ll u, ll w, ll p, ll i) : lower(l), upper(u), w(w), p(p), i(i) {}
};

const ll INF = 1000000;

ll W;
ll lowerbound(const vector<item>& items, ll i, ll w, ll p){
    w = W - w;
    for(i;i < items.size() && w > 0; i++){
        if(items[i].weight <= w) 
            { w -= items[i].weight; p -= items[i].price; }
        else
            { p -= (ll)((double)items[i].price * w / items[i].weight); w = 0; }
    }
    return p;
}
ll upperbound(const vector<item>& items, ll i, ll w, ll p){
    w = W - w;
    for(i;i < items.size() && w > 0; i++){
        if(items[i].weight <= w) 
            { w -= items[i].weight; p -= items[i].price; }
        else
            break;
    }
    return p;
}

int main(void){
    int n;
    while(cin >> n && n != 0){
        vector<item> items(n);
        for(int i = 0; i < n ;i++) cin >> items[i].weight;
        for(int i = 0; i < n ;i++) cin >> items[i].price;
        ll ans = INF;
        cin >> W;

        sort(items.begin(), items.end(), [](const item& a, const item& b) -> bool { return (a.price / a.weight) > (b.price / b.weight); });

        priority_queue<state> q;
        ll lb = lowerbound(items, 0, 0, 0);
        ll ub = upperbound(items, 0, 0, 0);
        q.push(state(lb, ub, 0, 0, 0));

        while(q.empty() == false){
            state s = q.top(); q.pop();
            // dprintf("Get state lb=%d ub=%d stage=%d w=%d p=%d\n", s.lower, s.upper, s.i, s.w, s.p);
            if(s.w > W) continue;
            if(s.lower >= ans) continue;
            if(s.lower == s.upper) { ans = min(ans, s.lower); continue; }

            ll l0 = lowerbound(items, s.i+1, s.w, s.p);
            ll u0 = upperbound(items, s.i+1, s.w, s.p);
            q.push(state(l0, u0, s.w, s.p, s.i+1));
            ll l1 = lowerbound(items, s.i+1, s.w + items[s.i].weight, s.p - items[s.i].price);
            ll u1 = upperbound(items, s.i+1, s.w + items[s.i].weight, s.p - items[s.i].price);
            q.push(state(l1, u1, s.w + items[s.i].weight, s.p - items[s.i].price, s.i+1));
        }

        cout << -ans << endl;
    }
}


