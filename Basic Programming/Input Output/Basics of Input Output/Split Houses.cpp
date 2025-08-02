#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define first F
#define second S

template<typename T>
void inputVec(vector<T> &v, int n) {
    v.resize(n);
    for (auto &x : v) cin >> x;
}
#define initv(v, n, T) vector<T> v; inputVec(v, n);

using pii = pair<int,int>;
using pli = pair<ll,int>;
const int MOD = 1e9 + 7;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;

void solve() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    bool adjacent = false;
    for(int i=0; i<n-1; i++) {
        if(s[i]=='H' && s[i]==s[i+1]) {
            adjacent = true;
            break;
        }
    }

    if(adjacent) {
        cout << "NO" << '\n';
    } else {
        for(int i=0; i<n; i++) {
            if(s[i]=='.') s[i]='B';
        }
        cout << "YES\n" << s << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
