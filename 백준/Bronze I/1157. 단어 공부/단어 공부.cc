#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main(void)
{
    char ch[1000000];
    int alpha[26] = { 0 };
    cin >> ch;
    int ch_len = (int)strlen(ch);
    int alpha_num;
    for (int i = 0; i < ch_len; i++)
    {
        ch[i] = toupper(ch[i]);
        alpha_num = (int)ch[i] - 65;
        alpha[alpha_num]++;
    }
    
    int fst_rate = 0;
    int sec_rate = 0;
    int fst_alpha = 0;
    int sec_alpha = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > fst_rate)
        {
            fst_rate = alpha[i];
            fst_alpha = i;
        }
        else if (alpha[i] > sec_rate)
        {
            sec_rate = alpha[i];
            sec_alpha = i;
        }
    }
    if (fst_rate == sec_rate)
        cout << '?' << endl;
    else
        printf("%c\n", (fst_alpha+65));
    
    return 0;
}
