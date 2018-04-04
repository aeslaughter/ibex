//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ibexTestApp.h"
#include "ibexApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ibexTestApp>()
{
  InputParameters params = validParams<ibexApp>();
  return params;
}

ibexTestApp::ibexTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ibexApp::registerObjectDepends(_factory);
  ibexApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ibexApp::associateSyntaxDepends(_syntax, _action_factory);
  ibexApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ibexApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    ibexTestApp::registerObjects(_factory);
    ibexTestApp::associateSyntax(_syntax, _action_factory);
    ibexTestApp::registerExecFlags(_factory);
  }
}

ibexTestApp::~ibexTestApp() {}

void
ibexTestApp::registerApps()
{
  registerApp(ibexApp);
  registerApp(ibexTestApp);
}

void
ibexTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
ibexTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
ibexTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ibexTestApp__registerApps()
{
  ibexTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
ibexTestApp__registerObjects(Factory & factory)
{
  ibexTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
ibexTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ibexTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
ibexTestApp__registerExecFlags(Factory & factory)
{
  ibexTestApp::registerExecFlags(factory);
}
