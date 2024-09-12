//152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int Max = nums[0], a = 1, b = 1;

        for(int i = 0; i < n; i++){
            a = (a == 0 ? 1 : a) * nums[i];
            b = (b == 0 ? 1 : b) * nums[n - 1 - i];
            
            Max = max(Max, max(a, b));
        }

        return Max;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Use long long to handle large products
        long long maxProd = nums[0];
        long long minProd = nums[0];
        long long result = nums[0];
        
        // Traverse the array starting from the second element
        for (int i = 1; i < n; i++) {
            // If nums[i] is negative, swap maxProd and minProd
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            // Update maxProd and minProd
            maxProd = max((long long)nums[i], maxProd * nums[i]);
            minProd = min((long long)nums[i], minProd * nums[i]);
            
            // Update the result
            result = max(result, maxProd);
        }
        
        return (int)result; // Cast back to int before returning
    }
};





//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        left[0] = height[0];

        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int ssum=0;
        for(int i=0; i<n; i++){
            ssum += (min(left[i], right[i]) - height[i]);
        }
        return ssum;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int min = height[0];
        vector<int> left;
        for(int i=0; i<height.size(); i++){
            min = max(min, height[i]);
            left.push_back(min);
        }   
        int Max = height[height.size()];
        vector<int> right;
        for(int i=height.size(); i>-0; i--){
            Max = max(Max, height[i]);
            right.push_back(Max);
        }   
        vector<int> sumarr;
        for(int i=0; i<height.size(); i++){
            int Sum = max(left[i],right[i]);
            int ans = Sum - height[i];
            sumarr.push_back(ans);
        }
        int ssum = 0;
        for(int i=0; i<sumarr.size(); i++){
            ssum += sumarr[i];
        }
        return ssum;
    }
};

//215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max=0;
        int size = nums.size();
        if(size==1){
                return 1;
        }
        int till = size-k;
        for(int i=0; i<till; i++){
            if(nums[till]){
                max=nums[till];
            }
        }
        return max;
    }
};



// Minimum Number of Pushes to Type Word II 
class Solution {
public:
    int minimumPushes(string word) {
        int arr[26] = {0}; // Initialize array with zeros
        
        for(char ch: word) {
            arr[ch - 'a']++;
        }
        
        // Convert C-style array to vector for using sort function
        vector<int> frequencies(arr, arr + 26);
        sort(frequencies.begin(), frequencies.end());
        
        int count = 0;
        int minKeyPress = 0;
        
        for(int i = 25; i >= 0; i--) {
            if(frequencies[i] == 0) break;
            int val = frequencies[i] * (count / 8 + 1);
            minKeyPress += val;
            count++; 
        }
        
        return minKeyPress;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        int arr[26];
        for(char ch: word){
            arr[ch-'a']++;
        }
        sort(arr[].begin(), arr[].end());

        int count=0;
        int minkeypress=0;

        for(int i=25; i>=0; i--){
            if(arr[i]==0) break;
            int val = arr[i]*(count/8 + 1);
            minkeypress += val;
            count++; 
        }
        return minkeypress;
    }
};


#include <unordered_map>
#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::unordered_map<char, int> keyMap = {
            {'a', 2}, {'b', 3}, {'c', 4}, {'d', 5}, {'e', 6}, {'f', 2}, {'g', 2},
            {'h', 3}, {'i', 3}, {'j', 4}, {'k', 4}, {'l', 5}, {'m', 5}, {'n', 6},
            {'o', 6}, {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7}, {'t', 8}, {'u', 8},
            {'v', 8}, {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}
        };
        
        int totalPushes = 0;
        for (char c : word) {
            totalPushes += keyMap[c];
        }
        
        return totalPushes;
    }
};


