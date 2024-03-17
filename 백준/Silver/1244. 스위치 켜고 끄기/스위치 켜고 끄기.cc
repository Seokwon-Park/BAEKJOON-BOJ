#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vec<int> v(n+1);
	for(int i =1; i<=n; i++)
	{
		cin >> v[i];
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int gen, num;
		cin >> gen >> num;
		if (gen == 1)
		{
			for (int i = num; i <= n; i += num)
			{
				v[i] = 1 - v[i];
			}
		}
		else
		{
			int offset = 1;
			v[num] = 1-v[num];
			while(num-offset >=1 && num+offset<=n)
			{
				if (v[num - offset] == v[num + offset])
				{
					v[num - offset] = 1 - v[num - offset];
					v[num + offset] = 1 - v[num + offset];
				}
				else
				{
					break;
				}
				offset++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}

	return 0;
}