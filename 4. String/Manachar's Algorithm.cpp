#define MX 100005

string str;
int d1[MX], d2[MX];

void manachar(int n)
{
	int i, k, l, r;

	for(i=0, l=0, r=-1; i < n; i++)
	{
		k = (i>r) ? 1 : min(d1[l+r-i], r-i+1);

		while(0 <= i-k && i+k < n && str[i-k] == str[i+k])
			k++;
		d1[i] = k--;

		if(i+k > r) {
			l = i-k;
			r = i+k;
		}
	}

	for(i=0, l=0, r=-1; i < n; i++)
	{
		k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);

		while(0<=i-k-1 && i+k < n && str[i-k-1] == str[i+k])
			k++;
		d2[i] = k--;

		if(i+k > r) {
			l = i-k-1;
			r = i+k;
		}
	}
}
