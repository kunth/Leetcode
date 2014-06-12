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

//SECOND TRIAL
//剪枝再二分搜索
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col-1;
        while(r < row && c>=0)
        {
            if(matrix[r][c] > target)
            {
                if(matrix[r][0]>target)
                    return false;
                else if(matrix[r][0]<target)
                {
                    int i = 1, j = c-1;
                    while(i<=j)
                    {
                        int mid = (i+j)/2;
                        if(matrix[r][mid]>target)
                            j = mid-1;
                        else if(matrix[r][mid]<target)
                            i = mid+1;
                        else
                            return true;
                    }
                    return false;
                }
                else
                    return true;
            }
            else if(matrix[r][c] < target)
                ++r;
            else
                return true;
        }
        return false;
    }
};

//Thrid trial
//剪枝再线性搜索, 比上一个要差
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col-1;
        while(r < row && c>=0)
        {
            if(matrix[r][c] > target)
                --c;
            else if(matrix[r][c] < target)
                ++r;
            else
                return true;
        }
        return false;
    }
};
