#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

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

struct DSU {
    vector<int> parent, sz, strength;
    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1,1);
        iota(parent.begin(), parent.end(), 0);
        strength.resize(n+1);
        iota(strength.begin(), strength.end(), 0);
    }

    int find(int x) {
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int x = find(a);
        int y = find(b);
        if(x!=y) {
            if(sz[x]<sz[y]) swap(x,y);
            strength[x] += strength[y];
            sz[x] += sz[y];
            parent[y] = x;
        }
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> owner(n+1);
    for(int i=1; i<=n; i++) owner[i] = i;

    DSU dsu(n+q+5);
    int cur = n;
    while(q--) {
        int x;
        cin>>x;

        if(x==1) {
            int a,b;
            cin>>a>>b;
            dsu.unite(owner[a], owner[b]);
        } else if(x==2) {
            int a;
            cin>>a;
            int root = dsu.find(owner[a]);
            cout << dsu.sz[root] << ' ' << dsu.strength[root] << '\n';

        } else {
            int a,b;
            cin>>a>>b;

            int ha = dsu.find(owner[a]);
            int hb = dsu.find(owner[b]);
            if(ha!=hb) {
                dsu.sz[ha]--;
                dsu.strength[ha] -= a;

                ++cur;

                owner[a] = cur;
                dsu.parent[cur] = cur;
                dsu.sz[cur] = 1;
                dsu.strength[cur] = a;

                dsu.unite(owner[a], owner[b]);
            }
        }
    }
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
