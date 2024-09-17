class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        unordered_map<string, int> wordCount;
        string word;
        string word2;
        vector<string>result;
        while (ss1 >> word) {
            wordCount[word]++;
        }
        while (ss2 >> word) {
            wordCount[word]++;
        }
        for(auto it:wordCount){
            if(it.second==1) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};