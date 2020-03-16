#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long directOccurrences = 0, occurrences = 0, repetitions, rest;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == 'a') ++directOccurrences;
    }
    
    repetitions = floor((double)n/s.length());
    rest = n - (repetitions*s.length());
    occurrences = repetitions*directOccurrences;

    for(int i=0; i<rest; ++i){
        if(s[i] == 'a') ++occurrences;
    }
    return occurrences;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

