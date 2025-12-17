#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

struct point
{
	int x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<point> v(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	vector<ll> sq(3);
	vector<double> len(3);
	for (int i = 0; i < 3; i++)
	{
		ll xgap = v[i].x - v[(i + 1) % 3].x;
		ll ygap = v[i].y - v[(i + 1) % 3].y;
		sq[i] = xgap * xgap + ygap * ygap;
		len[i] = sqrt((double)sq[i]);

	}

	sort(len.begin(), len.end());
	sort(sq.begin(), sq.end());
	if (len[0] + len[1] <= len[2])
	{
		cout << 'X';
	}
	else if (len[0] == len[1] && len[1] == len[2])
	{
		cout << "JungTriangle";
	}
	else if (len[0] == len[1])
	{
		if (sq[0] + sq[1] == sq[2])
		{
			cout << "Jikkak2Triangle";
		}
		else
		{
			cout << "Dunkak2Triangle";
		}
	}
	else if (len[1] == len[2])
	{
		cout << "Yeahkak2Triangle";
	}
	else
	{
		if (sq[0] + sq[1] == sq[2])
		{
			cout << "JikkakTriangle";
		}
		else if (sq[0] + sq[1] < sq[2])
		{
			cout << "DunkakTriangle";
		}
		else
		{
			cout << "YeahkakTriangle";
		}
	}
	
	return 0;
}