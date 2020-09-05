#include <bits/stdc++.h>

using namespace std;

int pot(int x){
	int tmp = 1;
	while(x){
		tmp*=2;
		x/=2;
	}
	return tmp;
}

struct node{
	int pref, suf, best, roz, pocz;
};

vector<node> tree;
vector<int> tab;
int treeSize;

void updt(int i){
	tree[i].pocz = tree[i*2].pocz;
	tree[i].roz = tree[i*2].roz + tree[i*2+1].roz;
	tree[i].pref = tree[i*2].pref;
	if(tree[i*2].roz==tree[i*2].best&&(tab[tree[i*2+1].pocz]>tab[tree[i*2+1].pocz-1])){
		tree[i].pref = tree[i*2].roz+tree[i*2+1].pref;	
	}
	tree[i].suf = tree[i*2+1].suf;
	if(tree[i*2+1].roz==tree[i*2+1].best&&(tab[tree[i*2+1].pocz]>tab[tree[i*2+1].pocz-1])){
		tree[i].suf = tree[i*2].roz+tree[i*2].suf;	
	}
	tree[i].best = 0;
	tree[i].best = max(tree[i*2].best, tree[i*2+1].best);
	tree[i].best = max(tree[i].best, max(tree[i].pref, tree[i].suf));
	if(tab[tree[i*2+1].pocz]>tab[tree[i*2+1].pocz-1]){
		tree[i].best = max(tree[i].best, tree[i*2].suf+tree[i*2+1].pref);	
	}
}

void qur(int val, int a){
	int va = treeSize+a;
	tab[a] = val;	
	va/=2;
	while(va>0){
		updt(va);
		va/=2;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	treeSize = pot(n);
	tree.resize(treeSize*2+1);
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		tab.push_back(a);
	}
	for(int i = 0; i < treeSize*2; i++) 
		tree[i] = node{1, 1, 1, 1, i-treeSize};
	while(tab.size()<treeSize) tab.push_back(-1);
	for(int i = treeSize-1; i > 0; i--){
		updt(i);
	}	
	cout<<tree[1].best<<'\n';
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a, b; cin>>a>>b; a--;
		qur(b, a);
		cout<<tree[1].best<<'\n';
	}
	return 0;
}
