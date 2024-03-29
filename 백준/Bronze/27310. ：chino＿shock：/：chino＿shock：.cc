#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	int c = count(s.begin(), s.end(), ':');
	int u = count(s.begin(), s.end(), '_');
	cout << n + c + u * 5;

	return 0;
}