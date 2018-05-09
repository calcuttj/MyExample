#ifndef MyExampleEventAction_h
#define MyExampleEventAction_h 1

#include "G4UserEventAction.hh"
#include "G4EventManager.hh"

#include "TTree.h"
#include <vector>

class MyExampleEventAction : public G4UserEventAction{

  public:
    MyExampleEventAction(TTree *, std::vector<int> *, std::vector<int> *);
    virtual ~MyExampleEventAction();

    virtual void BeginOfEventAction(const G4Event *);
    virtual void EndOfEventAction(const G4Event *);
  protected:
    G4EventManager * fpEventManager;

  private: 
    TTree * tree_copy;
    std::vector<int> * tid_copy;
    std::vector<int> * pid_copy;
};

#endif
