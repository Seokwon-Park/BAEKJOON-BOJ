#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 1;
	long long mxval = 0;
	int mxcnt = 0;
	
	vector<long long> v;
	
	for(int i = 0; i<n; i++)
	{
		long long in;
		cin >> in;
		v.push_back(in);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++)
	{
		if (v[i-1] == v[i])
			cnt++;
		else
		{
			if (mxcnt < cnt)
			{
				mxcnt = cnt;
				mxval = v[i-1];
			}
			else if (mxcnt == cnt)
			{
				mxval = min(mxval, v[i - 1]);
			}
			cnt = 1;
		}
	}
	if (cnt > mxcnt) mxval = v[n-1];
	cout << mxval;
	
	return 0;
}

// long long 타입 잘지켜라
