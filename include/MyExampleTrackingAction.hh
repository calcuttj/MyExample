#ifndef MyExampleTrackingAction_h
#define MyExampleTrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "TreeBuffer.hh"
#include "StepTreeBuffer.hh"

#include <iostream>
#include <fstream>
#include <vector>

class MyExampleTrackingAction : public G4UserTrackingAction{

  public:
    MyExampleTrackingAction(TreeBuffer *, StepTreeBuffer *);
    virtual ~MyExampleTrackingAction();

    virtual void PreUserTrackingAction(const G4Track *);  
    virtual void PostUserTrackingAction(const G4Track *);  
  private:
    TreeBuffer * MyTreeBuffer;
    StepTreeBuffer * MyStepTreeBuffer;
};

#endif
