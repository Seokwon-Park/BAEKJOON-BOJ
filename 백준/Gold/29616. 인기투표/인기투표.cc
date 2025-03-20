#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, p;
ll v1[105];
ll v2[105];


ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> p;

	int g = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
		if (g == -1)
			g = v1[i];
		else
			g = gcd(g, v1[i]);
	}
	ll prev = 0;
	for (int i = 0; i < n; i++)
	{
		v1[i] /= g;
		prev += v1[i];
	}

	g = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> v2[i];
		if (g == -1)
			g = v2[i];
		else
			g = gcd(g, v2[i]);
	}
	ll after = 0;
	for (int i = 0; i < n; i++)
	{
		v2[i] /= g;
		after += v2[i];
	}

	bool chk = true;

	//비율이 다 투표인전보다 크면 상관이 없어.
	for (int i = 0; i < n; i++)
	{
		if (v1[i] > v2[i])
		{
			chk = false;
			break;
		}
	}

	
	if (chk)
	{
		cout << prev << ' ' << after;
	}
	// 아니라면
	else
	{

		for (int i = 0; i < n; i++)
		{
			if (v1[i] > v2[i])
			{
				bool possible = true;
				ll mul = v1[i] / v2[i];
				ll result = 0;
				if (v1[i] % v2[i] != 0)
				{
					mul += 1;
				}
				for (int j = 0; j < n; j++)
				{
					if (v1[j] > v2[j] * mul)
					{
						possible = false;
					}
					result += v2[j] * mul;
				}
				if (possible)
				{
					after = result;
				}
			}
		}
		cout << prev << ' ' << after;
	}

	return 0;
}



