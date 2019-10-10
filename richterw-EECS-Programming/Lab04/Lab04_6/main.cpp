#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double freqToOmega(double freq){
    double omega = M_PI*2*freq;
    return omega;
}

// t
double periodFromFreq(double freq){
    double T = 1/freq;
    return T;
}

double currentMagnitude(double R, double resVoltage){
    double mag = resVoltage / R;
    return mag;
}

// A
double currentAmplitude(double omega, double Eo, double L, double C, double R) {
    double amp = ((omega*Eo) / sqrt( pow((L * pow(omega, 2) - (1/C)),2) + pow(R,2)*pow(omega,2)));
    return amp;
}

// theta
double currentTheta(double L, double omega, double R, double C){
    double theta = atan(((L*omega)/R) - (1/R*C*omega));
    return theta;
}

// Vt
double appliedVoltage(double Eo, double omega, double t){
    double Vt = Eo * sin(omega*t);
    return Vt;
}

//It
double totalCurrent(double A, double omega, double t, double theta){
    double TC = A*sin(omega*t - theta);
    return TC;
}

// VRt
double resVoltage(double R, double A, double omega, double t, double theta){
    double RVD = R * A * sin(omega * t - theta);
    return RVD;
}

//VLt
double indVoltage(double L, double omega, double A, double t, double theta){
    double idV = L * omega * A * cos(omega*t-theta);
    return idV;
}

//VCt
double capVoltage(double A, double C, double omega, double t, double theta){
    double dC = (-A/C*omega)*cos(omega*t-theta);
    return dC;
}


int main()
{
    double Eo, f, R, L, C;
    int nstep;

    cout << "Please enter applied voltage amplitude: ";
    cin >> Eo;
    cout << endl;
    cout << "Please enter line frequency: ";
    cin >> f;
    cout << endl;
    cout << "Please enter resistor value: ";
    cin >> R;
    cout << endl;
    cout << "Please enter inductor value: ";
    cin >> L;
    cout << endl;
    cout << "Please enter capacitor value: ";
    cin >> C;
    cout << endl;
    cout << "Please enter AC period: ";
    cin >> nstep;
    cout << endl;

    cout << setw(5) << "Iter." << setw(5) << "Time" << setw(12) << "AV";
    cout << setw(13) << "I" << setw(14) << "VR" << setw(15) << "VL" << setw(16) << "VC" << setw(17) << "VT" << endl;

    for (int i=0; i < nstep; i++){
        // Iter, Time, AV
        cout << setprecision(3) << fixed << setw(2) << i << setw(5) << i/1000 << setw(15) << appliedVoltage(Eo, freqToOmega(f), periodFromFreq(f));
        // I
        cout << setprecision(3) << fixed << setw(15) << totalCurrent(currentAmplitude(freqToOmega(f), Eo, L, C, R), freqToOmega(f), periodFromFreq(f), currentTheta(L, freqToOmega(f), R, C));
        // VR
        cout << setprecision(3) << fixed << setw(15) << resVoltage(R, currentAmplitude(freqToOmega(f), Eo, L, C, R), freqToOmega(f), periodFromFreq(f), currentTheta(L, freqToOmega(f), R, C));
        // VL
        cout << setprecision(3) << fixed << setw(15) << indVoltage(L,freqToOmega(f), currentAmplitude(freqToOmega(f), Eo, L, C, R), periodFromFreq(f), currentTheta(L, freqToOmega(f), R, C));
        // VC
        cout << setprecision(3) << fixed << setw(15) << capVoltage(currentAmplitude(freqToOmega(f), Eo, L, C, R), C, freqToOmega(f), periodFromFreq(f), currentTheta(L, freqToOmega(f), R, C));
        // VT
        cout << setprecision(3) << fixed << setw(15) << appliedVoltage(Eo, freqToOmega(f), periodFromFreq(f)) << endl;
    }
}
