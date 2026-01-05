#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin>>n;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];

	vector<int> x = a;
	sort(x.begin(), x.end());

	long long minsum=0, mxsum=0;
	for(int i=0; i+1<n; i+=2) {
		minsum += x[i+1]-x[i];
	}

	for(int i=0; i<n/2; i++) {
		mxsum += x[n-i-1]-x[i];
	}

	printf("%ld %ld\n", minsum, mxsum);
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
