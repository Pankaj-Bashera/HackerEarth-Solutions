#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
	cin>>s;
	int n = s.size();
    int res = n;
    for (int len=n; len<2*n; len++) {
        int steps = 0;
        for (int i = 0; i < len / 2; i++) {
            if (i < n && (len - i - 1) < n) {   
                if (s[i] != s[len-i-1]) steps++;
            } else {
                steps++;
            }
        }
        res = min(res, steps);
    }

    printf("%d ", res);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}