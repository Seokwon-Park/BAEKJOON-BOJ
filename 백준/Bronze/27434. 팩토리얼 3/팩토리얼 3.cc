// 참고 자료
// BIG INTEGER WITH C++ (https://codeforces.com/blog/entry/16380)
// BalkanJM - Balkan Journal of Mathematics
// 2013.001.02-A new method for fast computation of factorials of numbers
#include <bits/stdc++.h>

using namespace std;

const int base = 1e9;
using BigInt = vector<int>;
using ll = long long;



void Set(BigInt& a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt Integer(string s) {
	BigInt ans;
	if (s[0] == '-')
		return ans;
	if (s.size() == 0)
	{
		ans.push_back(0);
		return ans;
	}
	while (s.size() % 9 != 0)
		s = '0' + s;
	for (int i = 0; i < s.size(); i += 9) {
		int v = 0;
		for (int j = i; j < i + 9; j++)
			v = v * 10 + (s[j] - '0');
		ans.insert(ans.begin(), v);
	}
	Set(ans);
	return ans;
}

BigInt Integer(int x) {
	string s = "";
	while (x > 0)
	{
		s = char(x % 10 + '0') + s;
		x /= 10;
	}
	return Integer(s);
}

int operator % (BigInt a,  int b) {
	Set(a);
	if (b == 0) return -1;
	int ans = 0;
	for (int i = a.size() - 1; i >= 0; i--)
		ans = (ans * (base % b) + a[i] % b) % b;
	return ans;
}

bool operator == (BigInt a, int b) {
	return (a == Integer(b));
}

BigInt operator / (BigInt a,  int b) {
	Set(a);
	BigInt ans;
	ll cur = 0ll;
	for (int i = a.size() - 1; i >= 0; i--) {
		cur = (cur * (ll)base + (ll)a[i]);
		ans.insert(ans.begin(), cur / b);
		cur %= b;
	}
	Set(ans);
	return ans;
}

BigInt operator * (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt ans;
	ans.assign(a.size() + b.size(), 0);
	for (int i = 0; i <= a.size() - 1; i++) {
		ll carry = 0ll;
		for (int j = 0; j < b.size() || carry > 0; j++) {
			ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
			ans[i + j] = s % base;
			carry = s / base;
		}
	}
	Set(ans);
	return ans;
}

BigInt pow(BigInt a, BigInt b) {
	if (b == Integer(0)) return Integer("1");
	BigInt tmp = pow(a, b / 2);
	if (b % 2 == 0)
		return tmp * tmp;
	return tmp * tmp * a;
}

BigInt pow(int a, int b) {
	return pow(Integer(a), (Integer(b)));
}

void Print(BigInt a) {
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	for (int i = a.size() - 2; i >= 0; i--) printf("%09d", a[i]); printf("\n");
}

BigInt fct[7] = { Integer("1"),Integer("1"),Integer("2"),Integer("6"),Integer("24"),Integer("120"),Integer("720") };

BigInt RecursiveBinaryTree(vector<BigInt>& f,  int n, int m)
{
	if (m == n + 1)
		return f[n] * f[m];
	if (m == n + 2)
		return f[n] * f[n + 1] * f[m];
	int k = (n + m) / 2;
	return RecursiveBinaryTree(f, n, k) * RecursiveBinaryTree(f, k + 1, m);
}

BigInt SynchronizedBinaryTree(vector<BigInt>& f, int len)
{
	BigInt right = RecursiveBinaryTree(f, (len - 1) / 2 + 1, len - 1);
	BigInt left = RecursiveBinaryTree(f, 0, (len - 1) / 2);
	return left * right;
}


BigInt IFactorial(int& n)
{
	int eCount = 0;
	if (n % 2 == 1)  // if n is odd
		eCount = 1;

	int loop = n / 2;
	vector<BigInt> f(loop + eCount);
	f[0] = Integer(loop);
	if (eCount == 1)
		f[loop] = Integer(n);

	int i = 1;
	int s = loop;
	int r = 1;

	for (int inc = loop - 1; inc > 0; inc--)
	{
		s = s + inc;
		f[i] = Integer(s);
		while (f[i] % 2 == 0)
		{
			loop = loop + 1;
			f[i] = f[i] / 2;
		}
		i = i + 1;
	}
	return SynchronizedBinaryTree(f, f.size()) * pow(2, loop);
}

BigInt Factorial(int& n)
{
	if (n < 7)
		return fct[n];
	return IFactorial(n);
}

int main()
{
	int n;
	cin >> n;
	Print(Factorial(n));
	//BigInt test = 

	return 0;
}
