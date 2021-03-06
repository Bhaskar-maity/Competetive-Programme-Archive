// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#
// Input :
// A[] = {10, 5, 2, 7, 1, 9}
// K = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.

class Solution{
    
   
    // Function for finding maximum and value pair
    public static int lenOfLongSubarr (int A[], int N, int K) {
        //sliding window
        int i=0,j=0;
        long sum=0;
        int mx=Integer.MIN_VALUE;
        
        while(j<N){
            sum= sum + A[j];

            if(sum < K){
                j++;
            }
            else if(sum == K){
                mx=Math.max(mx, j-i+1);
                j++;
            }
            else if(sum > K){
                while(sum>K){
                    sum= sum - A[i];
                    i++;
                }
                j++;
            }
        }
        
        //if sum != K, in the end of the loop
        if(mx == Integer.MIN_VALUE) return 0;
        else
            return mx;
    }
    
    
}