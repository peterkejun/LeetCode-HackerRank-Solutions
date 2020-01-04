/*
Problem Name: Longest Palindromic Substring
Problem Algorithm: Dynamic Programming (Manacher's Algorithm)
Problem URL: https://leetcode.com/problems/longest-palindromic-substring/
*/

string longestPalindrome(string s) {
       int n = s.length();
	    if (n <= 1) return s;
	    n = 2 * n + 1;
	    int L[n];
	    L[0] = 0;
	    L[1] = 1;
	    int C = 1, R = 2, i = 0, mirror, expand = -1, diff = -1;
	    int max = 0, max_pos = 0;
	    int start = -1, end = -1;
	    for (int i = 2; i < n; i++) {
            mirror = 2 * C - i;
		    expand = 0;
		    diff = R - i;
		    if(diff > 0) { 
                if(L[mirror] < diff) // Case 1 
                    L[i] = L[mirror]; 
                else if(L[mirror] == diff && i == n - 1) // Case 2 
                    L[i] = L[mirror]; 
                else if(L[mirror] == diff && i < n - 1)  // Case 3 
                { 
                    L[i] = L[mirror]; 
                    expand = 1;  // expansion required 
                } 
                else if(L[mirror] > diff)  // Case 4 
                { 
                    L[i] = diff; 
                    expand = 1;  // expansion required 
                } 
            } else {
			    L[i] = 0;
			    expand = 1;
		    }
		    if (expand) {
			    while (((i + L[i]) < n && (i - L[i]) > 0) &&  
                        ( ((i + L[i] + 1) % 2 == 0) ||  
                        (s[(i + L[i] + 1)/2] == s[(i-L[i]-1)/2] ))) { 
                    L[i]++; 
                }
		    }
		    if (L[i] > max) {
			    max = L[i];
			    max_pos = i;
	    	}
		    if (i + L[i] > R) {
			    C = i;
		    	R = i + L[i];
		    }
	    }
	    start = (max_pos - max) / 2;
	    return s.substr(start, max);
    }