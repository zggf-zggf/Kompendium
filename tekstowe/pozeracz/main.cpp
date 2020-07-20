#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9+696969;

int main(){
	long long n; cin>>n;
	vector<long long> pot(501);
	pot[0] = 1;
	for(long long i = 1; i <= 500; i++){
		pot[i] = (pot[i-1]*2)%mod;
	}
	vector<long long> tab;
	for(long long i = 0;i < n; i++){ long long a; cin>>a; tab.push_back(a);}
	long long wyn = 0;
	map<long long, bool> mp;
	for(long long r = 0; r < n; r++){
		vector<long long> liczba(501);
		long long hs = 0;
		for(long long j = 0; j <= r; j++){
			liczba[tab[j]]++;
			if(liczba[tab[j]]==1) hs=(hs+pot[tab[j]])%mod;
			if(!mp[hs]){
				wyn++;
				mp[hs] = true;
			}	
		}
		for(int j = r+1; j<n; j++){
			liczba[tab[j-r-1]]--;
			if(liczba[tab[j-r-1]]==0){
				hs=(hs+mod-pot[tab[j-r-1]])%mod;
			}
			liczba[tab[j]]++;
			if(liczba[tab[j]]==1) hs=(hs+pot[tab[j]])%mod;
			if(!mp[hs]){
				wyn++;
				mp[hs] = true;
			}	
		}	
	}
	//for(auto it:mp) cout<<it.first<<endl;
	cout<<wyn;	
	return 0;
}
