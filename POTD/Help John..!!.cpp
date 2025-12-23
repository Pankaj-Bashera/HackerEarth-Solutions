#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,x,p;
	cin>>n>>x>>p;

	vector<int> cost(n+1,0);
	for(int i=1; i<=n; ++i) {
		cin>>cost[i];
	}

	int bottles = 0, tot = 0, flag = 0;
	for(int i=0; i<n; i++) {
		int k = (cost[i]-cost[i+1]);
		if(k<0) {
			k = -k;
			if(bottles>=k) {
				bottles -= k;
			} else {
				k -= bottles;
				bottles = 0;
				tot += x*k;
				if(!flag && tot > p) {
					cout << "Impossible\n";
					flag = 1;
				}
			}
		} else {
			bottles += k;
		}
	}

	if(flag) {
		cout << (tot-p) << '\n';
		return;
	}

	cout << "Possible" << '\n';
	cout << (p - tot) << '\n';
	
}


int main() {
	int i;
	cin>>i;
	while(i--) solve();
	return 0;
}
