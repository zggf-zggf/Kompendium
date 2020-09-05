#include <bits/stdc++.h>

using namespace std;
vector<vector<vector<int>>> mat;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin>>n>>m;
	mat.resize(n+1, vector<vector<int>>(n, vector<int>(n, -1e9)));
	for(int i = 0; i < m; i++){
		int a, b, c; cin>>a>>b>>c; a--; b--;
		mat[1][a][b] = c;
	}
	long double wyn = 0;
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				for(int o = 0; o < n; o++){
					mat[i][j][k] = max(mat[i][j][k], mat[i-1][j][o]+mat[1][o][k]);
				}
			}
		}
		for(int j = 0; j < n; j++){
			wyn = max(wyn, (long double)mat[i][j][j]/(long double)i);	
		}
	}
		
	cout<<fixed<<setprecision(4)<<wyn;
	return 0;
}
