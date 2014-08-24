//Source File: Brown.cpp
//---------------------------------------------------------------------------
#include <math.h>
#include <random>
#include "Brown.h"
//using namespace std;
//---------------------------------------------------------------------------
Brown::Brown() {}
//---------------------------------------------------------------------------
double Brown::CalculatePosition()
{
    double epsilon=Normal();
//    if (epsilon>=0.5) Position+=1.0;
//    if (epsilon<0.5) Position-=1.0;
//    Position=epsilon;
    Position=Position+_M*Position*_D+_S*epsilon*sqrt(_D);
    return Position;
}
//---------------------------------------------------------------------------
Brown::~Brown()
{
    
}
//---------------------------------------------------------------------------
double Brown::CalculateFinal()
{
    SetPosition();
    Position=0.0;
    for (int i=0; i<_T; i++)  
    {
    CalculatePosition();
    }
    return Position;
}
//----------------------------------------------------------------------------
int Brown::VaR(int N, int M, int step)
{
    int a[N];
    int j;
    int k;
    for (int i=0; i<N; i++)  
    {
    a[i]=0;
    }

    for (int i=0; i<step; i++)  
    {
    j=(int)(CalculateFinal())+M;
    a[j]++;
    }

    for (int i=0, x=0; i<N; i++, x+=a[i])  
    {
    k=i-M;
    if((double)x*100.0>_R*(double)(step)) break;
    }
    return k;
}
//---------------------------------------------------------------------------
double Brown::Normal()
{
    return distribution(generator);
}
