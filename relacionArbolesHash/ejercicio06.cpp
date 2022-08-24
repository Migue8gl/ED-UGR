#include <iostream>
#include <string>
using namespace std;

/*
 *						G
 *					   / \
 *					  E	  \
 * 			         /     \
 *                  A       M
 * 			       / \     / \
 *			      I   B   C   K
 *			    		 / \   \
 *						L   F   J
 *						 \      /
 *						  D	  H
 *
 *
 *
 *  POSTORDEN -> IBAEDLFCHJKMG
 */

int posicion(char a, string inorden) {
	int pos = -1;
	bool encontrado = false;

	for (int  i = 0; i < inorden.size() && !encontrado; i++) {
		if (inorden[i] == a) {
			pos = i;
			encontrado = true;
		}
	}

	return pos;
}

string postorden(string preorden, string inorden) {
	char root;
	string hoja;
	string leftP, rightP, leftI, rightI;
	int posRoot;

	root = preorden[0];

	if (preorden.size() >= 1)
		hoja += root;

	posRoot = posicion(root, inorden);

	if (inorden.size() < 2) {
		return hoja;
	}

	for (int i = 0; i < posRoot; i++) {
		leftP += preorden[i + 1];
		leftI += inorden[i];
	}

	for (int i = posRoot + 1; i < inorden.size(); i++) {
		rightP += preorden[i];
		rightI += inorden[i];
	}

	return postorden(leftP, leftI) + postorden(rightP, rightI) + hoja;
}

int main() {
	string pre_orden = "GEAIBMCLDFKJH";
	string in_orden = "IABEGLDCFMKHJ";
	string post_orden = "IBAEDLFCHJKMG";

	string post = postorden(pre_orden, in_orden);
	cout << post << endl;

	if (post_orden == postorden(pre_orden, in_orden))
		cout << "CORRECTO!" << endl;
	else
		cout << "INCORRECTO!" << endl;
}