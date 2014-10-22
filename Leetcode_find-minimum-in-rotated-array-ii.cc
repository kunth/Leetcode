class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()==1)
            return num[0];
        else if(num.size()==2)
            return min(num[0], num[1]);
            
        int mid = num.size()/2;
        if(num[0] == num[mid]) {
            vector<int>vec1(num.begin(), num.begin()+mid);
            vector<int>vec2(num.begin()+mid+1, num.end());
            return min(findMin(vec1), findMin(vec2));
        } else if(num[0] < num[mid]) {
            vector<int>vec(num.begin()+mid+1, num.end());
            return min(num[0], findMin(vec));
        } else {
            vector<int>vec(num.begin(), num.begin()+mid+1);
            return findMin(vec);
        }
    }
};
