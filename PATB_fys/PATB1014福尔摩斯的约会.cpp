#include <bits/stdc++.h>
using namespace std;

int main()
{
    string weekdays[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string astr, bstr, cstr, dstr;
    cin >> astr >> bstr >> cstr >> dstr;
    int lena=astr.length(),lenb=bstr.length(),lenc=cstr.length(),lend=dstr.length();
    int len1 = lena<lenb?lena:lenb;
    int len2 = lenc<lend?lenc:lend;
    int flag1 = 0, ww = 0, hh = 0, mm = 0;
    // for (int i = 0; i < len1; i++)
    // {
    //     if (flag1 == 1 && astr[i] == bstr[i] && ((astr[i] >= '0' && astr[i] <= '9') || (astr[i] >= 'A' && astr[i] <= 'N')))
    //     {
    //         if (astr[i] >= '0' && astr[i] <= '9')
    //             hh = astr[i] - '0';
    //         else if (astr[i] >= 'A' && astr[i] <= 'N')
    //             hh = 10 + astr[i] - 'A';
    //         break;
    //     }
    //     if (flag1 == 0 && astr[i] == bstr[i] && (astr[i] >= 'A' && astr[i] <= 'G'))
    //     {
    //         flag1 = 1;
    //         ww = astr[i] - 'A';
    //         astr[i]='#';
    //     }
    // }
    for (int i = 0; i < len1; i++)
    {
        
        if (astr[i] == bstr[i] && (astr[i] >= 'A' && astr[i] <= 'G'))
        {
            flag1=i;
            ww = astr[i] - 'A';
            astr[i]='#';
            break;
        }
    }
    for(int i=flag1+1;i<len1;i++)
    {
        if (astr[i] == bstr[i] && ((astr[i] >= '0' && astr[i] <= '9') || (astr[i] >= 'A' && astr[i] <= 'N')))
        {
            if (astr[i] >= '0' && astr[i] <= '9')
                hh = astr[i] - '0';
            else if (astr[i] >= 'A' && astr[i] <= 'N')
                hh = 10 + astr[i] - 'A';
            break;
        }
    } 
    cout << weekdays[ww]<<" ";
    if (hh >= 0 && hh <= 9)
    {
        cout << "0";
    }
    cout << hh << ":";
    for (int i = 0; i < len2; i++)
    {
        if (cstr[i] == dstr[i] && ((cstr[i] >= 'a' && cstr[i] <= 'z') || (astr[i] >= 'A' && astr[i] <= 'Z')))
        {
            mm = i;
            break;
        }
    }
    if (mm >= 0 && mm <= 9)
    {
        cout << "0";
    }
    cout << mm;
    return 0;
}
