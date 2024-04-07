#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	multiset<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string m;
		cin >> m;
		s.insert(m);
	}

	for (int i = 0; i < n-1; i++)
	{
		string m;
		cin >> m;
		s.erase(s.find(m));
	}

	cout << *s.begin();

	return 0;
}