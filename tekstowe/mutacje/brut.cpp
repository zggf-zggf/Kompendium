#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> tab1, tab2;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		tab1.push_back(a);
	}
	int m; cin>>m;
	for(int i = 0; i < m; i++){
		int a; cin>>a;
		tab2.push_back(a);
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int rep = -1, por = 0;
		int a, b, c; cin>>a>>b>>c;
		a--; b--;
		bool pos = true;
		for(int j = 0; j < c; j++){
			if(tab1[a+j]!=tab2[b+j]){
				if(rep==-1){
					rep = tab1[a+j];
					por = tab2[b+j];
				}
				if(rep!=tab1[a+j]) {pos = false; break;}
				else if(tab2[b+j]!=por) {pos = false; break;}
			}
		}
		if(pos) cout<<"TAK\n";	
		else cout<<"NIE\n";
	}
	return 0;
}
