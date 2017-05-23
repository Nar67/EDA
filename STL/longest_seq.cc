#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main(){
	string l;
	while(getline(cin, l)){
		istringstream ss(l);
		int n;
		set<int> s;
		while(ss >> n){
			s.insert(n);
		}
		auto it = s.begin();
		auto it2 = it;
		int length = 0;
		int length_aux = 0;
		while(it2 != s.end()){
			int act = *it;
			while(act%2 == *it%2 and it != s.end()){
				it++;
				length_aux++;
			}
			it2 = it;
			length = max(length_aux, length);
		}	
		cout << length << endl;
	}
}