#include "MyExamplePhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"

MyExamplePhysicsList::MyExamplePhysicsList() : G4VModularPhysicsList(){
  SetVerboseLevel(1);

  RegisterPhysics( new G4DecayPhysics );
  RegisterPhysics( new G4RadioactiveDecayPhysics );
  RegisterPhysics( new G4EmStandardPhysics );
  RegisterPhysics( new G4HadronPhysicsQGSP_BERT ); 
}

MyExamplePhysicsList::~MyExamplePhysicsList(){}

void MyExamplePhysicsList::SetCuts(){
  G4cout << "Set Cuts" << G4endl; 
}



