/*
Ordered Substrings

You are given an array A consisting of strings. You are supposed to order the given 
strings in such a way that for a particular string, all strings ordered before it exist 
as its substrings.

Each string is made up of lowercase English letters.

Return an array consisting of the correct order of strings.
If it is not possible to do so, return a vector consisting of one element, 
which is the string "NO".

*/
bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a.compare(b) < 0;
    }
    return a.length() < b.length();
}

vector<string> Solution::solve(vector<string> &A) {
    sort(A.begin(), A.end(), cmp);
    for(int i = 0; i < A.size() - 1; i++) {
        if(A[i + 1].find(A[i]) == string::npos) {
            return { "NO" };
        }    
    }
    return A;
}

