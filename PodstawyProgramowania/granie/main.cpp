#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	int sum = 0;
	vector<bool> tab(1e6+10);
	tab[0] = true;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		sum+=a;
		tab[sum] = true;
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a; cin>>a;
		if(tab[a]) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;
}
