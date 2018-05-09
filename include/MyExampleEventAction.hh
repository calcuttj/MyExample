#ifndef MyExampleEventAction_h
#define MyExampleEventAction_h 1

#include "G4UserEventAction.hh"
#include "G4EventManager.hh"

#include "TTree.h"

class MyExampleEventAction : public G4UserEventAction{

  public:
    MyExampleEventAction(TTree *);
    virtual ~MyExampleEventAction();

    virtual void BeginOfEventAction(const G4Event *);
    virtual void EndOfEventAction(const G4Event *);
  protected:
    G4EventManager * fpEventManager;

  private: 
    TTree * tree_copy;
};

#endif
