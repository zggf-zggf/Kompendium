#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin>>n>>m;
	int dp[(1<<m)];
	for(int i = 0; i < (1<<m); i++) dp[i] = 1e9;
	int tab[m]={};
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		int d; cin>>d;
		for(int j = 0; j < m; j++){
			cin>>tab[j];
		}
		for(int mask = (1<<m)-1; mask > 0; mask--){
			int sak = mask;	
			int sm = 0;
			bool op = true;
			while(op){
				op=false;
				for(int b = 0; b < m; b++){
					if(sak&(1<<b)){
						if(((dp[sak]-dp[sak^(1<<b)])>tab[b])||i==0){
							op=true;
							sak^=(1<<b);
							sm+=tab[b];
						}
					}
				}
			}
			if(d+sm+dp[sak]<dp[mask]) dp[mask] = d+sm+dp[sak];
		}	
	}	
	cout<<dp[(1<<m)-1];
	return 0;
}
