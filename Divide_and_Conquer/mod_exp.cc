#include <iostream>
using namespace std;

int power(int n, int k, int m){
	if(k == 0)
		return 1;
	int x = power(n, k/2, m);
	if(k%2 == 0){
		return (x*x)%m;
	}
	else{
		return (((x*x)%m)*n)%m;
	}

}



int main(){
	int n, k, m;
	while(cin >> n >> k >> m)
		cout << power(n, k, m) << endl;
}