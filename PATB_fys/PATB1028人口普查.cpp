#include <bits/stdc++.h>
using namespace std;

int year(string a) { return stoi(a.substr(0, 4)); }
int moon(string a) { return stoi(a.substr(5, 2)); }
int day(string a) { return stoi(a.substr(8, 2)); }

int isOK(string a)
{
    if ((year(a) > 1814 && year(a) < 2014) || (year(a) == 1814 && (moon(a) > 9 || (moon(a) == 9 && day(a) >= 6))) || (year(a) == 2014 && (moon(a) < 9 || (moon(a) == 9 && day(a) <= 6))))
        return 1;
    return 0;
}

int cmp(string a, string b)
{
    if (year(a) == year(b))
    {
        if (moon(a) == moon(b))
        {
            return day(a) < day(b);
        }
        else
        {
            return moon(a) < moon(b);
        }
    }
    return year(a) < year(b);
}

int main()
{
    int N, sum = 0;
    cin >> N;
    string names, dates, minname, mindate = "1814/09/05", maxname, maxdate = "2014/09/07";
    
    for (int i = 0; i < N; i++)
    {
        cin >> names >> dates;
        if (isOK(dates))
        {
            if(sum==0){
                maxname=minname=names;
                maxdate=mindate=dates;
            }
            sum++;
            mindate = cmp(dates, mindate) ? mindate : dates;
            minname = cmp(dates, mindate) ? minname : names;
            maxdate = cmp(maxdate, dates) ? maxdate : dates;
            maxname = cmp(maxdate, dates) ? maxname : names;
        }
    }
    //cout<<sum<<" "<<maxdate<<" "<<mindate<<endl;

    cout << sum ;
    if(sum>0){
    cout<< " " << maxname << " " << minname;
    }
    return 0;
}