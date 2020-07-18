#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; 
	cin>>n>>m;
	vector<vector<int>> pref(n, vector<int>(m));
	int k; cin>>k;
	for(int i = 0; i < k; i++){
		int a, b; cin>>a>>b;
		pref[a-1][b-1] = 1;
	}
	int wyn = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i>0) pref[i][j]+=pref[i-1][j];
			if(j>0) pref[i][j]+=pref[i][j-1];
			if(i>0&&j>0) pref[i][j] -= pref[i-1][j-1];
			for(int r = wyn; r<=i&&r<=j; r++){
				int tmp = pref[i][j];
				if(r<i)tmp -= pref[i-r-1][j];
				if(r<j)tmp -= pref[i][j-r-1];
				if(r<i&&r<j) tmp+=pref[i-r-1][j-r-1];
				if(tmp==0) wyn = r;
				else break;
			}
		}
	}
	cout<<(wyn+1)*(wyn+1);
	return 0;
}
