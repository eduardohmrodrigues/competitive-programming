#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int indexer = 0, valleys = 0;
    bool wasBellow = false;
    for(int i=0; i<n; ++i){
        wasBellow = indexer < 0;
        if(s[i] == 'U') ++indexer;
        else --indexer;
        
        if(indexer == 0 && wasBellow) ++valleys;
    }

    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

