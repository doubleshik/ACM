#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int cal(double finalscore,double suggest,char gan,char west,int paper)
{
    double award=0;
    if(finalscore >80 && paper>=1)
        award+=8000;
    if(finalscore>85 &&suggest>80)
        award+=4000;
    if(finalscore>90)
        award+=2000;
    if(finalscore>85 && west=='Y')
        award+=1000;
    if(suggest>80 && gan=='Y')
        award+=850;
    return award;
}

int main()
{
    int n;
    cin>>n;
    double total=0;
    char ansname[30];
    double maxmoney=0;
    while(n--)
    {
        char name[30];

        double finalscore,suggest;
        char gan,west;
        int paper;
        double ans;
        scanf("%s %lf %lf %c %c %d",name,&finalscore,&suggest,&gan,&west,&paper);
        getchar();
        ans=cal(finalscore,suggest,gan,west,paper);

        total+=ans;
        if(ans>maxmoney){maxmoney=ans;strcpy(ansname,name);}
    }
    cout<<ansname<<endl;
    cout<<maxmoney<<endl;
    cout<<total<<endl;;

    return 0;
}
