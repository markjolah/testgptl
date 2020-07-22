#include <iomanip>
#include <iostream>
#include <tuple>

#include <gptl.h>
#include <papi.h>

typedef std::tuple<double,double> coeff_t; // coefficients type
typedef coeff_t (*func_t)(int); // callback function type

double calc(func_t func, int n)
{
    double a, b, temp = 0;
    for (; n > 0; --n) {
        std::tie(a, b) = func(n);
        temp = b / (a + temp);
    }
    std::tie(a, b) = func(0);
    return a + temp;
}

coeff_t pi(int n)
{
    return coeff_t(n > 0 ? 6 : 3, (2 * n - 1) * (2 * n - 1));
}

void do_work()
{
    int n=10000;
    std::cout<<"Computed pi ("<<n<<" iterations): "<<std::setprecision(16)<<calc(pi,n)<<std::endl;
}

int main ()
{
  void do_work (void);
  int i, ret;
  ret = GPTLsetoption (GPTL_IPC, 1);     // Count instructions per cycle
  ret = GPTLsetoption (PAPI_TOT_INS, 1); // Print total instructions
  ret = GPTLsetoption (GPTLoverhead, 0); // Don't print overhead estimate
  ret = GPTLinitialize ();               // Initialize GPTL
  ret = GPTLstart ("main");              // Start a manual timer
  do_work ();                            // Do some work
  ret = GPTLstop ("main");               // Stop the manual timer
  ret = GPTLpr_file ("outfile");         // Write output to "outfile"
}
