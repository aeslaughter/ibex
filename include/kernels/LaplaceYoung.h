#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

#include "Kernel.h"

class LaplaceYoung;

template <>
InputParameters validParams<LaplaceYoung>();

/**
 * Implements the Laplace-Young equation.
 */
class LaplaceYoung : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  const Real & _kappa;
};

#endif
