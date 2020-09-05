#include <bits/stdc++.h>

using namespace std;
vector<int> parent, ranga, val;

int find(int x){
	if(parent[x] == -1) return x;
	int tmp = parent[x];
	parent[x] = find(parent[x]); 
	val[x]+=val[tmp];
	return parent[x];
}

int main(){
	int n, q; cin>>n>>q;
	parent.resize(n+1, -1); val.resize(n+1);
	for(int i = 0; i < q; i++){
		int a, b, c; cin>>a>>b>>c;
		int va = find(a), vb = find(b);
		if(va==vb){
			
			if(val[va]+(c+val[b]-val[a])==val[vb]) cout<<"TAK\n";
			else cout<<"NIE\n";
		}else{
			cout<<"TAK\n";
			val[va]+=(c+val[b]-val[a]);
			parent[va] = vb;	
		}
	}
}
