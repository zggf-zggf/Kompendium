#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q; cin>>q>>n;
	vector<int> tab(n+1);
	int sum = 0;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		sum+=a;
		tab[i] = sum;
	}
	for(int i = 0; i < q; i++){
		int a, b; cin>>a>>b; a--; b--;
		if(a>0) cout<< tab[b]-tab[a-1]<<endl;
		else cout<<tab[b]<<endl;
	}	
	return 0;
}
