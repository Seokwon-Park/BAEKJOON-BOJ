#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string ntos[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<pair<string,int>> v;
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		string num = to_string(i);
		string tmp = "";
		for (char c : num)
		{
			tmp += ntos[c - '0'];
			tmp += ' ';
		}
		tmp.pop_back(); // 마지막 공백 제거.
		v.push_back({tmp, i});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (i> 0&&i % 10 == 0) cout << '\n';
		auto [x, y] = v[i];
		cout << y << ' ';
	}


	return 0;
}