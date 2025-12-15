#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
	if(b==0) return a<0 ? -a : a;
	return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
	if(a==0 || b==0) return 0;
	return (a*b)/gcd(a,b);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		ll n,a,b,c;
		cin>>n>>a>>b>>c;


		ll bya = n/a;
		ll byb = n/b;
		ll byc = n/c;
		ll byab = n/lcm(a,b);
		ll bybc = n/lcm(b,c);
		ll byca = n/lcm(c,a);
		ll x = n/lcm(lcm(a,b),c);

		ll ans = bya+byb+byc-byab-bybc-byca+x;
		cout << ans << '\n';
	}
	return 0;
}
