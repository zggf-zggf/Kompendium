#include <bits/stdc++.h>

using namespace std;
unsigned long long mod = (1e9+696969);
unsigned long long pot(unsigned long long a, unsigned long long b){
	if(b==0) return 1;
	if(b%2LL==0){
		unsigned long long cur = pot(a, b/2LL);
		return (cur*cur)%mod;
	}else return (a*pot(a, b-1LL))%mod;
}
int main(){
	unsigned long long a, b, c, d;
	cin>>a>>b>>c>>d;
	a%= mod;
	c%=mod;
	b%=mod;
	d%=mod;
	unsigned long long wyn = ((a*b)%mod);
	wyn *= pot(c, mod-2);
	wyn%=mod;
	wyn *= pot(d, mod-2);
	wyn%=mod;
	cout<<wyn;
	return 0;
}
