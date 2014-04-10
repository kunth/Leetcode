class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty())
            return 0;
        vector<int>vec(ratings.size(), 1);
        for(int i = 0; i<ratings.size()-1; ++i)
        {
            if(ratings[i]<ratings[i+1])
            {
                vec[i+1] = vec[i]+1;
            }
        }
        for(int i = ratings.size()-2; i>=0; --i)
        {
            if(ratings[i]>ratings[i+1])
            {
                vec[i] = max(vec[i], vec[i+1]+1);
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};
