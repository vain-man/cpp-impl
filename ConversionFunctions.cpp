string convert_to_bit(int a, int bit) {
    string s;
    while (a > 0) {
        s += (a % 2) + 48;
        a /= 2;
    }
    int n = s.size();
    while (n < bit)
        s += '0';
    reverse(s.begin(), s.end());
    return s;
}
int to_int(string s)
{
    int ans = 0;
    string temp;
    int i = 0;
    while (s[i] == '0')
    {
        i++;
    }
    if (i == s.size())
        return 0;
    temp.assign(s, i, s.size());
    int mul = 1;
    for (i = temp.size() - 1; i >= 0; i--)
    {
        int a = temp[i] - '0';
        ans += mul * a;
        mul *= 10;
    }
    return ans;

}
string to_string(int n)
{
    string ans = "";
    if (n == 0)
        return "0";
    while (n > 0)
    {
        int a = n % 10;
        n /= 10;
        char temp = a + '0';
        ans += temp;
    }
    reverse(all(ans));
    return ans;
}
int bin_to_dec(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}
int binstr_to_dec(string s)
{
    int ans = 0;
    rep(i, s.size())
    if (s[i] == '1')
        ans += pow(2, s.size() - i - 1);
    return ans;
}