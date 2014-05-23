class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int>res;
        if(!matrix.empty())
        {
            int row = matrix.size(), col = matrix[0].size();
            int i = 0, j = 0, tmp = 0, endi = row, endj = col;
            while(i <= endi && j <= endj)
            {
                tmp = j;
                if(tmp >= endj)
                    break;
                while(tmp<endj)
                    res.push_back(matrix[i][tmp++]);
                ++i;
                tmp = i;
                if(tmp>=endi)
                    break;
                while(tmp<endi)
                    res.push_back(matrix[tmp++][endj-1]);
                --endj;
                tmp = endj-1;
                if(tmp<j)
                    break;
                while(tmp>=j)
                    res.push_back(matrix[endi-1][tmp--]);
                --endi;
                tmp = endi-1;
                if(tmp<i)
                    break;
                while(tmp>=i)
                    res.push_back(matrix[tmp--][j]);
                ++j;
            }
        }
        return res;
    }
};
