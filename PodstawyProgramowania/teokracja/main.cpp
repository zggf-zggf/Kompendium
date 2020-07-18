#include <bits/stdc++.h>

using namespace std;
long long mod = (1e9+696969);
long long pot(long long a, long long b){
	if(b==0) return 1;
	if(b%2==0){
		long long cur = pot(a, b/2);
		return (cur*cur)%mod;
	}else return (a*pot(a, b-1))%mod;
}
int main(){
	long long a, b, c, d;
	cin>>a>>b>>c>>d;
	a%= mod;
	c%=mod;
	b%=mod;
	d%=mod;
	long long wyn = (((a*b)%mod) * pot((c)%mod, mod-2))%mod;
	wyn *= pot(d, mod-2);
	wyn%=mod;
	cout<<wyn;
	return 0;
}
