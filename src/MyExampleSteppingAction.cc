#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"


MyExampleSteppingAction::MyExampleSteppingAction(TreeBuffer * inputTreeBuffer) : G4UserSteppingAction(){

  MyTreeBuffer = inputTreeBuffer;

  G4cout << "Initializing stepping action" << G4endl;

}

MyExampleSteppingAction::~MyExampleSteppingAction(){
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  auto prestep = step->GetPreStepPoint(); 
  MyTreeBuffer->tid->push_back(track->GetTrackID());
  MyTreeBuffer->pid->push_back(track->GetDefinition()->GetPDGEncoding());

  
  MyTreeBuffer->parid->push_back(track->GetParentID());
  
  MyTreeBuffer->ekin->push_back(prestep->GetKineticEnergy() / GeV);
  
  MyTreeBuffer->edep->push_back(step->GetTotalEnergyDeposit() / GeV); 

  
  MyTreeBuffer->xs->push_back(prestep->GetPosition().getX() / cm);
  
  MyTreeBuffer->ys->push_back(prestep->GetPosition().getY() / cm);
  
  MyTreeBuffer->zs->push_back(prestep->GetPosition().getZ() / cm);
  
}
