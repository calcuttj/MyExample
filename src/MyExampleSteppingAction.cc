#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"

MyExampleSteppingAction::MyExampleSteppingAction(TreeBuffer inputTreeBuffer) : G4UserSteppingAction(){

  MyTreeBuffer = inputTreeBuffer;

  G4cout << "Initializing stepping action" << G4endl;

}

MyExampleSteppingAction::~MyExampleSteppingAction(){
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  
  MyTreeBuffer.tid->push_back(track->GetTrackID());
  MyTreeBuffer.pid->push_back(track->GetDefinition()->GetPDGEncoding());
   
}
