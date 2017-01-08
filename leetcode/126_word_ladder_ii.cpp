class Solution {
public:
    vector<string> neighbors(string word,
			     const unordered_set<string> &dict) {
        vector<string> neighbor_words;
        
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            for(char j = 'a'; j <= 'z'; j++) {
                if(j == c)
                    continue;
                
                word[i] = j;
                
                if(dict.find(word) != dict.end())
                    neighbor_words.push_back(word);
            }
            word[i] = c;
        }
        
        return neighbor_words;
    }

    unordered_map<string, int>
    findDistanceToWord(string word,
		       const unordered_set<string> &dict) {
        unordered_map<string, int> distances;
        
        for(const string &w: dict) {
            if(w == word)
                distances[w] = 0;
            else
                distances[w] = dict.size() + 2;
        }
        
        queue<string> q;
        
        q.push(word);
        
        while(!q.empty()) {
            string current_word = q.front();
            q.pop();
            
            int current_distance = distances[current_word];
            
            vector<string> neighbor_words = neighbors(current_word, dict);
            
            for(const string &n: neighbor_words) {
                if(distances[n] > current_distance + 1) {
                    distances[n] = current_distance + 1;
                    q.push(n);
                }
            }
        }
        
        return distances;
    }

    void findLadders(string word,
                     const unordered_map<string, int>& distances,
                     const unordered_set<string> &dict,
                     vector<string>& current_ladder,
                     vector<vector<string>>& ladders) {
        int curr_distance = distances.at(word);
        
        if(curr_distance == 0) {
            current_ladder.push_back(word);
            ladders.push_back(current_ladder);
            current_ladder.pop_back();
            return;
        }
        
        current_ladder.push_back(word);
        
        vector<string> neighbor_words = neighbors(word, dict);
        
        for(const string &n: neighbor_words) {
            if(distances.at(n) == curr_distance - 1) {
                findLadders(n, distances, dict, current_ladder, ladders);
            }
        }
        
        current_ladder.pop_back();
    }

    vector<vector<string>> findLadders(string begin, string end,
				       unordered_set<string> &dict) {
        dict.insert(begin);
        dict.insert(end);
        
        unordered_map<string, int> distances = findDistanceToWord(end, dict);
        vector<vector<string>> ladders;
	    vector<string> current_ladder;
        
        findLadders(begin, distances, dict, current_ladder, ladders);
        
        return ladders;
    }
};
