#include <bits/stdc++.h>

using namespace std;

vector<int> parent(1e5+1, -1), ranga(1e5+1), roz(1e5+1, 1);
unordered_map<int, int> ile;

int find(int x){
	if(parent[x]==-1) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void join(int a, int b){
	int va = find(a), vb = find(b);
	if(va==vb) return;
	if(ranga[va]>ranga[vb]){
		parent[vb] = va;
		ile[roz[va]]--;
		ile[roz[vb]]--;
		roz[va]+=roz[vb];
		ile[roz[va]]++;
	}else if(ranga[va]<ranga[vb]){
		parent[va] = vb;
		ile[roz[va]]--;
		ile[roz[vb]]--;
		roz[vb]+=roz[va];
		ile[roz[vb]]++;
	}else{
		parent[va] = vb;
		ile[roz[va]]--;
		ile[roz[vb]]--;
		roz[vb]+=roz[va];
		ile[roz[vb]]++;
		ranga[vb]++;
	}
}					

int main(){
	ile[1] = 100000;
	int t; cin>>t;
	for(int i = 0; i < t; i++){
		int a; cin>>a;
		if(a==0){
			int k, l; cin>>k>>l;
			join(k, l);
		}else{
			int k; cin>>k;
			cout<<ile[k]<<endl;
		}
	}
	
	return 0;
}
