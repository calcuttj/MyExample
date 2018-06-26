#ifndef MyExampleEventAction_h
#define MyExampleEventAction_h 1

#include "G4UserEventAction.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "TreeBuffer.hh"
#include "StepTreeBuffer.hh"
#include "TrackTreeBuffer.hh"

#include "TTree.h"
#include <vector>

class MyExampleEventAction : public G4UserEventAction{

  public:
    MyExampleEventAction(TTree *, TreeBuffer *, StepTreeBuffer *, TrackTreeBuffer *);
    virtual ~MyExampleEventAction();

    virtual void BeginOfEventAction(const G4Event *);
    virtual void EndOfEventAction(const G4Event *);
  protected:
    G4EventManager * fpEventManager;

  private: 
    TTree * tree_copy;
    TreeBuffer * MyTreeBuffer;
    StepTreeBuffer * MyStepTreeBuffer;
    TrackTreeBuffer * MyTrackTreeBuffer;


};

#endif
