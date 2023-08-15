// https://www.hackerrank.com/challenges/time-conversion/problem
string timeConversion(string s) {
    string hour = s.substr(0, 2);
    if(s[s.length()-2] == 'A' && hour == "12") {
        return "00" + s.substr(2, s.length()-4);
    } else if(s[s.length()-2] == 'P' && hour != "12") {
        int hourInt = std::stoi(hour);
        return std::to_string(hourInt+12) + s.substr(2, s.length()-4);
    }

    return s.substr(0, s.length()-2);
}
