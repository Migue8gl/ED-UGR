#include <iostream>
#include <queue>
using namespace std;

class miComp {
public:
	bool operator()(const string &a, const string &b) {
		bool comp = true;
		int cont1 = 0, cont2 = 0;

		for (int i = 0; i < a.size(); i++)
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
				cont1++;

		for (int i = 0; i < b.size(); i++)
			if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
				cont2++;

		if (cont1 > cont2)
			comp = false;
		else if (cont1 == cont2)
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