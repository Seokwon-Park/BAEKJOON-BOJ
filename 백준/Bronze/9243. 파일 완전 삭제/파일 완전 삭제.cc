#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool isRight = true;
	if (n % 2)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (!((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')))
			{
				isRight = false;
				break;
			}

		}
	}
	else
	{
		isRight = (a == b);
	}

	if (isRight)
		cout << "Deletion succeeded";
	else
		cout << "Deletion failed";
	
		return 0;
}
