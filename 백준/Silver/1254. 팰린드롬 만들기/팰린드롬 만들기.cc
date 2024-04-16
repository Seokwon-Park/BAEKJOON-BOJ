#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	for (int mid = n / 2; mid < n; mid++)
	{
		//even
		int off = 0;
		bool isEvenPelin = true;
		while (mid + off < n)
		{
			if (s[mid + off] != s[mid - off - 1])
			{
				isEvenPelin = false;
				break;
			}
			off++;
		}
		if (isEvenPelin)
		{
			cout << mid * 2;
			break;
		}

		off = 1;
		bool isOddPelin = true;
		while (mid + off < n)
		{
			if (s[mid + off] != s[mid - off])
			{
				isOddPelin = false;
				break;
			}
			off++;
		}
		if (isOddPelin)
		{ 
			cout << mid * 2 + 1;
			break;
		}
		
	}

	return 0;
}
