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

void getThirdStringFromFirst(char*third, char* first,  int firstLen)
{
    for (int i = 0; i < firstLen; i++)
    {
        third[i] = first[i];
    }
    for (int i = firstLen; i < firstLen * 2; i++)
    {
        third[i] = first[i - firstLen];
    }
    third[firstLen * 2] = '\0';
}

bool isRotationalOfEachOther(char* first, char* second)
{
    int firstLen = strLen(first);
    int secondLen = strLen(second);
    if (firstLen != secondLen)
    {
        return false;
    }

    char* third = new char[MAX_SIZE * 2];
    getThirdStringFromFirst(third, first, firstLen);
    int thirdLen = strLen(third);
    

    for (int i = 0; i < thirdLen; i++)
    {
        int count = 0;
        if (third[i] == second[0] && thirdLen - i >= secondLen)
        {
            count++;
            for (int j = 1; j < secondLen; j++)
            {
                if (second[j] == third[i + count])
                {
                    count++;
                }
            }
        }
        if (count == secondLen)
        {
            return true;
        }
    }

    return false;


}
int main()
{
    char* firstStr = new char[MAX_SIZE];
    char* secondStr = new char[MAX_SIZE];

    cin >> firstStr >> secondStr;

    bool isTrue = isRotationalOfEachOther(firstStr, secondStr);
    if (isTrue == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

