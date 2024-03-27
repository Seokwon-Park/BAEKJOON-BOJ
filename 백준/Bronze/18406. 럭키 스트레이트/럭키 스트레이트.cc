#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();

	string a = s.substr(0, n / 2);
	string b =s.substr(n / 2);
	
	int aa = 0;
	int bb = 0;
	for (int i = 0; i < n / 2; i++)
	{
		aa += a[i] - '0';
		bb += b[i] - '0';
	}
	if (aa == bb)
		cout << "LUCKY";
	else
		cout << "READY";


	return 0;
}