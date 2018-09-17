/**
 * 一开始想着用一个set就能记录，后来发现，如果word在dic里出现了，这种情况应该返回true，于是只能用一个map记录
 * abbreviation和有哪些单词是这个abbreviation
 */


class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> abbreviation;

    ValidWordAbbr(vector<string> dictionary) {
        for (string s : dictionary) {
            string abb = "";
            if (s.length() < 3) {
                abb = s;
            } else {
                abb = s[0] + to_string(s.length() - 2) + s[s.length() - 1];
            }
            abbreviation[abb].insert(s);
        }
    }

    bool isUnique(string word) {
        string abb = "";
        if (word.length() < 3) {
            abb = word;
        } else {
            abb = word[0] + to_string(word.length() - 2) + word[word.length() - 1];
        }
        return (abbreviation.find(abb) == abbreviation.end()) || (abbreviation[abb].size() == 1 && abbreviation[abb].count(word) == 1);

    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
