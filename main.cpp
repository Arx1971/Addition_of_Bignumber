#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <iostream>
using namespace std;

#define INF_MAX 	2147483647
#define INF_MIN 	-2147483648
#define pb push_back
#define all(x) x.begin(),x.end()
#define distSqr(x1,y1,x2,y2) (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
#define dist(x1,y1,x2,y2) sqrt(distSqr(x1,y1,x2,y2))
#define Set(x,v) memset(x,v,sizeof x)
#define For(i,s,e) for(i=s;i<=e;i++)
#define lb lower_bound
#define ub upper_bound
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1)
#define mp make_pair
#define pos first
#define val second
#define error 1e-12
//#define mod 1000000007
#define nl printf("\n")

typedef long long ll;

void string_to_number(string a,vector <int> &n)
{
    int hand ;
    for(int i=0; i<a.size(); i++)
    {
        hand = (a[i]-'0');
        n.push_back(hand);
    }
    return;
}
void addzero(vector < int > &number,int n)
{

    for(int i=number.size()-1; i < n-1; i++)
    {
        number.push_back(0);
    }
    for(int i=0,j=number.size()-1; i<j; i++,j--)
    {
        swap(number[i],number[j]);
    }
}
int main()
{
    string num_1,num_2;

    vector < int > n1;
    vector < int > n2;
    vector < int > sum;


    int hand, temp, mid, add,mod,div;

    while(cin >> num_1 >> num_2)
    {
        n1.clear();
        n2.clear();
        sum.clear();

        cout << "The Addition of " << num_1 << " And " << num_2 << " is " << endl;

        string_to_number(num_1,n1);
        string_to_number(num_2,n2);

        if(n1.size()>n2.size())
            addzero(n2,n1.size());
        else if(n1.size()<n2.size())
            addzero(n1,n2.size());

        for(int i=n1.size()-1; i>=0; i--)
        {
            hand = n1[i] + n2[i];

            if(hand<=9)
                sum.push_back(hand);

            else
            {
                if(i!=0)
                {
                    mod = hand%10;
                    div = hand/10;
                    sum.push_back(mod);
                    n1[i-1] = n1[i-1] + div;
                }
                else
                    sum.push_back(hand);
            }
        }
        reverse(sum.begin(),sum.end());
        cout << " = ";
        for(int i=0; i<sum.size(); i++)
            cout << sum[i];
        cout << "\n" << "Total Digit = " << sum.size() << endl;
    }
    cout << endl;
    return 0;
}
