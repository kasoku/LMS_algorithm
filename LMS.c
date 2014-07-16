/*LSM_algorithm*/
#include <stdio.h>
#include <math.h>
#define N 22
double X(double n) {
    double y;
    y = sin(2 * M_PI * n /5 );
    return y;
}   
double D(double n) {
    double y;
    y = 2 * cos( 2 * M_PI * n / 5);
    return y;
}
int main(void)
{
    double h0[N], h1[N],x[N], y[N], d[N], e[N];
    double n = 0.5;
    int i;
  
    h0[0] = 10.7; h1[0] = 0;
    h0[1] = h0[0]; h1[1] = h1[1];
    
    for(i = 0; i <= 20; i++) {
      x[i] = X(i);
      d[i] = D(i);
    }

    i = 1;
    while (i <=  20) {
      y[i] = h0[i] * x[i] + h1[i] * x[i -1];
      e[i] = d[i] - y[i];
      h0[i + 1] = h0[i] + 2 * n * e[i] * x[i];
      h1[i + 1] = h1[i] + 2 * n * e[i] * x[i- 1];
      i++;
    }
    printf("n\t h0\t h1\t x\t y\t d\t e\n");
    for(i = 1; i <= 20; i ++){
      printf("%d\t %4f\t %4f\t %4f\t %4f\t %4f\t %4f\n", i, h0[i], h1[i], x[i], y[i], d[i], e[i]);
    }
    return 0;
}
