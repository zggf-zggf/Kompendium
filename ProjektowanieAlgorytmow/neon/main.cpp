#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, m; cin>>n>>m;
	string s, t; cin>>s>>t;
	//vector<vector<long long>> dp(s.size()+1, vector<long long>(t.size()+1));
	long long dp[s.size()+1][t.size()+1] = {};
	dp[0][0] = 1;
	//vector<vector<int>> sm1(s.size()+1, vector<int>(26, -1));
	//vector<vector<int>> sm2(t.size()+1, vector<int>(26, -1));
	int sm1[s.size()+1][26] = {};
	int sm2[t.size()+1][26] = {};	
	for(int i = 0; i < 26; i++){
		sm1[s.size()][i] = -1;
		sm2[t.size()][i] = -1;
	}
	for(long long i = s.size(); i > 0; i--){
		//sm1[i-1] = sm1[i];
		for(int j = 0; j < 26; j++){
			sm1[i-1][j] = sm1[i][j];
		}
		sm1[i-1][s[i-1]-'a'] = i;
	}	
	for(int i = t.size(); i > 0; i--){
		for(int j = 0; j < 26; j++){
			sm2[i-1][j] = sm2[i][j];
		}
		sm2[i-1][t[i-1]-'a'] = i;
	}	
	long long wyn = -1;
	for(int i = 0; i <= s.size(); ++i){
		for(int j = 0; j <= t.size(); ++j){
			dp[i][j] %= mod;
			wyn+=dp[i][j];
			for(int c = 0; c < 26; ++c){
				if(sm1[i][c]>-1&&sm2[j][c]>-1){
					dp[sm1[i][c]][sm2[j][c]]+=dp[i][j];
				}
			}
		}
		wyn%=mod;
	}	
	cout<<wyn;			
	return 0;
}
