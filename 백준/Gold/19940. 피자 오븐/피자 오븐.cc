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
using hashmap = unordered_map<key, value>;

vector<int> calc(int n)
{
	vector<vector<int>> v;
	//n에 60을 더하는 경우
	// n에 10을 더하고 1을 더하는 경우
	v.push_back({ n / 60, n % 60 / 10, 0 , n % 10, 0 });
	// n에 10을 더하고, 1을 빼는 경우
	v.push_back({ n / 60, n % 60 / 10 + 1, 0 , 0, 10 - n % 10 });

	//n에 60을 덤으로 더하는 경우
	// n에서 10을 빼고, 1을 더하는 경우
	v.push_back({ n / 60 + 1, 0, 6 - n % 60 / 10 , n % 10, 0 });
	// n에서 10을 빼고, 1을 빼는경우
	v.push_back({ n / 60 + 1, 0, 5 - n % 60 / 10 , 0, 10-n%10 });

	sort(v.begin(), v.end(), [](const auto& a, const auto& b)
		{
			int sumA = 0;
			int sumB = 0;
			for (int i = 0; i < 5; i++)
			{
				sumA += a[i];
				sumB += b[i];
			}

			if (sumA == sumB)
			{
				for (int i = 0; i < 5; i++)
				{
					if (a[i] == b[i])continue;
					return a[i] < b[i];
				}
			}
			return sumA < sumB;
		}
	);

	return v[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		auto res = calc(n);
		for (auto i : res)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}