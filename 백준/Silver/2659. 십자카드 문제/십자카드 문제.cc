#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int isused[10000];

int findmin(string s)
{
	int ret = stoi(s);
	for (int i = 0; i < 3; i++)
	{
		s = s.substr(1) + s[0];
		ret = min(stoi(s), ret);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	for (int i = 0; i < 4; i++)
	{
		int n;
		cin >> n;
		s.push_back(n + '0');
	}
	int ori = findmin(s);

	int cnt = 0;
	for (int i = 1111; i < ori; i++)
	{
		string num = to_string(i);
		if (count(num.begin(), num.end(), '0'))continue;
		int res = findmin(num);
		if (isused[res]) continue;
		isused[res] = true;
		cnt++;
	}

	cout << cnt + 1;


	return 0;
}