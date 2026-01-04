#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1001,true);
void sieve() {
	int n=1000;
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i<=n; i++) {
		if(isPrime[i] && i*i<=n) {
			for(int j=i*i; j<=n; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}
int main() {
	sieve();
	int n;
	cin>>n;

	vector<vector<int>> gd(n, vector<int>(n));
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		cin>>gd[i][j];
	}

	vector<pair<int,int>> dirs = {
		{-1,0},{0,1},{0,-1},{1,0}
	};

	int cnt = 0;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		int sum = 0;
		for(auto& [dx, dy] : dirs) {
			int nx = i+dx;
			int ny = j+dy;
			if(nx>=0 && nx<n && ny>=0 && ny<n) sum += gd[nx][ny];
		}
		if(isPrime[sum]) cnt++;
	}
	cout << cnt << '\n';
}
