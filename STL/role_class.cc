#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


auto cmp = [](pair<string ,int> const & a, pair<string ,int> const & b) { 
    return a.second != b.second?  a.second < b.second : a.first < b.first;}
;

int main(){
	map<string, int> m;
	string cmd;
	while(cin >> cmd){
		if(cmd == "LOGIN"){
			string name;
			cin >> name;
			if(m.find(name) == m.end())
				m.insert(make_pair(name, 1200));
		}
		else if(cmd == "LOGOUT"){
			string name;
			cin >> name;
			if(m.find(name) != m.end()){
				m.erase(name);
			}
		}
		else if(cmd == "PLAY"){
			string p1, p2;
			cin >> p1 >> p2;
			if(m.find(p1) == m.end() or m.find(p2) == m.end()){
				cout << "player (s) not connected" << endl;
			}
			else{
				m[p1] += 10;
				if(m[p2]-10 < 1200)
					m[p2] = 1200;
				else{
					m[p2] -= 10;
				}
			}
		}
		else if(cmd == "GET_ELO"){
			string name;
			cin >> name;
			cout << name << " " << m[name] << endl; 
		}
	}

	sort(m.begin(), m.end(), cmp);
	cout << "RANKING" << endl;
	for(auto it : m){
		cout << it->first << " " << it->second << endl;
	}

}