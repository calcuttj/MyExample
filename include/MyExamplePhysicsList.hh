#ifndef MyExamplePhysicsList_h
#define MyExamplePhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"

class MyExamplePhysicsList : public G4VModularPhysicsList
{

  public:
    MyExamplePhysicsList();
    virtual ~MyExamplePhysicsList();
  
  protected:
    virtual void SetCuts(); 
  
};
#endif
