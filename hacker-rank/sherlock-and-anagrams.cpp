#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string, int> anagrams;
    int count = 0;
    string currSubstr;

    for(int i=1; i<s.length(); ++i){
        for(int j=0; j<s.length(); ++j){
            if(j+i > s.length()) break;
            
            currSubstr = s.substr(j, i);
            sort(currSubstr.begin(), currSubstr.end());
            if(anagrams.find(currSubstr) != anagrams.end()) {
                count += anagrams[currSubstr];
                ++anagrams[currSubstr];
            }
            else anagrams[currSubstr] = 1;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

