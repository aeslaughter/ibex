[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./ly]
    type = LaplaceYoung
    variable = u
  [../]
[]

[BCs]
  [./bc]
    type = NeumannBC
    variable = u
    value = 0.2
    boundary = 'left right top bottom'
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
