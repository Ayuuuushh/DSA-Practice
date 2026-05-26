class Solution {
public:
    bool isAnagram(string source,string destStr){
        if(source.size() != destStr.size())
            return false;

        sort(source.begin(),source.end());
        sort(destStr.begin(),destStr.end());

        for(int i=0;i<source.size();i++){
            if(source[i] != destStr[i])
            return false;
        }

       return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(), false);
       
        for(int i=0;i<strs.size();i++){
           if (visited[i]) continue;
      
           string sourceStr = strs[i];
           vector<string> temp;

           for(int j=i;j<strs.size();j++){
                if(!visited[j] && isAnagram(sourceStr,strs[j])){
                  temp.push_back(strs[j]);
                  visited[j] = true;
                }
           }

           ans.push_back(temp);
        }

        return ans;
    }
};