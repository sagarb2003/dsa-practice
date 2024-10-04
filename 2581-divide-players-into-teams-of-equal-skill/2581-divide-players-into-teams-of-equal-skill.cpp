class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        int prevSum=skill[i]+skill[j];
        while(i<j){
            int currSum=skill[i]+skill[j];
            if(prevSum != currSum){
                return -1;
            }
            ans+=skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;
    }
};