class Solution {
public:
    int minimumPushes(string word) {
        int two = 0, three = 0, four=0, five=0, six=0, seven=0, eight=0, nine=0;
        for( char c: word){
            if(word[c]=='a' || word[c]=='f' || word[c]=='g'){
                two++;
            }
            if(word[c]=='b' || word[c]=='h' || word[c]=='i'){
                three++;
            }
            if(word[c]=='c' || word[c]=='j' || word[c]=='k'){
                four++;
            }
            if(word[c]=='d' || word[c]=='l' || word[c]=='m'){
                five++;
            }
            if(word[c]=='e' || word[c]=='n' || word[c]=='o'){
                six++;
            }
            if(word[c]=='p' || word[c]=='q' || word[c]=='r' || word[c]=='s'){
                seven++;
            }
            if(word[c]=='t' || word[c]=='u' || word[c]=='v'){
                eight++;
            }
            if(word[c]=='w' || word[c]=='x' || word[c]=='y' || word[c]=='z'){
                nine++;
            }   
        }
        int ans = two+three+four+five+six+seven+eight+nine;
        return ans;
    }
};


//2053. Kth Distinct String in an Array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int i;

        for(i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        for(i=0; i<arr.size(); i++){
            if(mp[arr[i]]==1){
                k--;
                if(k==0)
                    return arr[i];
            }
        }
        return "";
    }
};



class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>& ans;
        int  j=0, count=0;
        for(int i=0; i<arr.size(); i++){
            for(j=i+1; j<arr.size(); j++){
                // if(arr[i]==arr[j]){
                //     k--;
                //     if(k==0){
                //         ans = arr[j];
                //     }
                count++;
                }
                if(count>0){
                    ans = arr[i];
                }
            }
            j=0;
        }
        // if(k==0){
        //     return ans;
        // }
        return ans;
    }
};







//1508. Range Sum of Sorted Subarray Sums
//SOLUTION-1
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const unsigned int M = 1000000007;
        vector<int> sums;
        
        // Generate all subarray sums
        for(int i = 0; i < n; i++) {
            int current_sum = 0;
            for(int j = i; j < n; j++) {
                current_sum = (current_sum + nums[j]) % M;
                sums.push_back(current_sum);
            }
        }

        // Sort the subarray sums
        sort(sums.begin(), sums.end());
        
        // Calculate the sum of elements from `left-1` to `right-1`
        long long result = 0;
        for(int i = left - 1; i < right; i++) {
            result = (result + sums[i]) % M;
        }
        
        return (int)result;
    }
};


//SOLUTION-2
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long sum = 0;
        const unsigned int M = 1000000007;
        vector<int> csum;
        vector<int> sums;
        for(int i=0; i<n ; i++){
            sum = (sum+nums[i])%M;
            csum.push_back(sum);
        }

        for(int i=0; i<n; i++){
            sums.push_back(csum[i]);
            for(int j=i+1; j<n; j++){
                sums.push_back(csum[j]-csum[i]);
            }
        }
        sort(sums.begin(), sums.end());
        sum=0;
        for(int i=left-1; i<=right-1; i++){
            sum += sums[i];
        }
        return sum;
    }
};

//33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0; 
        int high = nums.size() -1;

        while( low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};



//1, 3, 4, 7, 9, 9 12, 56

int min = LLONG_MAX;

for(int i=0; i<n-m-1; i++){  //i+m-1<n -> i<n-m+1
    int diff = min(arr[i+m-1] - arr[i]);
}
return min;





//contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int >s(nums.begin(), nums.end());
        return nums.size() != s.size();
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};


//Minimum Swaps to Group All 1's Together
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int o=0, z=0;

        for(int i=0; i<n; i++){
            o += (nums[i]==1);
            z += (nums[i]==0);
        }

        nums.insert(nums.end(), nums.begin(), nums.end());

        int ans = n;
        int i=0, j=0, one=0;

        while(j<2*n){
            one += (nums[j]==1);

            if(j-i+1 == o){
                ans = min(ans, o-one);
                one -= (nums[i]==1);
                i++;
            }
            j++;
        }
        return(ans==n ? 0:ans);
    }
};

//Count Senior number of citizen

int count = 0;

for(String s: arr){
    int a = (s[11]-'O' * 10)+(s[12]-'O');
    if(a>60){
        count++;
    }
    return count;
}





