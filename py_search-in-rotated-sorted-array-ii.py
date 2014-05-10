class Solution:
    def bin_search(self, arr, target):
        left = 0
        right = len(arr)-1
        while left <= right:
            mid = (left+right)//2
            if target < arr[mid]:
                right = mid-1
            elif target > arr[mid]:
                left = mid+1
            else:
                return True
        return False
    # @param A a list of integers
    # @param target an integer
    # @return a boolean
    def search(self, A, target):
        if not A:
            return False
        i = 0
        while i<len(A)-1 and A[i]<=A[i+1]:
            i+=1
        if target > A[0]:
            return self.bin_search(A[:i+1], target)
        elif target < A[0]:
            return self.bin_search(A[i+1:], target)
        else:
            return True
