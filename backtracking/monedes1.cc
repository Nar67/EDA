#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> parint;

void monedes(int x, const vector<parint>& coins, vector<parint>& res, int i){
	int n = coins.size();
	if(i == n){
		
		return;
	}
}


int main() {
	int x, n;
	while(cin >> x >> n){
		vector<parint> m(n, {0, 0});
		for (int i = 0; i < n; ++i) {
			cin >> m[i].first;
		}
		vector<parint> res;
		monedes(x, m, res, 0);
		cout << "----------" << endl;
	}

}