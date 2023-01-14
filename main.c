#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int main()
{
    double F,x,x1,x2,delta;
    int N,n,i;
    char group_name[6],student_name[17];
    FILE *input,*output,*outbin,*inbin;

    input=fopen("D:\\ok\\lab5.2.txt","r");
    if(input==NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    fscanf(input, "%lf %lf %d %lf %s %s", &x1, &x2, &N, &delta, &group_name, &student_name);
    fclose(input);
    printf("x1=%lf\nx2=%lf\nN=%d\ndelta=%lf\n%s\n%s\n\n", x1, x2, N, delta, group_name, student_name);


    output=fopen( "D:\\ok\\lab5.2_out.txt", "w" );
    if(output==NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    outbin=fopen( "D:\\ok\\lab5.2.bin", "wb" );
    if(outbin==NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }


    if(N==0)
        N=((x2-x1)/delta)+1;
    if(delta==0)
        delta=(x2-x1)/(N-1);
    fprintf(output,"\t_________________________________________________\n");
    fprintf(output,"\t|\tN\t|\tX\t|\tF(x)\t|\n");
    fprintf(output,"\t_________________________________________________\n");
    for(i=1;i<=N+1;i++)
    {
        F=(-pow(x1,3)/25)+(10*pow(x1,2))-15000;
        fwrite( &i, sizeof(int), 1, outbin );
        fwrite( &x1, sizeof(double), 1, outbin );
        fwrite( &F, sizeof(double), 1, outbin );
        fprintf(output,"\n\t|\t%d\t|\t%.2f\t|\t%.2f|\n",i,x1,F);
        fprintf(output,"\t_________________________________________________\n");
        x1=x1+delta;
    }
    fprintf(output, "\n\t\t %s %s", student_name, group_name);
    fclose(output);
    fclose(outbin);


    inbin=fopen("D:\\ok\\lab5.2.bin","rb");
        if(inbin==NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    printf("\t_________________________________________________\n");
    printf("\t|\tN\t|\tX\t|\tF(x)\t|\n");
    printf("\t_________________________________________________\n");
    for(i=1;i<=N;i++)
    {
        fread(&n, sizeof(int),1,inbin );
        fread(&x, sizeof(double),1,inbin );
        fread(&F, sizeof(double),1,inbin );
        printf ("\n\t|\t%d\t|\t%.2f\t|\t%.2f|\n",n,x,F);
        printf("\t_________________________________________________\n");
    }
    fclose(inbin);
     return 0;
    }


