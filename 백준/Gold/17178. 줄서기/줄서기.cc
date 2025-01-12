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

	int n;
	cin >> n;
	std::queue<string> q;
	std::stack<string> waiting;
	std::vector<string> sorted;
	for (int i = 0; i < n * 5; i++)
	{
		string s;
		cin >> s;
		string c(s.substr(0,1));
		string num = s.substr(2);
		num = string(3 - num.size(), '0') + num;
		q.push(c + num);
		sorted.push_back(c + num);
	}
	sort(sorted.begin(), sorted.end());
	
	int ix = 0;
	while (!q.empty() || !waiting.empty())
	{
		if (!q.empty())
		{
			if (q.front() != sorted[ix])
			{
				if (!waiting.empty())
				{
					if (waiting.top() == sorted[ix])
					{
						waiting.pop();
						ix++;
					}
					else
					{
						waiting.push(q.front());
						q.pop();
					}
				}
				else
				{
					waiting.push(q.front());
					q.pop();
				}
			}
			else
			{
				q.pop();
				ix++;
			}
		}
		else
		{
			if (!waiting.empty())
			{
				if (waiting.top() == sorted[ix])
				{
					waiting.pop();
					ix++;
				}
				else
				{
					cout << "BAD";
					return 0;
				}
			}
			else
			{
				cout << "BAD";
				return 0;
			}
		}
	}
	cout << "GOOD";

	return 0;
}