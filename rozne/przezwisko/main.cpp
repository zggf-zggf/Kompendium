#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin>>n>>m;
	vector<vector<bool>> dp(n, vector<bool>(m));
	int z; cin>>z;
	vector<int> op;
	for(int i = 0; i < z; i++){
		int a; cin>>a; op.push_back(a);	
	}
	sort(op.begin(), op.end());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int c = 0; c <op.size(); c++){
				if(op[c]>i&&op[c]>j)break;
				if(i>=op[c])if(!dp[i-op[c]][j]){
					dp[i][j] = true;
					break;
				}
				if(j>=op[c])if(!dp[i][j-op[c]]){
					dp[i][j] = true;
					break;
				}
			}
		}
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a, b; cin>>a>>b; a--; b--;
		if(dp[a][b]) cout<<"KAROL\n";
		else cout<<"PRZEZWISKO\n";
	}
	return 0;
}