// 53. Maximum Subarray
// Approach 1: Brute Force
// for(int i=0 ->n){
// for(int j=0 ->n){
//     for(int k=i -> j){
//         sum = sum + arr[k];
//     }
// }
// }

// for(int i=0 ->n){
//     sum
// for(int j=0 ->n){
//     for(int k=i -> j){
//         sum = sum + arr[k];
//     }
// }
// }



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];


        for(int i=0; i<nums.size(); i++){
            //Step-1
            sum = sum + nums[i];
            //Step-2
            maxi = max(maxi, sum);
            //Step-3
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};



// DSA Sheet Sloving String Q-1: Maximum and minimum of an array using minimum number of comparisons
// Approch-1: set max and min from 1st two element of array

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int arr[n];
    int max, min;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==0){
        max = arr[0];
        min = arr[0];
    }
    if(n==1){
        if(arr[0]>arr[1]){
            max = arr[0];
            min = arr[1];
        }
        else{
            max = arr[1];
            min = arr[0];
        }
    }
    else{
        if(arr[0]>arr[1]){
            max = arr[0];
            min = arr[1];
        }
        else{
            max = arr[1];
            min = arr[0];
        }
        for(int i=2; i<n; i++){
            if(max<arr[i]){
                max = arr[i];
            }
            if(min>arr[i]){
                min = arr[i];
            }
        }
    }
    cout<<"Max" << max<<endl;
    cout<<"Min" << min<<endl;

    return 0;
}


// DSA Sheet Sloving String Q-2: Array Reverse
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    
    int n, i, j, temp;
    int arr[n];
    
    cin>>n;
    
    for(int k=0; k<n; k++){
        cin >> arr[k];
    }
    
    
    for(int i=0, j=n-1; i<n/2; i++,j--){
        temp = arr[i];
        arr[j] = arr[i];
        arr[j] = temp;
    }
    
    for(int k=0; k<n; k++){
        cout << arr[k];
    }
    
    
    return 0;
}




// #include <iostream>
// using namespace std;

// /* run this program using the console pauser or add your own getch, system("pause") or input loop */

// void printSum(int arr[][3], int row, int col){
// 	for(int row=0; row<3; row++){
// 		int sum = 0;
// 		for(int col=0; col<3; col++){
// 					sum += arr[row][col];	
// 		}
// 		cout<<sum<<" ";
// 	}
// }

// void printcolSum(int arr[][3], int row, int col){
// 	for(int row=0; row<3; row++){
// 		int sum = 0;
// 		for(int col=0; col<3; col++){
// 					sum += arr[col][row];	
// 		}
// 		cout<<sum<<" ";
// 	}
// }


// bool isPresent(int arr[][4], int target, int row, int col){
// 	for(int row=0; row<3; row++){
// 		for(int col=0; col<4; col++){
			
// 			if(arr[row][col] == target){
// 				return 1;
// 			}
			
// 		}
// 	}
// 	return 0;
// }


// int LargetRowSum(int arr[][3], int row, int col){
// 	int maxi = INT_MIN;
// 	int rowIndex = -1;
// 	for( int row=0; row<3; row++){
// 		int sum = 0;
// 		for(int col=0; col<3; col++){
// 			sum += arr[row][col];
// 		}
// 		if(sum > maxi){
// 			maxi = sum;
// 			rowIndex = row;
// 		}
// 	}
// 	return rowIndex;
// }


// int main(int argc, char** argv) {
	
// //	int arr1[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};
// 	int arr2[3][3];
	
// 	for(int row=0; row<3; row++){
// 		for(int col=0; col<3; col++){
// 			cin>>arr2[row][col];
// 		}
// 	}
	
// 	for(int row=0; row<3; row++){
// 		for(int col=0; col<3; col++){
// 			cout<<arr2[row][col]<<" ";
// 		}
// 		cout<<endl;
// 	}
	

// //Sieve of Eratosthenes
	
