#include <iostream>
using namespace std;

int main() {
	using ll = long long;
	int t;
	cin>>t;

	while(t--) {
		ll n,m;
		cin>>n>>m;

		if(m==1) {
			if(n==1) cout << "Alice\n";
			else cout << "Bob\n";
			continue;
		}

		if((n%2==1) && (m%2==1)) cout << "Alice\n";
		else cout << "Bob\n";
	}

	return 0;
}
