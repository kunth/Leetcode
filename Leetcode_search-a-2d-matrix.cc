class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[row-1][col-1])
            return false;
        int i = 0, endi = row-1;
        while(i<=endi)
        {
            if(target < matrix[(i+endi)/2][0])
            {
                endi = (i+endi)/2-1;
            }
            else if(target > matrix[(i+endi)/2][0])
            {
                if(target > matrix[(i+endi)/2][col-1])
                    i=(i+endi)/2+1;
                else if(target < matrix[(i+endi)/2][col-1])
                {
                    int j = 0, endj = col-1;
                    while(j<=endj)
                    {
                        if(target < matrix[(i+endi)/2][(j+endj)/2])
                        {
                            endj = (j+endj)/2-1;
                        }
                        else if(target > matrix[(i+endi)/2][(j+endj)/2])
                        {
                            j = (j+endj)/2+1;
                        }
                        else
                            return true;
                    }
                    return false;
                }
                else
                    return true;
            }
            else
                return true;
        }
        return false;
    }
};