// //	class Solution {
// //public:
// //    int countPrimes(int n) {
// //        int count = 0;
// //       vector<bool> prime(n+1, true);
// //       prime[0] = prime[1] = false;
// //
// //       for(int i=2; i<n; i++){
// //           if(prime[i]){
// //               count++;
// //               for(int j=2*i; j<n; j=j+i){
// //                   prime[j] = 0;
// //              }
// //           }
// //       }
// //        return count;
// //    }
// //};
	
	
// //	class Solution {
// //    bool isPrime(int n){
// //        if(n<=1){
// //            return false;
// //        }
// //        for(int i=2; i<n; i++){
// //            if(n%i==0){
// //                return false;
// //            }
// //        }
// //        return true;
// //    }
// //public:
// //    int countPrimes(int n) {
// //        int count = 0;
// //        for(int i=2; i<n; i++){
// //            if(isPrime(i)){
// //                count++;
// //            }
// //        }
// //        return count;
// //    }
// //};
	
	
// //	int target;
// //	cin>>target;
	
// //	if(isPresent(arr1, target, 3, 4)){	
// //		cout<<"Element Found";
// //	}	
// //	else{
// //		cout<<"Element Not Found";
// //	}

// 	cout<<"Row Wise Sum = ";
// 	printSum(arr2, 3, 3);
// 	cout<<endl;
// //	cout<<"Colum Wise Sum = ";
// //	printcolSum(arr2, 3, 3);
// //	cout<<endl;
	
// 	cout<<"The Largest Sum is "<<LargetRowSum(arr2, 3,  3);	
	
// 	return 0;
// }


// //54. Spiral Matrix
// //class Solution {
// //public:
// //    vector<int> spiralOrder(vector<vector<int>>& matrix) {
// //        int row = matrix.size();
// //        int col = matrix[0].size();
// //        vector<int> ans;
// //        int count = 0;
// //        int total = row*col;
// //        int startingRow = 0;
// //        int startingCol = 0;
// //        int endingRow = row-1;
// //        int endingCol = col-1;
// //
// //        while(count<total){
// //
// //            for(int i=startingCol; count<total && i<=endingCol; i++){
// //                ans.push_back(matrix[startingRow][i]);
// //                count++;
// //            }
// //            startingRow++;
// //
// //            for(int i=startingRow; count<total &&i<=endingRow; i++){
// //                ans.push_back(matrix[i][endingCol]);
// //                count++;
// //            }
// //            endingCol--;
// //
// //            for(int i=endingCol; count<total && i>=startingCol; i--){
// //                ans.push_back(matrix[endingRow][i]);
// //                count++;
// //            }
// //            endingRow--;
// //
// //            for(int i=endingRow; count<total && i>=startingRow; i--){
// //                ans.push_back(matrix[i][startingCol]);
// //                count++;
// //            }
// //            startingCol++;
// //        }
// //        return ans;
// //    }
// //};
// //class Solution {
// //public:
// //    vector<int> spiralOrder(vector<vector<int>>& matrix) {
// //        int n=matrix.size(),m=matrix[0].size();
// //        int left=0,top=0;
// //        int bottom=n-1,right=m-1;
// //        vector<int>ans;
// //        while(left<=right&&top<=bottom)
// //        {
// //            for(int i=left;i<=right;i++)
// //            {
// //                ans.push_back(matrix[top][i]);
// //            }
// //            top++;
// //            for(int i=top;i<=bottom;i++)
// //            {
// //                ans.push_back(matrix[i][right]);
// //            }
// //            right--;
// //            if(top<=bottom)
// //            {
// //                for(int i=right;i>=left;i--)
// //                {
// //                    ans.push_back(matrix[bottom][i]);
// //                }
// //                bottom--;
// //            }
// //            if(left<=right)
// //            {
// //                for(int i=bottom;i>=top;i--)
// //                {
// //                    ans.push_back(matrix[i][left]);
// //                }
// //                left++;
// //            }
// //        }
// //        return ans;
// //    }
// //};

