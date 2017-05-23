#include <iostream>
#include <queue>
using namespace std;



int main(){
	priority_queue<int> pq;
	char input;
	int n;
	while(cin >> input){
		if(input == 'S'){
			cin >> n;
			pq.push(n);
		}
		else if(input == 'A'){
			if(not pq.empty())
				cout << pq.top() << endl;
			else
				cout << "error!" << endl;
		}
		else if(input == 'R'){
			if(not pq.empty())
				pq.pop();
			else
				cout << "error!" << endl;
		}
		else if(input == 'I'){
			cin >> n;
			if(not pq.empty()){
				int incr = pq.top();
				pq.pop();
				pq.push(incr+n);
			}
			else
				cout << "error!" << endl;
		}
		else{
			cin >> n;
			if(not pq.empty()){
				int incr = pq.top();
				pq.pop();
				pq.push(incr-n);
			}
			else
				cout << "error!" << endl;
		}
	}
}
