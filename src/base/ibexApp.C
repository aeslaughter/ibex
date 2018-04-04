#include "ibexApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ibexApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ibexApp::ibexApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ibexApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ibexApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ibexApp::registerExecFlags(_factory);
}

ibexApp::~ibexApp() {}

void
ibexApp::registerApps()
{
  registerApp(ibexApp);
}

void
ibexApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"ibexApp"});
}

void
ibexApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"ibexApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
ibexApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
ibexApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
ibexApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ibexApp__registerApps()
{
  ibexApp::registerApps();
}

extern "C" void
ibexApp__registerObjects(Factory & factory)
{
  ibexApp::registerObjects(factory);
}

extern "C" void
ibexApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ibexApp::associateSyntax(syntax, action_factory);
}

extern "C" void
ibexApp__registerExecFlags(Factory & factory)
{
  ibexApp::registerExecFlags(factory);
}
