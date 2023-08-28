class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    string b;

private:
    void dfs(vector<string> seq, string word) {
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int n = word.size();
        int steps = mp[word];

        for(int i=0;i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(mp.find(word)!=mp.end() && mp[word]+1 == steps) {
                    seq.push_back(word);
                    dfs(seq, word);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        mp[beginWord] = 1;
        st.erase(beginWord);
        q.push(beginWord);
        b = beginWord;

        int n = beginWord.size();
        while(!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word == endWord) {
                break;
            } 

            for(int i=0;i<n; i++) {
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }

        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(seq, endWord);
        }
        return ans;
    }
};
