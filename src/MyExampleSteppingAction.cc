#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"

MyExampleSteppingAction::MyExampleSteppingAction(TreeBuffer inputTreeBuffer) : G4UserSteppingAction(){

  MyTreeBuffer = inputTreeBuffer;

  G4cout << "Initializing stepping action" << G4endl;

  G4cout << "Got tid vector at " << tid_copy <<
  "\nGot pid vector at " << pid_copy << G4endl;

}

MyExampleSteppingAction::~MyExampleSteppingAction(){
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  
  MyTreeBuffer.tid->push_back(track->GetTrackID());
  MyTreeBuffer.pid->push_back(track->GetDefinition()->GetPDGEncoding());
   
}
