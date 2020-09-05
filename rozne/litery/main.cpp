#include <bits/stdc++.h>

using namespace std;
vector<int> tree;
int treeSize;

int pot(int x){
	int tmp = 1;
	while(x){
		x/=2;
		tmp*=2;
	}
	return tmp;
}

void update(int x){
	int va = treeSize+x;
	tree[va] = 0;
	va/=2;
	while(va>0){
		tree[va] = tree[va*2] + tree[va*2+1];
		va/=2;
	}
}

int qur(int a, int b){
	int va = a+treeSize, vb = treeSize+b;
	int out = tree[va];
	if(va!=vb) out+=tree[vb];
	while(va/2!=vb/2){
		if(va%2==0) out+=tree[va+1];
		if(vb%2==1) out+=tree[vb-1];
		va/=2; vb/=2;
	}		
	return out;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int n; cin>>n;
	treeSize = pot(n);	
	tree.resize(treeSize*2+1);
	for(int i = 0; i < n; i++) tree[treeSize+i] = 1;
	for(int i = treeSize-1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];
	vector<vector<int>> tab(26);
	long long wyn = 0;
	string s, t; cin>>s>>t;
	for(int i = n-1; i >= 0; i--) tab[s[i]-'A'].push_back(i);
	for(int i = 0; i < n; i++){
		int tmp = tab[t[i]-'A'].back();
		tab[t[i]-'A'].pop_back();
		wyn+=qur(0, tmp)-1;
		update(tmp);
	}
	cout<<wyn;
		
	return 0;
}
