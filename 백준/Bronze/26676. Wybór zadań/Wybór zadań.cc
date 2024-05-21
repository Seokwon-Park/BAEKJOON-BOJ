#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(15);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int a = s[0] - '0';
		int b = s[1] - 'A';
		v[b * 5 + a-1]++;
	}

	if (count_if(v.begin(), v.end(), [](auto a) {return a > 0; }) == 15 &&
		v[4] >= 2 && v[9] >= 2 && v[14] >= 2)
		cout << "TAK";
	else
		cout << "NIE";

	return 0;
}