#include <stdio.h>
#include <math.h>
#include <time.h>

void iterativ(int n)
{
    long long int fibn, term1 = 0, term2 = 1;
    for (int i = 2; i <= n; i++)
    {
        fibn = term1+term2;
        term1 = term2;
        term2 = fibn;
    }
    printf("metoda 1: %lli\n",fibn);
}

int recursiv(int n)
{
    if (n>1) return recursiv(n-1) + recursiv(n-2);
    else if (n==1) return 1;
    else if (n==0) return 0;
}

int met3(int n)
{
    int j=0, i=1;
    for (int k=1; k<=n; k++)
    {
        j= i+j;
        i=j-i;
    }
    return j;
}

int met4(int n)
{
    int f[n+2];
    int i;
    f[0]=0;
    f[1]=1;
    for (i=2;i<=n;i++)
    f[i]=f[i-1] + f[i-2];
    return f[n];
}

int met5(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };

    if (n == 0)
        return 0;

    power(F, n - 1);

    return F[0][0];
}

void power(int F[2][2], int n)
{
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
    for(i = 2; i <= n; i++)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] +
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] +
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] +
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] +
            F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int met6(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

int main()
{
    int n;

    clock_t t;
    t = clock();

    printf("Enter the number for fibonacci sequence:");
    scanf("%i",&n);
    iterativ(n);
    //printf("metoda 2: %lli\n",recursiv(n));
    //printf("metoda 3: %lli\n",met3(n));
    //printf("metoda 4: %lli\n",met4(n));
    //printf("metoda 5: %lli\n",met5(n));
    //printf("metoda 6: %lli\n",met5(n));
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("algorithm took %f seconds to execute \n", time_taken);
    return 0;
}

