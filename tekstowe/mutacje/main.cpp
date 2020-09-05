#include <bits/stdc++.h>

using namespace std;
int p = 500777, mod = 1e9+9; 
vector<int> pot;

int main(){
	int n; vector<int> ciag1, ciag2;
	vector<vector<int>> wys(500009), H;
	pot.resize(500009);
	pot[0] =1;
	for(int i = 1; i < pot.size(); i++){
		pot[i] = (pot[i-1]*p)%mod;
	}
	vector<int> hasze1, hasze2;	
	hasze1.resize(n);
	ciag1.resize(n);
	for(int i = 0; i < n; i++){
		int c; cin>>c;
		hasze1[i] = (c*pot[i])%mod;
		if(i>0) hasze1[i] = (hasze1[i]+hasze1[i-1])%mod;
		ciag1[i] = c;
		wys[c].push_back(i);
		if(H[c].size()) H[c].push_back(H[c].back());
		else H[c].push_back(0);	
		H[c].back() = (H[c].back()+pot[i])%mod;	
	}
	int m; cin>>m;
	hasze2.resize(m);
	ciag2.resize(m);
	for(int i = 0; i < m; i++){
		int c; cin>>c;
		hasze2[i] = (c*pot[i])%mod;
		if(i>0) hasze2[i] = (hasze2[i]+hasze2[i-1])%mod;
		ciag2[i] = c;
	}
	
		
}
