#include <bits/stdc++.h>

using namespace std;

int opLet(int x){
	return (x+2)%4;
}

int opNum(int x){
	return x^1;
}

int opFul(int x){
	return 3-x;
}

bool pos(int va, int vb, int vc, int vd, int i, int j){
	if(i==j){
		if(va<(i==0)*2) return false;
		if(vb<(i==1)*2) return false;
		if(vc<(i==2)*2) return false;
		if(vd<(i==3)*2) return false;	
	}else{
		if(va<(i==0)||va<(j==0)) return false;
		if(vb<(i==1)||vb<(j==1)) return false;
		if(vc<(i==2)||vc<(j==2)) return false;
		if(vd<(i==3)||vd<(j==3)) return false;
	}
	return true;
}
int mod = 1e6;
int main(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	if(a+b+c+d==1) {cout<<1; return 0;}
	int dp[a+1][b+1][c+1][d+1][4][4]={};
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(pos(a, b, c, d, i, j))
				dp[(i==0)+(j==0)][(i==1)+(j==1)][(i==2)+(j==2)][(i==3)+(j==3)][i][j] = 1;
		}
	}

	for(int va = 0; va <= a; va++){
		for(int vb = 0; vb <= b; vb++){
			for(int vc = 0; vc <= c; vc++){
				for(int vd = 0; vd <= d; vd++){
					if(va+vb+vc+vd<=2)continue;
					for(int i = 0; i < 4; i++){
						for(int j = 0; j < 4; j++){
							if(!pos(va, vb, vc, vd, i, j)) continue;
							int tmp = 0;
							if(i!=j){
								if(i==opFul(j)){
									tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][0][i];
									tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][1][i];
									tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][2][i];
									tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][3][i];
								}else{
									if(i==opNum(j)){
										tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][opLet(i)][i];
										tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][opLet(j)][i];
									}else{
										tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][opNum(i)][i];
										tmp += dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][opNum(j)][i];
									}
								}		
							}else{ 
								tmp = dp[va-(j==0)][vb-(j==1)][vc-(j==2)][vd-(j==3)][opFul(i)][i];
							}
							dp[va][vb][vc][vd][i][j] = tmp%mod;
						}
					}
				}
			}
		}
	}
	int wyn = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			wyn+=dp[a][b][c][d][i][j];
		}
	}
	cout<<wyn%mod;
	return 0;
}
