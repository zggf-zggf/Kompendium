#include <bits/stdc++.h>

using namespace std;
int n, m, mod;
vector<vector<vector<int>>> dp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>mod;
	graf.resize(n);
	for(int i = 0; i < m; i++){
		int a, b; cin>>a>>b;
		a--; b--;
		dp[1][a][b]++;
	}
	for(int j = 1; j < 50; j++){
		for(int i = 0; i < n; i++){
			for(int k = 0; k < n; k++){
				for(int t = 0; t < n; t++){
					dp[j][i][k] += dp[1][i][t]*dp[j-1][t][k];	
				}
				dp[j][i][k]%=mod;
			}
		}	
	}
			
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a, b, c; cin>>a>>b>>c; a--; b--;
	}
	return 0;
}
