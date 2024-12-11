#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> v(10);
vector<int> vm(10);

int invf(string x)
{
	int ret = 0;
	vector<int> va;
	for (int i = 0; i < x.size(); i++)
	{
		va.push_back(x[i] - '0');
	}

	for (int i = 0; i < va.size(); i++)
	{
		 ret = ret * 10 + vm[va[i]];
	}
	return ret;
}

string f(string x)
{
	string ret;
	for (int i = 0; i < x.size(); i++)
	{
		ret += v[x[i]-'0']+'0';
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	for (int i = 0; i < 10; i++)
	{
		cin >> v[i];
		vm[v[i]] = i;
	}
	string fa, fb;
	cin >> fa >> fb;


	int a = invf(fa);
	int b = invf(fb);
	
	cout << f(to_string(a + b));

	return 0;
}



