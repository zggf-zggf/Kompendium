#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	srand(atoi(argv[2]));
	cout<<n<<endl;
	for(int i = 0; i < n; i++){
		cout<<rand()%500 + 1<<endl;
	}
	return 0;
}
