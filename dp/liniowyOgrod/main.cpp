#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin>>n>>m;
	int dp[n+2][5][5] = {};
	int sm[n+2] = {};
	dp[0][2][2] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			for(int k = j; k < 5; k++){
				dp[i][j][k] %= m;
				//case adding R
				int j2 = min(j+1, 3);
				int k2 = max(k+1, 3);
				if(j2>=0&&k2<5) dp[i+1][j2][k2] += dp[i][j][k];
				//case adding L
				j2 = min(j-1, 1);
				k2 = max(k-1, 1);
				if(j2>=0&&k2<5) dp[i+1][j2][k2] += dp[i][j][k];
			}
		}
		for(int k = 0; k < 5; k++){
			for(int j = 0; j < 5; j++){
				sm[i] += dp[i][k][j];
			}
		}
		
		sm[i]%=m;

	}
	for(int k = 0; k < 5; k++){
		for(int j = 0; j < 5; j++){
			sm[n] += dp[n][k][j];
		}
	}
	sm[n]%=m;
	for(int i = 0; i <= n; i++) cout<<sm[i]<<" ";
	string s; cin>>s;
	reverse(s.begin(), s.end());
	int mi = 2, ma = 2;
	int wyn = 1;
	for(int i = 0; i < s.size(); i++){
		int ti, ta;
		if(s[i]=='P'){
			ta = max(ma-1, 1);
			ti = min(mi-1, 1);
			ma = max(ma+1, 3);
			mi = min(mi+1, 3);
			wyn+=dp[i+1][ti][ta];
		}else{
			ma = max(ma-1, 1);
			mi = min(mi-1, 1);
			ta = max(ma+1, 3);
			ti = min(mi-1, 1);
		}
	}
	cout<<wyn;	
	return 0;
}
