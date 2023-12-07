#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int tc;
	cin >> s >> tc;

	for (int i = 0; i < tc; i++)
	{
		char c;
		int st, ed;
		cin >> c >> st >> ed;
		int size = ed - st;
		int cnt = 0;
		string sub = s.substr(st, size+1);
		for (auto k : sub)
		{
			if (k == c) cnt ++;
		}
		cout << cnt << '\n';
	}


	return 0;
}