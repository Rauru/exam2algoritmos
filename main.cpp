#include "Test.h"
#include <iostream>
#include <map>
using namespace std;

int longestPalindromicSubsequence(string sequence, int begin, int end)
{
   if (begin == end)
     return 1;

   if (sequence[begin] == sequence[end] && begin + 1 == end)
     return 2;

   if (sequence[begin] == sequence[end])
      return longestPalindromicSubsequence(sequence, begin+1, end-1) + 2;

   return max( longestPalindromicSubsequence(sequence, begin, end-1),
           longestPalindromicSubsequence(sequence, begin+1, end) );
}

int longestPalindromicSubsequence(string sequence)
{
  return longestPalindromicSubsequence(sequence, 0, sequence.size()-1);
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
    vector<int> answer;
    vector<int> failed;
    int check = source;
    int current = source;
    int next = source;
    int eraset=0;
    for(int i=current;i<size;i++)
    {
        for(int j=current+1; j<size; j++)
        {
            if(DAG[i][j] !=-1)
            {
                bool verify;
                for(int f = 0; f < failed.size(); f++)
                {
                    if(j == failed[f])
                    {
                        verify = true;
                    }
                }
                if(!verify){
                    current = j;
                    next = next++;
                    answer.push_back(j);
                    eraset ++;
                }
                }else if(DAG[i][j] ==-1){

                    failed.push_back(current);
                    for(int e = 0; e< eraset; e++){
                        answer.pop_back();
                    }
                    eraset =0;
                }
        }
    }

    printf("answer");
    for(int f = 0; f < answer.size(); f++)
                {
                    printf("%d", answer[f]);
                }
    return answer;
}


int main ()
{
    test();
    return 0;
}
