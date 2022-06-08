#include <stdio.h>

int main()
{
    int n, ndiv;
    printf("Enter length of data: ");
    scanf("%d", &n);
    printf("Enter length of divisor: ");
    scanf("%d", &ndiv);
    printf("Enter data: ");
    int data[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    printf("Enter divisor: ");
    int divisor[ndiv];
    for(int i=0; i<ndiv; i++) {
        scanf("%d", &divisor[i]);
    }
    
    int codeword[n+ndiv-1];
    for (int i=0; i<n; i++) {
        codeword[i] = data[i];
    }
    for (int i=n; i<n+ndiv-1; i++) {
        codeword[i] = 0;
    }
    
    int originalCode[n+ndiv-1];
    for(int l=0; l<n+ndiv-1;l++) {
        originalCode[l] = codeword[l];
    }
    int quotient[n], rem[ndiv];
    for (int i=0; i<n; i++) {
    int temp = i;
        if (codeword[i] == 1) {
            
            for(int j=0; j<ndiv; j++) {
                if (codeword[temp] == divisor[j]) {
                    codeword[temp] = 0;
                    rem[j] = 0;
                } else {
                    codeword[temp] = 1;
                    rem[j] = 1;
                    
                }
                temp++;
            }
            quotient[i] = 1;
        } else {
            quotient[i] = 0;
        }
    }
    
    printf("\nThe quotient is \n");
    for(int i=0;i<n;i++)
    printf("%d",quotient[i]);
    printf("\nThe remainder is \n");
    for(int j=1;j<ndiv;j++)
    printf("%d",rem[j]);
    
    for(int k=1; k<ndiv; k++) {
        originalCode[n+k-1] = rem[k];
    }
    printf("\nFinal string is \n");
    for(int i=0;i<ndiv+n-1;i++) {
    printf("%d",originalCode[i]);
    }

    // CHECKING STRING 
    int nr, ndivr;
    printf("\nEnter length of data: ");
    scanf("%d", &nr);
    printf("Enter length of divisor: ");
    scanf("%d", &ndivr);
    printf("Enter data: ");
    int rdata[nr];
    for(int i=0; i<nr; i++) {
        scanf("%d", &rdata[i]);
    }
    printf("Enter divisor: ");
    int rdivisor[ndivr];
    for(int i=0; i<ndivr; i++) {
        scanf("%d", &rdivisor[i]);
    }
    
    int ndata = nr - ndivr + 1;
    int rquotient[ndata];
    int calcRem[ndivr];
    
    for(int a=0; a<ndata; a++) {
        int temp = a;
        
        if (rdata[a] == 1 ){
            rquotient[a] = 1;
            for (int j=0; j<ndivr; j++) {
                if (rdata[temp] ==  rdivisor[j]) {
                    rdata[temp] = 0;
                    calcRem[j] = 0;
                } else {
                    rdata[temp] = 1;
                    calcRem[j] = 1;
                }
                temp++;
            }
            
            
        } else {
            rquotient[a] = 0;
            
        }
    }
    int error = 0;
    printf("\nThe remainder is \n");
    for(int j=1;j<ndivr;j++)
    {
        printf("%d",calcRem[j]);
        if(calcRem[j] == 1) {
            error = 1;
        }
        
    }
    
    if (error!=0) {
        printf("\nThere is an error in the received data");
    } else {
        printf("\nThere is no error in the received data");
    }
    

    return 0;
}

