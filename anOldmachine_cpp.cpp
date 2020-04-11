#include <bits/stdc++.h>
#include <utility>
#include<string>
#define fast ios_base::sync_with_stdio(false)
#define fastInput cin.tie(NULL)
using namespace std;
typedef unsigned long long int ll;

ll exeptionalCase(string s, ll indexValue)
{
    ll indexValue1 = -1;
    for (ll i = indexValue - 1; i >= 0; i--) {
        ll digit = s[i] - '0';
        if (digit != 8) {
            indexValue1 = i;
            break;
        }
    }
    if (indexValue1 == -1)
        return 2 * pow(10, s.length());
    ll number = 0;
    for (ll i = 0; i < indexValue1; i++)
        number = number * 10 + (s[i] - '0');
    if (s[indexValue1] % 2 == 0)
        number = number * 10 + (s[indexValue1] - '0' + 2);
    else
        number = number * 10 + (s[indexValue1] - '0' + 1);
    for (ll i = indexValue1 + 1; i < s.length(); i++)
        number = number * 10;

    return number;
}

ll smallestnumberberEven(ll n)
{
    ll number = 0;
    string s = "";
    ll temp = n;
    while (n) {
        s = char(n % 10 + 48) + s;
        n /= 10;
    }
    ll index = -1;
    for (ll i = 0; i < s.length(); i++) {
        ll digit = s[i] - '0';
        if (digit & 1) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return temp;
    if (s[index] == '9') {
        number = exeptionalCase(s, index);
        return number;
    }
    for (ll i=0;i<index;i++)
        number = number*10+(s[i] - '0');
    number = number*10+(s[index] - '0' + 1);
    for (ll i = index + 1; i < s.length(); i++)
        number = number * 10;

    return number;
}

ll largestnumberberEven(ll n)
{
    string s = "";
    ll duplicate = n;
    while (n) {
        s = char(n % 10 + 48) + s;
        n /= 10;
    }
    ll index = -1;
    for (ll i = 0; i < s.length(); i++) {
        if ((s[i] - '0') % 2 & 1) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return duplicate;

    ll number = 0;
    for (ll i = 0; i < index; i++)
        number = number * 10 + (s[i] - '0');
    number = number * 10 + (s[index] - '0' - 1);
    for (ll i = index + 1; i < s.length(); i++)
        number = number * 10 + 8;

    return number;
}


int32_t main()
{   
    fast;
    fastInput;
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++){
        ll n;
        cin>>n;
        ll small = smallestnumberberEven(n);
        ll large = largestnumberberEven(n);
        cout<<"Case #"<<test<<": ";
        if((small-n) <= (n-large))
            cout<<(small - n)<<endl;
        else
            cout<<(n-large)<<endl;
    }
    return 0;
}
