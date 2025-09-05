#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v).size())
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

const char V[5] = {'a', 'i', 'u', 'e', 'o'};
const char C[5] = {'p', 't', 'k', 's', 'n'};

int n;
string l, r;

int isV(char c) {
	for (int i = 0;i <= 5 - 1;++i) {
		if (c == V[i]) return 1;
	}
	return 0;
}
int isDoubleC(char c1, char c2) {
	for (int i = 0;i <= 5 - 1;++i) {
		if ((c1 == C[i]) && (c2 == C[i])) return 1;
	}
	return 0;
}

int count(string s) {
	int ret = 0;
	int n = sz(s);
	for (int i = 0;i <= n - 1;++i) {
		if (isV(s[i])) ret++;
	}
	for (int i = 0;i <= n - 2;++i) {
		if (isDoubleC(s[i], s[i + 1])) ret++, i++;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> l >> r;
		cout << count(l) << ' ' << count(r) << endl;
	}
}