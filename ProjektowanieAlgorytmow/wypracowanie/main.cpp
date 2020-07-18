#include <bits/stdc++.h>

using namespace std;

int minDistance(string word1, string word2) {
	vector<vector<int>> dp(word1.size()+1, vector<int>(1+word2.size()));
	for(int i = 0; i <= word1.size(); i++){
	    for(int j = 0; j <= word2.size(); j++){
		if(i==0)dp[i][j] = j;
		else if(j==0){
		    dp[i][j] = i;
		}else if(word1[i-1]==word2[j-1]){
		    dp[i][j] = dp[i-1][j-1];
		}else{
		    dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	    }
	}

	return dp.back().back();
}

int main(){
	ios_base::sync_with_stdio(0);// cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin>>n>>m;
	string s; cin>>s;
	int n; cin>>n;
	string t;	
	cin>>t;
	cout<<minDistance(s,t);
	return 0;
}
