#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    /*
     * Sum of two strings
     * @param A: a string
     * @param B: a string
     * @return: the sum of two strings
     */
    string SumOfTwoStrings(string &A, string &B)
    {
        string results = "";
        int lenA = A.length();
        int lenB = B.length();

        int indA = lenA - 1;
        int indB = lenB - 1;

        int carrier = 0;
        while (indA >= 0 && indB >= 0)
        {
            int res = (A[indA] - '0') + (B[indB] - '0') + carrier;
            if (res > 9) 
            {
                res -= 10;
                res %= 10;
                carrier = 1;
            }
            else{
                carrier = 0;
            }
            results = to_string(res) + results;

            indA--;
            indB--;
        }

        while (indA > 0)
        {
            int res = (A[indA] - '0') + carrier;
            if (res > 9) 
            {
                res -= 10;
                res %= 10;
                carrier = 1;
            }
            else{
                carrier = 0;
            }
            results = to_string(res) + results;
            indA--;
        }

        while (indB > 0)
        {
            int res = (B[indB] - '0') + carrier;
            if (res > 9) 
            {
                res -= 10;
                res %= 10;
                carrier = 1;
            }
            else{
                carrier = 0;
            }
            results = to_string(res) + results;
            indB--;
        }

        if (carrier)
            results = to_string(carrier) + results;

        return results;
    }

    string SumOfTwoStrings2(string &A, string &B)
    {
        int inta = stoi(A);
        int intb = stoi(B);
        return to_string(inta + intb);
    }
};

int main (int argc, char *argv[])
{
    string num1 = "1234";
    string num2 = "8888";

    Solution sol;

    cout << sol.SumOfTwoStrings(num1, num2) << endl;
    cout << sol.SumOfTwoStrings2(num1, num2) << endl;

    return 0;
}
