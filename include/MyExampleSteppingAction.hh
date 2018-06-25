#ifndef MyExampleSteppingAction_h
#define MyExampleSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "TreeBuffer.hh"
#include "StepTreeBuffer.hh"
#include "TTree.h"

#include <iostream>
#include <fstream>
#include <vector>

class MyExampleSteppingAction : public G4UserSteppingAction{

  public:
    MyExampleSteppingAction(TreeBuffer *, StepTreeBuffer *, TTree *);
    virtual ~MyExampleSteppingAction();

    virtual void UserSteppingAction(const G4Step*);  

  private:
    TreeBuffer * MyTreeBuffer;
    StepTreeBuffer * MyStepTreeBuffer;
    TTree * step_tree_copy;


};

#endif
