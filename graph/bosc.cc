#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
typedef pair<int, int> parint;

int bosc(const vector<parint> v, int n){
	vector<bool> vis(n, false);
	stack<int> s;
	int cc = 0;
	for(int u = 0; u < n; u++;){
		s.push(u);
		while(not s.empty()){
			
			
		}



	}
}


int main(){
	parint p;
	vector<parint> v;
	int n, m;
	while(cin >> n >> m){
		for (int i = 0; i < m; ++i) {
			cin >> v[i].first >> v[i].second; 
		}
	}
	int res = bosc(v, n);
}