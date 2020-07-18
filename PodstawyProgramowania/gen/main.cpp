#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	long long n, k; cin>>n>>k;
	long long pocz = 0;
	vector<long long> tab;
	for(long long i = 0; i < n; i++){
		long long a; cin>>a;
		tab.push_back(a);
	}
	pocz = 0;
	for(long long i = 0;i < n; i++){
		while(pocz<n&&abs(tab[pocz]-tab[i])<=k) pocz++;
		cout<<pocz<<" ";
	}	
	return 0;

}
