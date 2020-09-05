#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n; cin>>n;
	long long wyn = 0;
	for(long long i = 2; i*i<=n; i++){
		if(n%i==0)wyn++;
		while(n%i==0){
			n/=i;
		}
	}
	if(n>1) wyn++;
	cout<<wyn;
			
	return 0;
}
