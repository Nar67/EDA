#include <iostream>
#include <vector>
using namespace std;


void zeros_uns(vector<int>& v, int i){
	int n = (int)v.size();
	if(i == n){
		bool primer = true;
		for (int j = 0; j < n; ++j) {
			if(primer){
				primer = false;
				cout << v[j];
			}
			else
				cout << ' ' << v[j];
		}
		cout << endl;
	}
	else{
		v[i] = 0;
		zeros_uns(v, i+1);
		v[i] = 1;
		zeros_uns(v, i+1);
	}
}




int main(){
	int n;
	cin >> n;
	vector<int> v(n, 0);
	zeros_uns(v, 0);

}