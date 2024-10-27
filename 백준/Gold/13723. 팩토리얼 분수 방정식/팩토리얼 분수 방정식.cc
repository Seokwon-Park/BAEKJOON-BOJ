#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
using bigInt = vector<int>;
const ll base = 1e9;

// 1/x + 1/y = 1/n
// (x+y)/xy = 1/n
// (x+y)n = xy;
// n^2 = pq; 로 가정 // p,q는 n의 약수
// x = p+n, y = q+n 
// (2n + p + q)n = n^2 + (p+q)n + pq
// 두 식이 동일하다? pq는 n^2의 약수이다.

bigInt karatsuba(bigInt a, bigInt b);

bigInt IntegerToBigInteger(ll s)
{
	bigInt res;
	while (s)
	{
		res.push_back(s % base);
		s /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

bigInt stringToBigInteger(string s)
{
	bigInt res;
	while (s.size() % 9 != 0)s.insert(s.begin(), '0');
	for (int i = 0; i < s.size(); i += 9)
	{
		res.push_back(stoi(s.substr(i, 9)));
	}
	return res;
}

bigInt operator+(bigInt a, bigInt b)
{
	int n = max(a.size(), b.size());
	bigInt res(n, 0);
	while (a.size() < n)a.insert(a.begin(), 0);
	while (b.size() < n)b.insert(b.begin(), 0);
	ll carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ll x = a[i];
		ll y = b[i];
		ll tmp = (x + y + carry) % base;
		carry = (x + y + carry) / base;
		res[i] = tmp;
	}
	if (carry)
		res.insert(res.begin(), carry);
	return res;
}

bool operator<(bigInt a, bigInt b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])continue;
			return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}

bigInt operator-(bigInt a, bigInt b)
{
	bool isNeg = false;
	if (a < b)
	{
		a.swap(b);
		isNeg = true;
	}
	int n = max(a.size(), b.size());
	bigInt res(n, 0);
	while (a.size() < n)a.insert(a.begin(), 0);
	while (b.size() < n)b.insert(b.begin(), 0);
	ll carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ll x = a[i];
		ll y = b[i];
		ll tmp = x - y + carry + base;
		carry = tmp / base - 1;
		res[i] = tmp % base;
	}
	int ix = 0;
	while (ix< res.size() && res[ix] == 0)ix++;
	if(res.size())
	res = bigInt(res.begin() + ix, res.end());
	if (isNeg)
		res[0] = -res[0];
	return res;
}

bigInt operator*(bigInt a, bigInt b)
{
	return karatsuba(a, b);
}

bigInt karatsuba(bigInt a, bigInt b)
{
	bigInt ret;
	int n = max(a.size(), b.size());
	while (a.size() < n)a.insert(a.begin(), 0);
	while (b.size() < n)b.insert(b.begin(), 0);
	if (n == 1)
	{
		ll tmp = (ll)a[0] * b[0];
		bigInt result;
		if (tmp > base)
		{
			result.push_back(tmp / base);
		}
		result.push_back(tmp % base);
		return result;
	}

	int mid = n / 2;

	bigInt A, B;
	for (int i = 0; i < mid; i++)
	{
		A.push_back(a[i]);
	}
	for (int i = 0; i < n - mid; i++)
	{
		B.push_back(a[mid + i]);
	}

	bigInt C, D;
	for (int i = 0; i < mid; i++)
	{
		C.push_back(b[i]);
	}
	for (int i = 0; i < n - mid; i++)
	{
		D.push_back(b[mid + i]);
	}

	bigInt ac = karatsuba(A, C);
	bigInt bd = karatsuba(B, D);

	bigInt apb = A + B;
	bigInt cpd = C + D;

	bigInt res = karatsuba(apb, cpd);
	res = res - (ac + bd);
	for (int i = 0; i < n - mid; i++)
	{
		res.push_back(0);
	}
	for (int i = 0; i < (n - mid) * 2; i++)
	{
		ac.push_back(0);
	}
	res = res + ac;
	res = res + bd;

	int ix = 0;
	while (ix < res.size() && res[ix] == 0)ix++;
	if (ix == res.size()) 
		res = bigInt(1, 0);
	else
		res = bigInt(res.begin() + ix, res.end());

	return res;
}

ostream& operator<<(ostream& ost, bigInt& a)
{
	ost << a[0];
	for (int i = 1; i < a.size(); i++)
	{
		ost << setw(9) << setfill('0') << a[i];
	}
	return ost;
}

// 1/x + 1/y = 1/n
// (x+y)/xy = 1/n
// (x+y)n = xy;
// n^2 = pq; 로 가정 // p,q는 n의 약수
// x = p+n, y = q+n 
// (2n + p + q)n = n^2 + (p+q)n + pq
// 두 식이 동일하다? pq는 n^2의 약수이다.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> v(n+5);
	for (int i = 2; i <= n; i++)
	{
		int tmp = i;
		for (int j = 2; j <= i ; j++)
		{
			while (tmp % j == 0)
			{
				v[j]++;
				tmp /= j;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		v[i] *= 2;
	}

	bigInt res = stringToBigInteger("1");
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			bigInt tmp = IntegerToBigInteger(v[i] + 1LL);
			res = res * tmp;
		}
	}
	cout << res;



	return 0;
}