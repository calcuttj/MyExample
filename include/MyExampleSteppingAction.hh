#ifndef MyExampleSteppingAction_h
#define MyExampleSteppingAction_h 1

#include "G4UserSteppingAction.hh"

#include <iostream>
#include <fstream>



class MyExampleSteppingAction : public G4UserSteppingAction{

  public:
    MyExampleSteppingAction();
    virtual ~MyExampleSteppingAction();

    virtual void UserSteppingAction(const G4Step*);  
//    std::ofstream fout;

};

#endif
