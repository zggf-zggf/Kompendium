#include <bits/stdc++.h>

using namespace std;
vector<int> rg;

int find(int x){
	if(rg[x]==-1) return x;
	rg[x] = find(rg[x]);
	return rg[x];
}

int main(){
	int n; cin>>n;	
	rg.resize(n+1, -1);
	vector<int> wart(n);
	for(int i = 0; i < n; i++){
		cin>>wart[i];	
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a, b; cin>>a>>b; a--; b--;
		int pt = a;
		while(pt<=b){
			pt = find(pt);
			if(pt>b) break;
			cout<<wart[pt]<<" ";
			rg[pt] = find(b+1);		
			pt++;
		}
		cout<<endl;
	}
}
