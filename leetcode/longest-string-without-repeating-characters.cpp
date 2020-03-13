class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> startingPoint;
        int maxSize = 0, size = 0;
        
        for(int i=0; i<s.length(); ++i){
            if(startingPoint.find(s[i]) != startingPoint.end()){
                maxSize = size > maxSize ? size : maxSize;
                
                for(map<char, int>::iterator it=startingPoint.begin(); it!=startingPoint.end(); ){
                    if(it->second < startingPoint[s[i]]){
                        startingPoint.erase(it++);
                    }else{
                        ++it;
                    }
                }
                
                size = i - startingPoint[s[i]];
            }else{
                ++size;
            }
            
            startingPoint[s[i]] = i;
        }
       
        for(map<char, int>::iterator it=startingPoint.begin(); it!=startingPoint.end(); ++it){
            size = s.length() - it->second;
            maxSize = size > maxSize ? size : maxSize;
        }
       
        return maxSize;
    }
};
