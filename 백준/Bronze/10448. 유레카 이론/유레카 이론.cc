#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

vi t(1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 1; t[i - 1] + i <= 1000; i++)
	{
		t.push_back(t[i - 1] + i);
	}
	int n = t.size();
	while (tc--)
	{
		int num;
		cin >> num;
		bool find = false;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				for (int k = 1; k < n; k++)
				{
					if (t[i] + t[j] + t[k] == num)
					{
						find = true;
						break;
					}
				}
				if (find) break;
			}
			if (find)break;
		}
		if (find)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}