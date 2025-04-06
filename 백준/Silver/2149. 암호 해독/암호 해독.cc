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

	string key;
	cin >> key;
	string crypt;
	cin >> crypt;

	string keysort = key;
	sort(keysort.begin(), keysort.end());

	queue<char> q[26];

	int w = crypt.size() / key.size();
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < key.size(); j++)
		{
			q[keysort[j] - 'A'].push(crypt[i + j * w]);
		}
	}

	for (int i = 0; i < crypt.size(); i++)
	{
		int ix = key[i % key.size()] - 'A';
		cout << q[ix].front();
		q[ix].pop();
	}


	return 0;
}