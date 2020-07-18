#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pref;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int sum = 0;
	int n, m; cin>>n>>m;
	pref.resize(n, vector<int>(m));
	vector<vector<bool>> pos(n, vector<bool>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin>>c;
			pref[i][j] = c=='#';
			sum+= c=='#';
			if(i>0) pref[i][j] += pref[i-1][j];
			if(j>0) pref[i][j] += pref[i][j-1];
			if(i>0&&j>0) pref[i][j] -= pref[i-1][j-1];	
		}
	}

	vector<vector<int>> tmp(n+1, vector<int>(m+1));
	int wyn = min(n, m);
	int pocz = 1, kon = 1+min(n, m);
	while(pocz<kon){
		tmp.resize(0); tmp.resize(n+1, vector<int>(m+1));
		int mid = (kon+pocz)/2;
		mid--;
		for(int i = 0; i < n-mid; i++){
			for(int j = 0; j < m-mid; j++){
				int sum = pref[i+mid][j+mid];
				if(i>0) sum -= pref[i-1][j+mid];
				if(j>0) sum -= pref[i+mid][j-1];	
				if(i>0&&j>0) sum += pref[i-1][j-1];
				if(sum==(mid+1)*(mid+1)){
					tmp[i][j] += 1;
					tmp[i+mid+1][j] -=1;
					tmp[i][j+mid+1] -=1;
					tmp[i+mid+1][j+mid+1] +=1;
				}
			}
		}
		int coc = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i>0) tmp[i][j]+=tmp[i-1][j];
				if(j>0) tmp[i][j]+=tmp[i][j-1];
				if(i>0&&j>0) tmp[i][j] -= tmp[i-1][j-1];
				if(tmp[i][j]>=1) coc++;
			}
		}
		mid++;
		if(coc==sum) pocz = mid+1;
		else kon = mid;
	}
	cout<<pocz-1;
	return 0;
}
