#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin>>n;

	vector<vector<int>> cost(n, vector<int>(n));
	vector<vector<int>> benefit(n, vector<int>(n));
	vector<string> board(n);

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		cin>>cost[i][j];
	}
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		cin>>benefit[i][j];
	}
	for(int i=0; i<n; i++) {
		cin>>board[i];
	}

	int tcost = 0, tbt = 0;

	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		if(board[i][j]=='*') {
			tcost += cost[i][j];
			tbt += benefit[i][j];
			continue;
		}

		bool dominated = true;
		for(int d=0; d<4; d++) {
			int ni = i+dx[d];
			int nj = j+dy[d];

			if(ni>=0 && ni<n && nj>=0 && nj<n) {
				if(board[ni][nj]!='*') {
					dominated = false;
					break;
				}
			}
		}

		if(dominated) tbt += benefit[i][j];
	}

	cout << (tbt - tcost) << '\n';
}

int main() {
	int t;
	cin>>t;

	while(t--) solve();
}
