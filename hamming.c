#include <stdio.h>
#include <math.h>


int hamCalc(int position, int hamlen, int hamming[]) {
    
    int i = position;
    int count = 0;
    

    // till i is the last bit
    while(i <= hamlen) {
    // start with the current position and calculate the number of bits equal to the position
    //8 16 
    for (int j=i; j<i+position; j++) {
        
            if(j>hamlen) {
                break;
            }
            if(hamming[j] == 1) {
                count++; 
            }
    }
    
    // skip the number of bits equal to the position
    i = i+2*position;
    
    }
    
    if (count%2 == 0) {
        return 0;
    } else {
        return 1;
    }
}
int main ()
{
    

  int m,nr,r=0;
  printf("Enter number of bits in the data: ");
  scanf("%d", &m);
  int data[m];
  printf("Enter data bit by bit: ");
  for (int k=0; k<m; k++) {
      scanf("%d", &data[k]);
  }
  
  // find r
  while(1) {
      if(pow(2, r) >= m+r+1) {
          break;
      }
      r++;
  }
  printf(" r %d ", r);
  int hamming[m+r+1];
  
  int rpos;
  for (int i=0; i<r; i++) {
      rpos = pow(2,i);
      hamming[rpos] = -1;
  }
  
  int k = 1, j = m-1;
  while (k <= m+r) {
      if(hamming[k] != -1) {
          hamming[k] = data[j];
          j--;
      }
      k++;
  }
  
  int parityBit;
  for (int i=1; i<=m+r; i++) {
      if(hamming[i] == -1) {
         parityBit = hamCalc(i, m+r, hamming);
         hamming[i] = parityBit;
      }
  }
  
  printf("\nCalculated hamming code is: \n");
    for (int i=m+r; i>0; i--) {
      printf("%d ",hamming[i]);
  }
  
  // ERROR CORRECTION
  int nreceived;
  printf("\nEnter length of received code: " );
  scanf("%d", &nreceived);
  int received[nreceived+1]; 
  printf("\nEnter the received code bit by bit: ");
  for(int i=nreceived; i>0; i--) {
      scanf("%d", &received[i]);
  }
  
  int r2 = 0;
  while(pow(2,r2) <= nreceived) {
      r2++;
  }
  
  int errorPosn = 0;
  
  for(int k=0; k<r2; k++) {
      int pos = pow(2, k);
      // check if parity is even
      int value = hamCalc(pos, nreceived, received);
      
      if (value != 0) {
          errorPosn = errorPosn + pos;
      }
  }
  
  if(errorPosn == 0) {
      printf("\nCorrect code received");
  } else {
      printf("Incorrect code received. Error at position %d", errorPosn);
      if (received[errorPosn] == 0) {
          received[errorPosn] = 1;
      } else {
          received[errorPosn] = 0;
      }
      printf("\nCorrected hamming code is: ");
      for (int i=nreceived; i>0; i--) {
      printf("%d ",received[i]);
  }
      
  }

  return 0;
}
