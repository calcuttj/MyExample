#ifndef MyExampleActionInitialization_h
#define MyExampleActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

#include "TTree.h"
#include "TFile.h"

struct TreeBuffer{
  std::vector<int> * tid;
  std::vector<int> * pid;
  int fEvent;
};

class MyExampleActionInitialization : public G4VUserActionInitialization{

  public:
    MyExampleActionInitialization();
    virtual ~MyExampleActionInitialization();
    
    void Build() const;

    TFile * fout;
    TTree * tree;

/*    std::vector<int> * tid;
    std::vector<int> * pid;
    int fEvent;*/

    TreeBuffer MyTreeBuffer;
};
#endif
