//time complexity O(logn)
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()==1)
            return num[0];
        else if(num.size()==2)
            return min(num[0], num[1]);
            
        int mid = num.size() / 2;
        if(num[0] < num[mid]) {
            vector<int> subvec(num.begin()+mid+1, num.end());
            return min(findMin(subvec), num[0]);
        } else {
            vector<int> subvec(num.begin(), num.begin()+mid+1);
            return min(num[mid+1], findMin(subvec));
        }
    }
};
