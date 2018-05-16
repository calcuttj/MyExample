#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "MyExampleDetectorConstruction.hh"
#include "MyExamplePhysicsList.hh"
#include "MyExampleActionInitialization.hh"

int main(int argc, char ** argv){
 
  G4RunManager * runManager = new G4RunManager;
  
  //Define and create detector volume  
  runManager->SetUserInitialization(new MyExampleDetectorConstruction);

  //Define the list of particles to be simulated
  //and on which models their behaviors are based
  runManager->SetUserInitialization(new MyExamplePhysicsList);

  //Define the actions taken during various stages of the run
  //i.e. generating particles
  runManager->SetUserInitialization(new MyExampleActionInitialization);

  runManager->Initialize();

  G4UImanager * UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");

  int nEvents = 100;
  runManager->BeamOn(nEvents);  

  delete runManager;
  return 0;
}
