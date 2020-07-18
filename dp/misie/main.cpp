#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	int dp[a+2][b+2][c+2][d+2][4];
	dp[0][0][0][0][0] = 1;
	dp[0][0][0][0][1] = 1;
	dp[0][0][0][0][2] = 1;
	dp[0][0][0][0][3] = 1;
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			for(int k = 0; k <= c; k++){
				for(int l = 0; l <= d; l++){
					if(i==0&&j==0&&k==0&&l==0) continue;
					int tmp=0;
					//wybieramy A1
					if(i>0)tmp = dp[i-1][j][k][l][3];
					if(i>1)tmp+=dp[i-2][j][k][l][3];
					dp[i][j][k][l][0] = tmp;
				}	
			}
		}
	}
	int wyn = 0;
	wyn += dp[a][b][c][d][0];
	wyn += dp[a][b][c][d][1];
	wyn += dp[a][b][c][d][2];
	wyn += dp[a][b][c][d][3];
	cout<<wyn;
	return 0;
}
