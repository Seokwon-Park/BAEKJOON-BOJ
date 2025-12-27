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

vector<vector<ll>> b(8, vector<ll>(8, 0));

//0: 정보 1: 전산 2: 미래 3:신양 4: 한경직 5: 진리 6: 학생 7: 형남

void connect(int u, int v)
{
	b[u][v] = 1;
	b[v][u] = 1;
}

vector<vector<ll>> multiply(const vector<vector<ll>>& x, const vector<vector<ll>>& y)
{
	vector<vector<ll>> ret(8, vector<ll>(8, 0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				ret[i][j] += x[i][k] * y[j][k];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

vector<vector<ll>> fastpow(vector<vector<ll>> x, int exp)
{
	vector<vector<ll>> ret(8, vector<ll>(8, 0));
	for (int i = 0; i < 8; i++)
	{
		ret[i][i] = 1;
	}
	auto n = x;
	while (exp)
	{
		if (exp % 2)
		{
			ret = multiply(ret, n);
		}
		n = multiply(n, n);
		exp /= 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d;
	cin >> d;
	
	connect(0, 1);
	connect(0, 2);
	connect(1, 2);
	connect(1, 3);
	connect(2, 3);
	connect(2, 4);
	connect(3, 4);
	connect(3, 5);
	connect(4, 5);
	connect(4, 7);
	connect(5, 6);
	connect(6, 7);

	auto ans = fastpow(b, d);
	cout << ans[0][0];


	return 0;
}
