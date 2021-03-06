#ifndef CEC2013_FUNCS_H
#define CEC2013_FUNCS_H

#include <armadillo>
#include <matio.h>

// Initialization functions
void init_f1 (mat_t* matfp);
void init_f2 (mat_t* matfp);
void init_f3 (mat_t* matfp);
void init_f4 (mat_t* matfp);
void init_f5 (mat_t* matfp);
void init_f6 (mat_t* matfp);
void init_f7 (mat_t* matfp);
void init_f8 (mat_t* matfp);
void init_f9 (mat_t* matfp);
void init_f10(mat_t* matfp);
void init_f11(mat_t* matfp);
void init_f12(mat_t* matfp);
void init_f13(mat_t* matfp);
void init_f14(mat_t* matfp);
void init_f15(mat_t* matfp);

// Benchmark functions
long double f1 (const arma::mat& x);
long double f2 (const arma::mat& x);
long double f3 (const arma::mat& x);
long double f4 (const arma::mat& x);
long double f5 (const arma::mat& x);
long double f6 (const arma::mat& x);
long double f7 (const arma::mat& x);
long double f8 (const arma::mat& x);
long double f9 (const arma::mat& x);
long double f10(const arma::mat& x);
long double f11(const arma::mat& x);
long double f12(const arma::mat& x);
long double f13(const arma::mat& x);
long double f14(const arma::mat& x);
long double f15(const arma::mat& x);

#endif