// //Rotate Image by 90 degree
// //class Solution {
// //public:
// //    void rotate(vector<vector<int>>& matrix) {
// //        int n = matrix.size();
// //        for(int i=0; i<(n+1)/2;i++){
// //            for(int j=0; j<n/2; j++){
// //                int temp = matrix[n-1-j][i];
// //                matrix[n-1-j][i] = matrix[n-1-i][n-j-1];
// //                matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
// //                matrix[j][n-1-i] = matrix[i][j];
// //                matrix[i][j] = temp;
// //            }
// //        }
// //    }
// //    
// //};













// //Print Like a Wave
// //#include <bits/stdc++.h> 
// //vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
// //{
// //    vector<int> ans;
// //
// //    for(int col=0; col<mCols; col++){
// //        if(col&1){
// //            for(int row=nRows-1; row>=0; row--){
// //                ans.push_back(arr[row][col]);
// //            }
// //        }
// //        else{
// //            for(int row=0; row<nRows; row++){
// //                ans.push_back(arr[row][col]);
// //            }
// //        }
// //    }
// //    return ans;
// //}




// // 2d matrix

// //class Solution {
// //public:
// //    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
// //        // if(matrix.size()==0 || matrix[0].size()==0){
// //        //     return matrix;
// //        // }
// //        vector<int> ans;
// //        int m = matrix.size();
// //        int n = matrix[0].size();
// //        int row=0, col=0;        
// //        bool up = true;
// //
// //        while(row<m && col<n){
// //            if(up){
// //                while(row>0 && col<n-1){
// //                    ans.push_back(matrix[row][col]);
// //                    row--;
// //                    col++;
// //                }
// //                 ans.push_back(matrix[row][col]);
// //                 if(col==n-1){
// //                     row++;
// //                 }
// //                 else{
// //                     col++;
// //                 }
// //            }
// //            else{
// //                while(col>0 && row<m-1){
// //                 ans.push_back(matrix[row][col]);
// //                 row++;
// //                 col--;   
// //                }
// //                ans.push_back(matrix[row][col]);
// //                if(row==m-1){
// //                    col++;
// //                }
// //                else{
// //                    row++;
// //                }
// //            }
// //            up = !up; // Fix: Toggle the boolean variable 'up'
// //        }
// //        return ans;
// //    }
// //};




// // Modular Exponentiation
// //#include <bits/stdc++.h>
// //
// //int modularExponentiation(int x, int n, int m) {
// //	int res = 1;
// //	while(n>0){
// //		if(n&1){
// //			res = (1LL*(res) * (x)%m)%m;
// //		}
// //		x = (1LL * (x)%m * (x)%m) %m;
// //		n = n>>1;
// //	}
// //	return res;
// //}



#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        int suneeWins = 0;
        
        // Compare the values in each possible way to determine Sunee's wins
        if ((a1 > b1 && a2 > b2) || (a1 > b2 && a2 > b1)) {
            suneeWins = 1;
        }
        
        cout << suneeWins << endl;
    }
    
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases
    
    while(t--) {
        int n;
        cin >> n;  // Read the two-digit positive integer
        int sum = (n / 10) + (n % 10);  // Calculate the sum of the digits
        cout << sum << endl;  // Output the result
    }

        return 0;
    }


#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;  // Read number of test cases
    
    while(t--){
        int a1, a2, b1, b2;
        cin>>a1>>a2>>b1>>b2;
        
        int suneeWins = 0;
        
        if(a1>b1 && a2>b2){
            suneeWins++;
        }
        if(a1>b2 && a2>b1){
            suneeWins++;
        }
        if(a2>b1 && a1>b2){
            suneeWins++;
        }
        
        cout<<suneeWins<<endl;
    }
    
    
    return 0;
}

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

vector<int> reverse(vector<int> v){
    int s=0, e=v.size()-1;
    
    while(s<=e){
        swap(v[s], v[e]);
        s++
        e--;
    }
    return v;
}
void print(vector<int> p){
    for(int i=0; i<v.size(); i++){
        cout<< v[i] << " ";
    }
    cout<endl;
}

int main() {
    vector <int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);
    
    vector<int> ans = reverse(v);
    print(ans);
    
    return 0;
}
