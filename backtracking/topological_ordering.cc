#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> parint;


void write(const vector<int>& res){
	for (int i = 0; i < (int)res.size(); ++i) {
		if(i == 0)
			cout << res[i];
		else
			cout << " " << res[i];
	}
	cout << endl;
}

bool priority(const set<parint>& s, int i, int j, const vector<int>& res){
	return (s.find({i, j}) != s.end());
}

void topological(vector<int>& res, const set<parint>& s, int i){
	int n = (int)res.size();
	if(i == n){
		write(res);
		return;
	}
	for(int j = 0; j < n; j++){
		if(not priority(s, res[i], j, res)){
			res[i] = j;
			topological(res, s, i+1);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	set<parint> s;
	vector<int> res(n, 0);
	int s1, s2;
	for (int i = 0; i < m; ++i) {
		cin >> s1 >> s2;
		s.insert({s1, s2});
	}
	topological(res, s, 0);
}