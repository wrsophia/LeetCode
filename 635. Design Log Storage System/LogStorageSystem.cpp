class LogSystem {
public:
    multimap<string, int> timeIdMap;
    unordered_map<string, int> cropIndex;
    LogSystem() {
        cropIndex.insert({"Year", 4});
        cropIndex.insert({"Month", 7});
        cropIndex.insert({"Day", 10});
        cropIndex.insert({"Hour", 13});
        cropIndex.insert({"Minute", 16});
        cropIndex.insert({"Second", 19});
    }

    void put(int id, string timestamp) {
        timeIdMap.insert({timestamp, id});
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int> result;
        string cropS = s.substr(0, cropIndex[gra]);
        string cropE = e.substr(0, cropIndex[gra]);
        for (auto it = timeIdMap.begin(); it != timeIdMap.end(); ++it) {
            if (it->first.substr(0, cropIndex[gra]) >= cropS) {
                if (it->first.substr(0, cropIndex[gra]) <= cropE)
                    result.push_back(it->second);
                else
                    break;
            }
        }
        return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
