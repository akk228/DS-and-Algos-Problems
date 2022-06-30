// Fast Fourier transform with shitty auxilliary space using and only for n = 2^m, otherwise gives shit

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef complex<double> compl_num;
typedef vector<compl_num> compl_vec;

compl_vec FFT (compl_vec v){
    int n = v.size();
    
    if (n==1) {return v;};
    
    //Split at the even & odd
    
    compl_vec A_e (n/2), A_o (n/2);
    
    for (int i = 0; i < n/2; i++){
        A_e.at(i) = v.at(2*i);
        A_o.at(i) = v.at(2*i+1);
    };
   
    //Perform FFT on the splitted vectors
    
    compl_vec t_e (n/2), t_o (n/2);
    
    t_e = FFT(A_e);
    t_o = FFT(A_o);
    
    //Complete FFT for the whole vector
    
    compl_vec t(n);
    compl_num w( 1., 0), w_mult ( cos(2*M_PI/n), sin(2*M_PI/n));
    
    for (int i = 0; i < n/2; i++){
        t.at(i)   = t_e.at(i) + w*t_o.at(i);
        t.at(i+n/2) = t_e.at(i) - w*t_o.at(i);
        w = w*w_mult;
    };
    
    return t;
};

int main()
{
    int n;
    
    cout << "Input n such that it's a power of 2"<< endl;
    cout <<"n = ";
    cin >> n;
    
    compl_vec a(n);
    for(int i = 0; i < n; i++){
        a.at(i) = ( compl_num ( rand()%10, 0) );
        cout << a.at(i);
    };
    cout << endl;
    for(auto s: FFT(a)){
        cout << s;
    };
    cout << endl;
    return 0;
}


