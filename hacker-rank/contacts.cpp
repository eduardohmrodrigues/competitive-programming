/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */
static char END_OF_TRIE = '$';
class Trie {
    public:
    map<char, Trie> next;
    int leaves;
    Trie(){leaves = 0;}

    int insert(string str){
        int newEntryAdded = 0;
        if(str.length() == 0) {
            if(next.find(END_OF_TRIE) != next.end()) {
                return 0;
            }
            next[END_OF_TRIE] = Trie();
            return 1;
        };
        char curr = str[0];
        if(next.find(curr) == next.end()) {
            next[curr] = Trie();
        }
        
        newEntryAdded = next[curr].insert(str.substr(1, str.length()));
        next[curr].leaves += newEntryAdded;
        
        return newEntryAdded;
    }
    
    int find(string str) {
        char curr = str[0];
        if(str.length() == 1) {
            if(next.find(curr) != next.end()) return next[curr].leaves;
            else return 0;
        }

        if(next.find(curr) != next.end()) {
            return next[curr].find(str.substr(1, str.length()));
        }
        return 0;
    }
};

vector<int> contacts(vector<vector<string>> queries) {
    Trie trie;
    vector<int> res;
    string operation, value;
    for(int i=0; i<queries.size(); ++i) {
        operation = queries[i][0];
        value = queries[i][1];
        if(operation == "add") {
            trie.insert(value);
        } else {
            res.push_back(trie.find(value));
        }
    }
    
    return res;
}
