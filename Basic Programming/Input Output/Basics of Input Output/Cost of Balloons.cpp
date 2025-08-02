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
    int n,m;
    cin>>n>>m;

    int participants;
    cin>>participants;

    int l=0,g=0;

    for(int i=0; i<participants; i++) {
        int p1,p2;
        cin>>p1>>p2;

        l+=p1;
        g+=p2;
    }

    int ans = 0;
    if(l<g) {
        ans = (l*max(n,m))+(g*min(n,m));
    } else {
        ans = (g*max(n,m))+(l*min(n,m));
    }

    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
    return 0;
}
