#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> conv;
int n,m;
unordered_map<int, int> valid;
long long mat[63][145][145];
long long roz, mod = 1e9+9;
int cur = 2;

bool val(int a){
	if(n==2) return a!=3;
	if(valid[a]==0){
		valid[a] = 1;
		for(int i = 1; i < n-1; i++){
			if(a&(1<<i)){
				if((a&(1<<(i-1)))||(a&(1<<(i+1)))){ valid[a] = 2; break;}	
			}
		}
	}
	return valid[a]==1;
}

bool pos(int a, int b){
	bool pos = true;
	if(__builtin_popcount(b)<__builtin_popcount(a)) swap(a, b);
	for(int i = 0; i < n; i++){
		if(a&(1<<i)){
			if(b&(1<<i)){ pos = false; break;}
			if(i<n-1)if(b&(1<<(i+1))){ pos = false; break;}
			if(i>0)if(b&(1<<(i-1))){ pos = false; break;}	
		}
	}
	return pos;
}


void pot(int k){
	if(conv[k]!=0) return;
	conv[k] = cur;
	cur++;
	int cr=cur-1, nx;
	if(k%2==0){
		pot(k/2);
		nx=conv[k/2];
		for(int i = 0; i < roz; i++){
			for(int j = 0; j < roz; j++){
				for(int o = 0; o < roz; o++){
					mat[cr][i][j] += ((mat[nx][i][o])*(mat[nx][o][j]))%mod;	
				}
				(mat[cr][i][j])%=mod;
			}
		}
	}else{
		pot(k-1);
		nx=conv[k-1];
		for(int i = 0; i < roz; i++){
			for(int j = 0; j < roz; j++){
				for(int o = 0; o < roz; o++){
				if(mat[1][o][j]) mat[cr][i][j] += mat[nx][i][o];	
				}
				(mat[cr][i][j])%=mod;
			}
		}
	}
}
		
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	int sum = 0;	
	vector<int> nodes;
	for(int i = 0; i < (1<<n);i++){
		if(val(i)) nodes.push_back(i);
	}
	conv[1] = 1;
	roz = nodes.size();
	for(int i = 0; i < roz; i++){
		for(int j = i; j < roz; j++){
			mat[1][i][j] = pos(nodes[i], nodes[j]);
			mat[1][j][i] = mat[1][i][j];
		}
	}

	pot(m);
	long long wyn = 0;
	for(int i = 0; i < roz; i++){
		wyn+=mat[conv[m]][0][i];
	}
	wyn%=mod;
	cout<<wyn;
	return 0;
}
