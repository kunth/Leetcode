class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        if not ratings:
            return 0
        vec = [1]*len(ratings)
        for i in range(0, len(ratings)-1):
            if ratings[i] < ratings[i+1]:
                vec[i+1] = 1 + vec[i]
        
        for i in range(len(ratings)-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                vec[i] = max(vec[i], 1+vec[i+1])
        
        return sum(vec)
