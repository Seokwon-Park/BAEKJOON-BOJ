#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool row[8];
bool col[8];
bool lurd[16];
bool ldru[16];

bool check(int r, int c)
{
	if (row[r]) return false;
	else row[r] = true;
	if (col[c]) return false;
	else col[c] = true;
	if (lurd[r-c+7]) return false;
	else lurd[r - c + 7] = true;
	if (ldru[r+c]) return false;
	else ldru[r+c] = true;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	bool isInvalid = false;
	int queen = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char x;
			cin >> x;
			if (x == '*')
			{
				queen++;
				if (!isInvalid)
				{
					if (check(i, j) == false)
					{
						isInvalid = true;
					}
				}
			}
		}
	}
	
	cout << (isInvalid || queen != 8 ? "invalid" : "valid");

	return 0;
}