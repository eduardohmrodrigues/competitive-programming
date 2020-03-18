#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    map<long, vector<long>> mp;
    long long count = 0, curr, i, j, k;

    for(long long a=0; a<arr.size(); ++a){
        i = arr[a];
        if(mp.find(i) == mp.end()){
             mp[i] = vector<long>();
        }
        mp[i].push_back(a);
    }
    
    if(r == 1){
        for(map<long, vector<long>>::iterator it=mp.begin(); it!= mp.end(); ++it){
            while(it->second.size() > 2){
                for(int i=it->second.size()-2; i>0; --i){
                    count += i;
                }
                it->second.erase(it->second.begin());
            }
        }
    }else{
        for(long long a=0; a<arr.size(); ++a){
            i = arr[a]; j = i*r; k = j*r;
            mp[i].erase(mp[i].begin());
            if(mp.find(j)!=mp.end() && mp.find(k)!=mp.end()){
                count += mp[j].size()*mp[k].size();
            }
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

