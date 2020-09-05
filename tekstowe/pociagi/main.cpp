#include <bits/stdc++.h>

using namespace std;
long long p = 31, mod = 1e9+696969;

int main(){
	long long n, m, q; cin>>n>>m>>q;
	vector<long long> pot(m+1);
	pot[0] = 1;
	for(long long i = 1; i < pot.size(); i++){
		pot[i] = (pot[i-1]*p)%mod;
	}
	vector<string> inp(n), oper;
	unordered_map<long long, long long> cur, maksi;
	vector<long long> zap, hasze(n), wyn(n);
	for(long long i = 0; i < n; i++){
		cin>>inp[i];	
		for(long long j = 0; j < m; j++){
			hasze[i] += ((inp[i][j]-'a')*pot[j])%mod;
		}
		cur[hasze[i]]++;
		maksi[hasze[i]]=cur[hasze[i]];
	}
	zap = hasze;
	oper = inp;
	vector<pair<pair<long long, long long>, pair<long long, long long>>> qur;
	for(long long i = 0; i < q; i++){
		long long a, b, c, d; cin>>a>>b>>c>>d;
		qur.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
		a--; b--; c--; d--;
		cur[hasze[a]]--;
		cur[hasze[c]]--;
		hasze[a]=(hasze[a]+mod-(pot[b]*(oper[a][b]-'a'))%mod)%mod;	
		hasze[c]=(hasze[c]+mod-(pot[d]*(oper[c][d]-'a'))%mod)%mod;	
		swap(oper[a][b], oper[c][d]);
		hasze[c]=(hasze[c]+(pot[d]*(oper[c][d]-'a'))%mod)%mod;	
		hasze[a]=(hasze[a]+(pot[b]*(oper[a][b]-'a'))%mod)%mod;	
		cur[hasze[a]]++;
		cur[hasze[c]]++;
		maksi[hasze[a]] = max(maksi[hasze[a]], cur[hasze[a]]);	
		maksi[hasze[c]] = max(maksi[hasze[c]], cur[hasze[c]]);	
	}
	oper = inp;
	hasze = zap;
	for(long long i = 0; i < q; i++){
		long long a = qur[i].first.first, b = qur[i].first.second, c =qur[i].second.first, d =qur[i].second.second; 
		cout<<maksi[hasze[3]]<<" ";
		a--; b--; c--; d--;
		wyn[a] = max(wyn[a], maksi[hasze[a]]);
		wyn[c] = max(wyn[c], maksi[hasze[c]]);
		hasze[a]=(hasze[a]+mod-(pot[b]*(oper[a][b]-'a'))%mod)%mod;	
		hasze[c]=(hasze[c]+mod-(pot[d]*(oper[c][d]-'a'))%mod)%mod;	
		swap(oper[a][b], oper[c][d]);
		hasze[c]=(hasze[c]+(pot[d]*(oper[c][d]-'a'))%mod)%mod;	
		hasze[a]=(hasze[a]+(pot[b]*(oper[a][b]-'a'))%mod)%mod;	
		wyn[a] = max(wyn[a], maksi[hasze[a]]);
		wyn[c] = max(wyn[c], maksi[hasze[c]]);
	}
	for(auto it:maksi) cout<<it.first<<" "<<it.second<<endl;
	for(auto it:wyn) cout<<it<<endl;	
	return 0;
}
			
			
