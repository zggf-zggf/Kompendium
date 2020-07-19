#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9+7;
int main(){
	long long n; cin>>n;
	vector<long long> tab;
	for(long long i = 0; i < n; i++){
		long long a; cin>>a;
		tab.push_back(a);
	}
	long long dp[(1<<n)]={};
	dp[0] = 1;
	for(long long j = 0; j < (1<<n); j++){
		long long tmp = 0;
		for(long long bit = 0; bit < n; bit++){
			if(j&(1<<bit)) tmp+=tab[bit];
		}
		if(tmp<0) dp[j] = 0;
		else{
			for(long long bit = 0; bit < n; bit++){
				if(j&(1<<bit)) dp[j]+=dp[j-(1<<bit)];
			}
		}	
		dp[j] %= mod;
	}
	cout<<dp[(1<<n)-1];		
	return 0;
}
