class Solution {
public:
    vector<string> neighbors(const string &word,
			     const unordered_set<string> &dict) {
        string neigh = word;
	vector<string> neighbor_words;
        
        for(int i = 0; i < word.size(); i++) {
            for(int c = 'a'; c <= 'z'; c++) {
                neigh[i] = (char)c;
                
                if(dict.find(neigh) != dict.end())
                    neighbor_words.push_back(neigh);
            }
            
            neigh[i] = word[i];
        }
        
        return neighbor_words;
    }
    
    int ladderLength(string begin, string end,
		     unordered_set<string>& dict) {
        unordered_map<string, int> distance;
	vector<string> to_expand;
	
        for(auto &word: dict) {
            distance[word] = dict.size() + 1;
        }
        
        to_expand.push_back(begin);
        distance[begin] = 1;
        
        while(!to_expand.empty()) {
            string word = to_expand.front();
            to_expand.erase(to_expand.begin());
            
            vector<string> neighbor_words = neighbors(word, dict);
            
            for(const auto &neighbor: neighbor_words) {
                if(neighbor == end)
		    return distance[word] + 1;
		
		if(distance[word] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[word] + 1;
                    to_expand.push_back(neighbor);
		}
            }
        }
        
        return 0;
    }
};
