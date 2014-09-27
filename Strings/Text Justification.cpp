/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res; 
        string line;
        int p = 0, len;
        while (p < words.size()){
            len = words[p].length();
            vector<int> cur; 
            cur.push_back(p); p++; 
            while(p < words.size() && len + 1 + words[p].length() <= L) {
                len += 1 + words[p].length();
                cur.push_back(p); 
                p++;
            }
            if(cur.size() == 1) {
                line = words[cur[0]] + string(L - len, ' ');
            } else {
                int sp, sh;
                if(p == words.size()){
                    sp = 1; sh = 0;
                } else {
                    int sl = L - (len - cur.size() + 1);
                    sp = sl / (cur.size() - 1);
                    sh = sl % (cur.size() - 1);
                }
                line = words[cur[0]];
                for(int k = 1; k < cur.size(); k++){
                    if(sh-- > 0) line += " ";
                    line += string(sp, ' ') + words[cur[k]];
                }
                if(p == words.size()) line += string(L-len, ' ');
            }
            res.push_back(line);
        }
        return res;
    }
};
