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

int unused = -1;

int ix[300005];
int val[300005];
int prv[300005];
int nxt[300005];
int st;
int en;

void sf()
{
	int sttmp = nxt[st];
	prv[sttmp] = -1;

	nxt[st] = -1;
	nxt[en] = st;
	prv[st] = en;
	en = st;
	st = sttmp;
}

void sl()
{
	int entmp = prv[en];
	nxt[entmp] = -1;

	prv[en] = -1;
	prv[st] = en;
	nxt[en] = st;
	st = en;
	en = entmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	fill(prv, prv + n, -1);
	fill(nxt, nxt + n, -1);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		unused++;
		val[unused] = x;
		ix[x] = unused;
		if (unused > 0)
		{
			prv[unused] = unused - 1;
			nxt[unused - 1] = unused;
			en = unused;
		}
	}

	int q;
	cin >> q;
	vector<int> ans;
	for (int i = 0; i < q; i++)
	{
		string s;
		cin >> s;
		if (s == "SF")
		{
			if (st == en) continue;
			sf();
		}
		else if (s == "SL")
		{
			if (st == en) continue;
			sl();
		}
		else if (s == "SM")
		{
			int x;
			cin >> x;
			int loc = ix[x];
			if (loc == st)
			{
				if (st == en) continue;
				sf();
			}
			else if (loc == en)
			{
				if (st == en) continue;
				sl();
			}
			else
			{
				if (st == en) continue;
				int ltmp = prv[loc];
				int rtmp = nxt[loc];
				nxt[loc] = st;
				prv[st] = loc;
				prv[loc] = en;
				nxt[en] = loc;

				nxt[ltmp] = -1;
				en = ltmp;
				prv[rtmp] = -1;
				st = rtmp;
			}
		}
		else if (s == "PF")
		{
			ans.push_back(val[st]);

			int sttmp = nxt[st];
			if (sttmp == -1) continue;
			prv[sttmp] = -1;
			st = sttmp;
		}
		else if (s == "PL")
		{
			ans.push_back(val[en]);

			int entmp = prv[en];
			nxt[entmp] = -1;
			en = entmp;
		}
		else if (s == "PM")
		{
			int x;
			cin >> x;
			int loc = ix[x];
			if (loc == st)
			{
				ans.push_back(val[st]);

				int sttmp = nxt[st];
				prv[sttmp] = -1;
				st = sttmp;
			}
			else if (loc == en)
			{
				ans.push_back(val[en]);
				int entmp = prv[en];
				nxt[entmp] = -1;
				en = entmp;
			}
			else
			{
				ans.push_back(x);
				int ltmp = prv[loc];
				int rtmp = nxt[loc];
				nxt[ltmp] = rtmp;
				prv[rtmp] = ltmp;
			}
		}

		/*int cur = st;
		while (cur != -1)
		{
			cout << val[cur] << ' ';
			cur = nxt[cur];
		}
		cout << '\n';*/
	}

	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}