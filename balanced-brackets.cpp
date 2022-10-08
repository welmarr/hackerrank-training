// Include map header before use.
// #include <map>


/**
 * For a string to be valid, any opening bracket must be its 
 * closing counterpart and the last opening bracket in the string 
 * must be the first to be closed. Any string that does not 
 * meet this requirement is not valid. 
 * 
 * @param s 
 * @return string 
 */
string isBalanced(string s) {
    // The simplest valid s we can generate is an opening bracket 
    // and its closing bracket. Considering that the condition on the 
    // closing order is respected, we notice that we always have to 
    // add two characters (i.e. an opening bracket and its closing bracket) 
    // to generate a valid string. So s with even size is likely
    // to be valid while s with odd size is necessarily invalid.
    if(s.size()%2 != 0) return "NO";
    
    map<char, char> bracket { { '{', '}'}, { '[', ']' }, { '(', ')' }};

    // I will use memory like LIFO [Last In (the last opening bracket's 
    // closing bracket is added) First Out (the first closing bracket will be
    // the last element add in memory)]
    string memory ("");
    char temp(0);
    
    for (int i = 0; i < s.size(); i++) {
        // Use the current character of s as key to get the
        // closing bracket if the current character is an opening bracket.
        // If the current character is not opening bracket, temp will set 
        // at 0 [and mean that the current character is closing bracket
        // (s containt opening and closing bracket only)]. If the current
        // character is opening bracket, temp will be its closing bracket.
        temp = bracket[s[i]];
        
        
        if(temp == 0){
            if (memory != "" && memory[memory.size() - 1] == s[i]) {
                // FO (LIFO) process succeeded
                memory.pop_back();
            }else {
                // FO (LIFO) process failed
                return "NO";
            }
        }else {
            // LI (LIFO) process in progress
            memory = memory + temp;
        }
    }
    
    // If the memory is not empty, it means that we have opening
    // brackets in s that are not closed.
    return memory.empty() ? "YES" : "NO";
}
