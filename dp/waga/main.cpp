#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, r, l; cin>>n>>r>>l;
	vector<int> dpr(120001, 1e9), dpl(120001, 1e9);
	int sr = 0, sl = 0;
	int maR=60000, miR = 60000;
	int maL=60000, miL = 60000;
	dpr[60000] = 0;
	dpl[60000] = 0;

	vector<int> tmp;
	tmp = dpr;
	for(int i = 0; i < r; i++){
		tmp = dpr;
		vector<int> stck;
		vector<pair<int, int>> dos;
		for(int j = 0; j < n; j++){
			int a; cin>>a;
			sr+=a;
			stck.push_back(a);
		}
		int sum = 0;
		int macoc = -1e9, micoc = 1e9;
		for(int j = stck.size()-1; j >= 0; j--){
			sum-=stck[j];
			macoc=max(macoc, sum);
			micoc=min(micoc, sum);
			dos.push_back(make_pair(sum, stck.size()-j));	
		}
		for(int j = miR; j <= maR; j++){
			for(auto coc:dos){
				if(dpr[j]||j==60000) tmp[j+coc.first] = min(tmp[j+coc.first], dpr[j]+coc.second);
			}
		}
		maR=max(maR, maR+macoc);
		miR=min(miR, miR+micoc);
		dpr.swap(tmp);
	}
	tmp.clear();
	for(int i = 0; i < l; i++){
		tmp = dpl;
		vector<int> stck;
		vector<pair<int, int>> dos;
		for(int j = 0; j < n; j++){
			int a; cin>>a;
			sl+=a;
			stck.push_back(a);
		}
		int sum = 0;
		int macoc = -1e9, micoc = 1e9;
		for(int j = stck.size()-1; j >= 0; j--){
			sum-=stck[j];
			macoc=max(macoc, sum);
			micoc=min(micoc, sum);
			dos.push_back(make_pair(sum, stck.size()-j));	
		}
		for(int j = miL; j <= maL; j++){
			for(auto coc:dos){
				if(dpl[j]||j==60000) tmp[j+coc.first] = min(tmp[j+coc.first], dpl[j]+coc.second);
			}
		}
		maL=max(maL, maL+macoc);
		miL=min(miL, miL+micoc);
		dpl.swap(tmp);
	}
	int mini = dpr[60000-sr]+dpl[60000-sl];
	for(int i = 1+min(maR+sr, maL+sl); i >= max(sr, sl); i--){
		if(dpr[i-sr]>0&&dpl[i-sl]>0){
			mini = min(mini, dpr[i-sr]+dpl[i-sl]);
		}
	} 
	if(dpr[60000+sl-sr]>0) mini = min(mini, dpr[60000+sl-sr]);
	if(dpl[60000+sr-sl]>0) mini = min(mini, dpl[60000+sr-sl]);
	if(sl==sr) mini = 0;
	cout<<mini;
	return 0;
}
