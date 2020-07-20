#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	srand(atoi(argv[3]));
	cout<<n<<" "<<m<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= m; j++){
			cout<<rand()%10+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
