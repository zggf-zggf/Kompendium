#include <bits/stdc++.h>

using namespace std;
long long mod1 = 1e9+696969, mod2 = 1e9+9, p1 = 29, p2 = 31;
int main(){
	string s; cin>>s;
	long long n = s.size();
	vector<long long> pot1(n+1), pot2(n+1);
	pot1[0] = 1;
	pot2[0] = 1;
	for(long long i = 1; i <= n; i++){
		pot1[i] = (pot1[i-1]*p1)%mod1;
		pot2[i] = (pot2[i-1]*p2)%mod2;
	}	
	vector<long long> hasz1(n+1), hasz2(n+1);
	for(long long i = 0; i < n; i++){
		hasz1[i] = ((s[i]-'a')*pot1[i])%mod1;
		hasz2[i] = ((s[i]-'a')*pot2[i])%mod2;
		if(i>0) hasz1[i] = (hasz1[i]+hasz1[i-1])%mod1;
		if(i>0) hasz2[i] = (hasz2[i]+hasz2[i-1])%mod2;
	}
	long long q; cin>>q;
	for(long long i = 0; i < q; i++){
		string t; cin>>t;
		long long k; cin>>k;
		if(k+t.size()>=n){cout<<"NIE\n"; continue;}
		long long hs1 = 0, hs2 = 0;
		for(long long j = 0; j < t.size(); j++){
			hs1=(hs1+(t[j]-'a')*pot1[j+k])%mod1;	
			hs2=(hs2+(t[j]-'a')*pot2[j+k])%mod2;	
		}
		long long coc1 = hasz1[k+t.size()-1];	
		long long coc2 = hasz2[k+t.size()-1];	
		if(k>0) coc1=(coc1-hasz1[k-1]+mod1)%mod1;
		if(k>0) coc2=(coc2-hasz2[k-1]+mod2)%mod2;
		if(coc1!=hs1||coc2!=hs2) cout<<"NIE\n";
		else cout<<"TAK\n";
	}
	return 0;
}
