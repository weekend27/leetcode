// Source : https://leetcode.com/problems/simplify-path/
// Author : weekend27
// Date   : 2015-12-18

/**********************************************************************************

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.sg/2013/01/leetcode-simplify-path.html
/*
利用栈的特性，如果sub string element
1. 等于“/”，跳过，直接开始寻找下一个element
2. 等于“.”，什么都不需要干，直接开始寻找下一个element
3. 等于“..”，弹出栈顶元素，寻找下一个element
4. 等于其他，插入当前elemnt为新的栈顶，寻找下一个element

最后，再根据栈的内容，重新拼path。这样可以避免处理连续多个“/”的问题。
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        assert(path[0] == '/');
        int i = 0;
        while (i < path.size()){
            while (path[i] == '/' && i < path.size()){      // skip the every beginning '///////'
                i++;
            }
            if (i == path.size()){
                break;
            }
            int start = i;
            while (path[i] != '/' && i < path.size()){      // decide the end boundary
                i++;
            }
            int end = i - 1;
            string element = path.substr(start, end - start + 1);
            if (element == ".."){
                if (stack.size() > 0){
                    stack.pop_back();
                }
            }
            else if (element != "."){
                stack.push_back(element);
            }
        }
        if (stack.size() == 0){
            return "/";
        }
        string simPath;
        for (int i = 0; i < stack.size(); i++){
            simPath += "/" + stack[i];
        }
        return simPath;
    }
};
