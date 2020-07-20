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
		for(int mask = 0; mask < (1<<m); mask++){
			int sm = d;
			for(int b = 0; b < m; b++) if(mask&(1<<b)) sm+=tab[b];
			if(sm<dp[mask]){
				int roz = m-__builtin_popcount(mask);
				for(int sak = 0; sak < (1<<roz); sak++){
					int pt = 0;
					int coc = 0;				
					int twyn = d;
					for(int b = 0; b < m; b++){
						if(mask&(1<<b))twyn+=tab[b];	
						else {
							if(sak&(1<<pt)){
								coc+=(1<<b);
							}
							pt++;
						}
					}
					if(dp[coc]+twyn<dp[coc+mask]) dp[coc+mask]=dp[coc]+twyn;
				}
				
			}	
		}	
	}	
	cout<<dp[(1<<m)-1];
	return 0;
}
