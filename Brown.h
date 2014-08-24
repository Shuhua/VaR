//---------------------------------------------------------------------------
#ifndef BrownH
#define BrownH                                                                
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <random> 
class Brown
{
std::default_random_engine generator; 
std::normal_distribution<double> distribution;
private:
    double _M;
    double _S;
    double _D;
    int _T;
    double _R;
public:
    Brown();
    ~Brown();
    double Position;
    void setMu(const double Mu) { _M = Mu; }
    void setSigma(const double Sigma) { _S = Sigma; }
    void setDT(const double DT) { _D = DT; }
    void setTime(const int Time) { _T = Time; }
    void setRisk(const double Risk) { _R = Risk; }
    double getMu() const { return _M; }
    double getSigma() const { return _S; }
    double getDT() const { return _D; }
    double getTime() const { return _T; }
    double getRisk() const { return _R; }

    double SetPosition()  {Position= 0.0; }
    double Normal();
    double CalculatePosition();
    double CalculateFinal();
    int VaR(int N, int M, int step);
//    double CalculateDistribution() const;
};
//---------------------------------------------------------------------------
#endif
