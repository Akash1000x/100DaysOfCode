class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Initialize a vector to map characters from 'pattern' to words from 's'
        vector<string> map(256, "0");
        
        // Create a set to keep track of words to ensure uniqueness
        set<string> check;
        
        // Vector to store individual words from 's'
        vector<string> words;
        string temp = "";

        // Tokenize 's' into words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else {
                words.push_back(temp);
                temp = "";
            }
        }
        words.push_back(temp);

        // If the number of words and characters in 'pattern' doesn't match, return false
        if (words.size() != pattern.size()) {
            return false;
        }

        // Check the mapping between 'pattern' and 's' words
        for (int i = 0; i < pattern.size(); i++) {
            // Check if the character in 'pattern' is not mapped and the word is not in 'check'
            if (map[pattern[i]] == "0" && check.find(words[i]) == check.end()) {
                // Map the character to the word and add the word to 'check'
                map[pattern[i]] = words[i];
                check.insert(words[i]);
            }

            // If the mapping doesn't match, return false
            if (map[pattern[i]] != words[i]) {
                return false;
            }
        }

        // If all checks pass, return true
        return true;
    }
};










// other solutin (using vector instead of set in check )



class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Initialize a vector to map characters from 'pattern' to words from 's'
        vector<string> map(256, "0");

        // Vector to store unique words from 's'
        vector<string> check;                        // <--- change

        // Vector to store individual words from 's'
        vector<string> words;
        string temp = "";

        // Tokenize 's' into words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);

            } else {
                words.push_back(temp);
                temp = "";
            }
        }
        words.push_back(temp);

        // If the number of words and characters in 'pattern' doesn't match, return false
        if (words.size() != pattern.size()) {
            return false;
        }

        // Check the mapping between 'pattern' and 's' words
        for (int i = 0; i < pattern.size(); i++) {
            // Search for the word in 'check'
            auto it = std::find(check.begin(), check.end(), words[i]);

            // Check if the character in 'pattern' is not mapped and the word is not in 'check'
            if (map[pattern[i]] == "0" && it == check.end()) {
                // Map the character to the word and add the word to 'check'
                map[pattern[i]] = words[i];
                check.push_back(words[i]);
            }

            // If the mapping doesn't match, return false
            if (map[pattern[i]] != words[i]) {
                return false;
            }
        }

        // If all checks pass, return true
        return true;
    }
};
