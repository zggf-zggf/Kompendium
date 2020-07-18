#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin>>n>>m;
	vector<int> inp;
	int sum = 0;
	for(int i = 0;i < m; i++){
		int a; cin>>a;
		sum+=a;
		inp.push_back(a);
	}
	vector<int> tab(n+1), cur(n+1);	
	for(int i = 0; i < m; i++){
		int a; cin>>a;
		tab[a] = inp[i];
	}

	int pocz = 0;	
	vector<int> coc;
	int wyn = 0;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		coc.push_back(a);
		cur[a]++;
		while(cur[a]>tab[a]){
			cur[coc[pocz]]--;
			pocz++;
		}
		if(i-pocz+1==sum) wyn++;
	}		
	cout<<wyn;
	return 0;
}
