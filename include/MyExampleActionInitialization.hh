#ifndef MyExampleActionInitialization_h
#define MyExampleActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "TreeBuffer.hh"
#include "StepTreeBuffer.hh"

#include "TTree.h"
#include "TFile.h"



class MyExampleActionInitialization : public G4VUserActionInitialization{

  public:
    MyExampleActionInitialization();
    virtual ~MyExampleActionInitialization();
    
    void Build() const;

    TFile * fout;
    TTree * tree;
    TTree * step;

    TreeBuffer * MyTreeBuffer;
    StepTreeBuffer * MyStepTreeBuffer;
};
#endif
