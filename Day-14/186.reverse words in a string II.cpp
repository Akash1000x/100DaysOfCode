#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
    string s = "my name is akash";
    string temp = "";
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        
        
        if (s[i] != ' ')
        {
            temp.push_back(s[i]);
        }
        else
        {
             reverse(temp.begin(), temp.end());
            ans += temp +" ";
            temp = "";
        }
    }
    reverse(temp.begin(), temp.end());
        ans += temp +" ";
        temp = "";
    cout << ans;
}