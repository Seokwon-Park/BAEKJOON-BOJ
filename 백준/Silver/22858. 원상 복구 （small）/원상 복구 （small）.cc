#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}


	for (int i = 0; i < k; i++)
	{
		vector<int> tmp(n);
		for (int j = 0; j < n; j++)
		{
			int sendToIndex = d[j]-1;
			tmp[sendToIndex] = s[j];
		}
		s.swap(tmp);
	}
	for (int i : s)
		cout << i << ' ';


	return 0;
}

