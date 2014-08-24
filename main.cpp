#include <iostream>
#include "Brown.h"
#include <cstddef>
using namespace std;

void RequestDimensions(Brown* cn)
{
    double Mu=0.00;        //Drift
    double Sigma=1.0;      
    double DT=2.0;
    int Time=20;
    double Risk=10.0;         //Risk%


    cn->setMu(Mu);
    cn->setSigma(Sigma);
    cn->setDT(DT);
    cn->setTime(Time);
    cn->setRisk(Risk);
}

int main()
{
    Brown typeBrown;
    int j;
    RequestDimensions(&typeBrown);

    int M=int(Time*DT*Sigma)+1;
//    int M=int(typeBrown.getTime())+1;
    const std::size_t N = 2*M+1;
    int a[N];
    int step=10000;

    cout << "\nMonte Carlo simulation characteristics";
    cout << "\nMu:       " << typeBrown.getMu();
    cout << "\nSigma:       " << typeBrown.getSigma();
    cout << "\nd_Time:       " << typeBrown.getDT();
    cout << "\nTime:       " << typeBrown.getTime();
    cout << "\nFinal position:    " << typeBrown.CalculateFinal();
    cout << "\n"<<typeBrown.getRisk()<<"% Value-at-Risk is:    "<<typeBrown.VaR(N,M,step)<<"\n ";
    return 0;
}
