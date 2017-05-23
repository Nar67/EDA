#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	string name;
	map<string, int> m;
	while(cin >> name){
		string instruction;
		cin >> instruction;
		if(instruction == "enters"){
			if(m.find(name) != m.end())
				cout << name << " is already in the casino" << endl;
			else
				m.insert(make_pair(name, 0));
		}
		else if(instruction == "leaves"){
			if(m.find(name) != m.end()){
				cout << name << " has won " << m[name] << endl;
				m.erase(name);
			}
			else
				cout << name << " is not in the casino" << endl;
		}
		else if(instruction == "wins"){
			int money;
			cin >> money;
			if(m.find(name) != m.end()){
				m.find(name)->second += money;
			}
			else 
				cout << name << " is not in the casino" << endl;		
		}
	}
	cout << "----------" << endl;
	for (auto it : m) {
			cout << it.first << " is winning " << it.second << endl;
	}
}