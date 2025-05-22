#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> gunnar;
	for (int i = a; i <= b; i++)
	{
		for (int j = c; j <= d; j++)
		{
			gunnar.push_back(i + j);
		}
	}

	int e, f, g, h;
	cin >> e >> f >> g >> h;
	vector<int> emma;
	for (int i = e; i <= f; i++)
	{
		for (int j = g; j <= h; j++)
		{
			emma.push_back(i + j);
		}
	}

	int total = gunnar.size() * emma.size();

	int draw = 0;
	int gwin = 0;
	int ewin = 0;
	for (int i = 0; i < gunnar.size(); i++)
	{
		for (int j = 0; j < emma.size(); j++)
		{
			if (gunnar[i] > emma[j])
				gwin++;
			else if (gunnar[i] == emma[j])
				draw++;
			else
				ewin++;
		}
	}

	if (gwin > ewin)
	{
		cout << "Gunnar";
	}
	else if(gwin == ewin)
	{
		cout << "Tie";
	}
	else
	{
		cout << "Emma";
	}

	return 0;
}
