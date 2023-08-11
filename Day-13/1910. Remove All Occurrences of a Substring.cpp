#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:

    string removeOccurrences(string s, string part) {

        while(s.size() != 0 && s.find(part) < s.size()){

            s.erase(s.find(part),part.length());

        }
        
        return s;

    }

};