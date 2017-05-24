#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

double const infinity = 99999999999;

typedef pair<double,int> par;

void dijkstra(const vector<vector<par>>& arc, int x, int y){
	//int total_cost = 0;
	int n = (int)arc.size();
	vector<double> d(n, infinity);
	vector<int> sol(n, -1);
	d[x] = 0;
	vector<bool> s(n, false);
	priority_queue<par, vector<par>, greater<par> > q;
	q.push({0, x});
	while(not q.empty()){
		int u = q.top().second;
		q.pop();
		if(not s[u]){
			s[u] = true;
			if(u == y){
				stack<int> pila;
		    	while (y != x) {
		        	pila.push(y);
		        	y = sol[y];
		    	}
			    pila.push(y);
			    cout << "cost " << d[u] << ", " << pila.size()-1 << " step(s)" << endl;
				return;
			}
			for(auto a : arc[u]){
				int v = a.second;
				double cost = a.first;
				if(d[v] > d[u] + cost){
					d[v] = d[u] + cost;
					sol[v] = u;
					q.push({d[v], v});
				}
			}
		}
	}
	cout << "no path from " << x << " to " << y << endl;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		vector<vector<par>> arc(n);
		for(int i = 0; i < m; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			arc[u].push_back({w, v});
		}
		int x, y;
		cin >> x >> y;
		dijkstra(arc, x, y);
	}

}