#include "LaplaceYoung.h"

registerMooseObject("ibexApp", LaplaceYoung);

template <>
InputParameters
validParams<LaplaceYoung>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("kappa", 0.1, "Kappa parameter for Laplace-Young equation.");
  params.addClassDescription("The Laplace-Young equation.");
  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) :
    Kernel(parameters),
    _kappa(getParam<Real>("kappa"))
{
}

Real
LaplaceYoung::computeQpResidual()
{
  Real k = 1. / std::sqrt(1. + _grad_u[_qp].norm() * _grad_u[_qp].norm());
  return k * _grad_u[_qp] * _grad_test[_i][_qp] + _kappa * _u[_qp] * _test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  Real k = 1. / std::sqrt(1. + _grad_u[_qp].norm() * _grad_u[_qp].norm());
  return k * _grad_phi[_j][_qp] * _grad_test[_i][_qp] + _kappa * _test[_i][_qp];
}
