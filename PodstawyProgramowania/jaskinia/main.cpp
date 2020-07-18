#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	long long n, m; cin>>n>>m;
	vector<vector<long long>> pref(n, vector<long long>(m));
	for(long long i = 0; i < n; i++){
		for(long long j = 0; j < m; j++){
			long long a; cin>>a;
			pref[i][j] = a;
			if(i>0) pref[i][j] += pref[i-1][j];
			if(j>0) pref[i][j] += pref[i][j-1];
			if(j>0&&i>0) pref[i][j] -= pref[i-1][j-1];
		}
	}
	long long q; cin>>q;
	long long wyn = 0;
	for(long long i = 0; i < q; i++){
		long long a, b, c, d; cin>>a>>b>>c>>d;
		a--; b--; c--; d--;
		long long sum = pref[c][d];
		if(a>0) sum -= pref[a-1][d];
		if(b>0) sum -= pref[c][b-1];
		if(a>0&&b>0) sum += pref[a-1][b-1];
		wyn = max(wyn, sum);
	}
	cout<<wyn;
	return 0;
}
