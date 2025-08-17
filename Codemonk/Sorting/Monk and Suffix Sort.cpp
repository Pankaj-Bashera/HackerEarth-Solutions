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

vector<string> genSuffixes(string& s) {
    vector<string> v;
    int n = s.length();
    for(int i=0; i<n; i++) {
        v.pb(s.substr(i));
    }
    return v;
}

void solve() {
    string s;
    cin>>s;

    int k;
    cin>>k;

    // since the constraints are very small we can directly implement a brute force solution
    vector<string> suffix = genSuffixes(s);
    sort(all(suffix));

    cout << suffix[k-1] << '\n';
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
