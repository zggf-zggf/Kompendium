#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin>>n;
	vector<int> tab;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		tab.push_back(a);
	}
	sort(tab.begin(), tab.end());
	long long wyn = 1;
	long long mod = 1e9+7;
	for(int i = tab.size()-1; i >= 0; i--){
		wyn*=tab[i]-i;
		wyn%=mod;
	}
	cout<<wyn;
	return 0;
}
