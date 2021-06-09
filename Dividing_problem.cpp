/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int SumSum (double *, int, double);
int FindNum (double *, int, double);
void swap (double *, double *); // swap
void bubbleSort (double *, int); //Bubble sort
int fact (int); //Factorial calculator
int NchooseK(int ,int );
int Left2(double *, int , double , double , int );


int main ()
{
  int Out = 0, i, z;
  int maxL=100;
//  double A[maxL] ;
  double A[]={1,2,5,3,4,5};
/*
    double input; 
    int count = 0; 
    cout << "To stop enter any character.";
    cout << "\nEnter Your Input::"<<endl;
  
    // cin returns false when a character
    // is entered
    while (cin >> input){
        A[count]= input;
        count++; 
    }
      
    cout << "\nTotal number of inputs entered: " 
         << count<<endl;
    int len= count;
*/

  int len = sizeof (A) / sizeof (A[0]);
  bubbleSort (A, len);
  cout << "Length: "<<len << endl<<"Sorted Array: ";

  for (i = 0; i < len; i++)
    cout << A[i] << " ";
  cout << endl;

  Out = FindNum (A, len, 0);
    cout <<"The answer is: " << Out  << endl;
   return Out ;
}


int FindNum (double *AA, int N, double D)
{
    //N includes the last element of aN
    //Left (group 1) sum is D more than Right (group 2) sum.
    
  int Result, i, count;
  //Assuming that AA is sorted ascending
  if (N==1)
    return 0;
    
  if (N == 2)
    {
      if ((D==0) && (AA[0]==AA[1]))
        return 2;
      if ((D!=0) && (AA[0] == AA[1] + D))
	    return 1;
	  return 0;
    }

  i=N-2;
  count=0;
  while (AA[i]==AA[N - 1]){
      count++;
      i--;
  }

  Result = 
          FindNum (AA, N - 1, D) 
        + SumSum (AA, N - 1, AA[N - 1] + D) 
        + FindNum (AA, N - 1, AA[N - 1] + D)
        + Left2(AA, N, D, AA[N - 1], count);

  return Result;
}


int SumSum (double *AA, int M, double Y)
{
    //a1+a2+...+aM=S
  if (Y < AA[0])
    return 0;
    
  if (M == 1)
    {
      if (AA[0] == Y)
        {
        return 1;
        }
      else
        return 0;
    }
    
  if (M > 1){
      if (Y == AA[M - 1]){
          return SumSum (AA, M - 1, Y) +1;
      }
      else
      return SumSum (AA, M - 1, Y) 
            	+ SumSum (AA, M - 1, Y - AA[M - 1]);
  }
}

void swap (double *xp, double *yp)
{
  double temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort (double arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    // Last i elements are already in place
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
    	swap (&arr[j], &arr[j + 1]);
}


int fact (int uu)
{
  int y = 1, i;
  if (uu == 0)
    return 1;
  else
    {
      for (i = 1; i <= uu; i++)
	y = y * i;
      return y;
    }

}

int NchooseK(int t,int k)
{
    if (t>=k)
        return fact(t)/(fact(k)*fact(t-k));
    else
        return 0;
}


int Left2(double *B, int N, double D, double aN, int C)
{
    //N includes the last element of aN as well.
    
    if (C==0)
        return 0;

    int Res=0, u;
    for (u=1; u<=C; u++){
        if ((u==1)&&(D==0))
            Res=C;
        else{
            if (N>1+u)
                Res= Res+ NchooseK(C,u)*SumSum (B, N-1-u, aN*(u-1)+D);
        }
    }
    return Res;
}






