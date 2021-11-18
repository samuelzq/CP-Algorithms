#include <bits/stdc++.h>

using namespace std;
#define LL long long

LL fgcd(LL a, LL b)
{
	if (!a || !b)
		return a | b;
	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do {
		b >>= __builtin_ctz(b);
		if (a > b)
			swap(a, b);
		b -= a;
	} while (b);
	return a << shift;
}

LL gcd(LL a, LL b)
{
	LL m;

	if (a < b)
		swap(a, b);

	do {
		m = a % b;
		a = b;
		b = m;
	} while (m);

	return a;
}

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		LL a, b;
		cin >> a >> b;

		LL g = fgcd(a, b);
		LL m = a * b / g;

		cout << g << ' ' << m << '\n';
	}
	return 0;
}

