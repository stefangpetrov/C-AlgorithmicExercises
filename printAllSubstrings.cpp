#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int strLen(char* str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

void printKSubstrings(char* word, int K)
{
    int wordLen = strLen(word);
    for (int i = 0; i < wordLen - K + 1; i++)
    {
        for (int j = i; j < i+K; j++)
        {
            cout << word[j];
        }
        cout << " ";
    }
}
void printAllSubstrings(char* word)
{
    int wordLen = strLen(word);

    for (int i = 1; i <= wordLen; i++)
    {
        printKSubstrings(word, i);
    }
}
int main()
{
    char* str = new char[MAX_SIZE];
    cin >> str;
    
    printAllSubstrings(str);

    delete[] str;

}

