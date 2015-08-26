/* The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.*/

using System;
using System.Text;

public class Solution {
    public string CountAndSay(int n) {
        if (n < 2) {
            return "1";
        }        

        // Use a StringBuilder for efficiency
        string result = "1";
        StringBuilder stringBuilder = new StringBuilder();
        
        for (int i = 0; i < n - 1; ++i) {
            int count;
            int j = 0;
            char c;
            
            while (j < result.Length) {
                c = result[j++];
                count = 1;

                while (j < result.Length && c == result[j]) {
                    ++count;
                    ++j;
                }

                stringBuilder.Append(count.ToString() + c);
                
                if (j >= result.Length) {
                    break;
                }
            }
            
            result = stringBuilder.ToString();
            stringBuilder.Clear();
        }
        
        return result;
    }

    public static void Main(string[] args) {
        Solution solution = new Solution();
        int n = int.Parse(args[0]);

        Console.WriteLine("String for {0} is: {1}", n, solution.CountAndSay(n));
    }
}
