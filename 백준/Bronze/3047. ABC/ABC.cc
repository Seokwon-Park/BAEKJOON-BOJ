#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(3);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	string s;
	cin >> s;
	for (auto c : s)
	{
		cout << v[c - 'A'] << ' ';
	}


	return 0;
}