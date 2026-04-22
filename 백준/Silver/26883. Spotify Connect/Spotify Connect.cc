#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; i++)
	{
		string s, type, action;
		cin >> s >> type >> action;

		int t = stoi(s);
		bool isPlay = action == "play";
		if (type == "mobile")
		{
			pq.push({ t + 100, isPlay });
		}
		else
		{
			pq.push({ t, isPlay });
		}
	}

	bool isPlaying = false;
	int startTime = 0;
	int ans = 0;
	while (!pq.empty())
	{
		auto [t, isPlay] = pq.top();
		pq.pop();
		if (isPlaying)
		{
			if (!isPlay)
			{
				isPlaying = false;
				ans += t - startTime;
			}
		}
		else
		{
			if (isPlay)
			{
				isPlaying = true;
				startTime = t;
			}
		}
	}

	cout << ans;

	return 0;
}