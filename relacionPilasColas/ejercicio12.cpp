#include <iostream>
#include <queue>
using namespace std;

class miComp {
public:
	bool operator()(const string &a, const string &b) {
		bool comp = true;
		if (a.size() > b.size())
			comp = false;

		else if (a.size() == b.size())
			if (a < b)
				comp = false;

		return comp;
	}
};

int main() {
	priority_queue<string, vector<string>, miComp> cp;
	string pal;

	for (int i = 0; i < 5; i++) {
		cout << "Introduzca una palabra: ";
		cin >> pal;
		cp.push(pal);
	}

	cout << "Palabras ordenadas --> ";  
	while (!cp.empty()) {
		cout << "<" << cp.top() << "> ";
		cp.pop();
	}

	cout << endl;
}