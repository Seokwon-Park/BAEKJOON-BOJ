#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string m[256];
	m['M'] = "MatKor";
	m['W'] = "WiCys";
	m['C'] = "CyKor";
	m['A'] = "AlKor";
	m['$'] = "$clear";
	char c;
	cin >> c;
	cout << m[c];

	return 0;
}