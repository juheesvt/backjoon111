#include <stdio.h>

int main()
{
  int arr[9];
  int a=1;
  for(int i=0;i<9;i++)
    {
      scanf("%d", &arr[i]);
    }
  int max=arr[0];
  for(int i=0;i<9;i++)
  {
    if (max<arr[i])
       {
         max=arr[i];
         a=i+1;
       }
  }

    printf("%d\n",max);
    printf("%d",a);
  return 0;
}