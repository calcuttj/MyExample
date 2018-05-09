#ifndef MyExampleSteppingAction_h
#define MyExampleSteppingAction_h 1

#include "G4UserSteppingAction.hh"

#include <iostream>
#include <fstream>
#include <vector>

class MyExampleSteppingAction : public G4UserSteppingAction{

  public:
    MyExampleSteppingAction(std::vector<int>*, std::vector<int>*);
    virtual ~MyExampleSteppingAction();

    virtual void UserSteppingAction(const G4Step*);  
//    std::ofstream fout;
  private:
    std::vector<int> * tid_copy;
    std::vector<int> * pid_copy;

};

#endif
