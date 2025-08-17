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

    initv(a,n,int);
    // simplifying the equation it becomes Ai^Aj where i!=j;

    sort(all(a));

    int ans = inf;
    for(int i=1; i<n; i++) {
        ans = min(ans, a[i]^a[i-1]);
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
