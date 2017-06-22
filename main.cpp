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
void findPath(int **DAG,int size,int source,int destination,vector<int> *answer)
{
  int next = 0,nextWeight=9999;
  for (int i = 0; i < size; ++i)
  {
    if (DAG[source][i] != -1)
    {
      if(i == destination)
      {
        answer->push_back(i);
        return;
      }else{
        if(DAG[source][i] <= nextWeight)
        {
          next = i;
          nextWeight = DAG[source][i];
        }
      }
    }
  }
  answer->push_back(next);
  findPath(DAG,size,next,destination,answer);
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
  vector<int> answer;
  findPath(DAG,size,source,destination,&answer);
  return answer;
}

int main ()
{
    test();
    return 0;
}
