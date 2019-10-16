string multiply(string s, ll a)
{
	reverse(s.begin(), s.end());

	ll carry = 0;
	for(int i = 0; i < s.size(); i++) {
		carry += a * (s[i]-48);
		s[i] = (carry % 10 + 48);
		carry /= 10;
	}

	while(carry) {
		s += (carry % 10 + 48);
		carry /= 10;
	}

	reverse(s.begin(), s.end());

	return s;
}
