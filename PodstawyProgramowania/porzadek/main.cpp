#include <bits/stdc++.h>

using namespace std;
long long pot(long long x){
	long long tmp = 1;
	while(x){
		x/=2;
		tmp*=2;
	}
	return tmp;
}
long long treeSize;
vector<long long> tree, roz, inw;

int main(){
	ios_base::sync_with_stdio(0);
	long long n; cin>>n;

	treeSize = pot(n);	
	tree.resize(treeSize*2+1);
	inw.resize(treeSize*2+1);
	roz.resize(treeSize*2+1, 1);

	long long lst = -1;
	for(long long i = 0; i < n; i++){
		char c; cin>>c;
		if(c=='N') tree[i+treeSize] = 1; 	
	}
	for(long long i = treeSize-1; i > 0; i--){
		roz[i] = roz[i*2]*2;
		tree[i] = tree[i*2]+tree[i*2+1];
		inw[i] = (roz[i*2]-tree[i*2]) * tree[i*2+1] + inw[i*2] + inw[i*2+1];		
	}
	long long q; cin>>q;
	for(long long i = 0; i < q; i++){
		long long a, b; cin>>a>>b;
		a--; b--;
		long long va = a+treeSize, vb = b+treeSize;
		long long wyn = 0;
		long long zer = 1-tree[va];
		long long jed = tree[vb];

		while(va/2!=vb/2){
			if(va%2==0){
				 wyn += zer*tree[va+1];
				 zer+=roz[va+1]-tree[va+1];
				 wyn += inw[va+1];
			}
			if(vb%2==1){ 
				 wyn+= (roz[vb-1]-tree[vb-1])*jed;
				 jed+=tree[vb-1]; 	
				 wyn += inw[vb-1];
			}
			va/=2; vb/=2;
		}
		cout<<wyn+jed*zer<<endl;
	}
	return 0;
}
