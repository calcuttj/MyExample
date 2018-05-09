#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"

MyExampleSteppingAction::MyExampleSteppingAction(std::vector<int> * tid, std::vector<int> * pid) : G4UserSteppingAction(){

  tid_copy = tid;
  pid_copy = pid;

  G4cout << "Initializing stepping action" << G4endl;

  G4cout << "Got tid vector at " << tid_copy <<
  "\nGot pid vector at " << pid_copy << G4endl;

}

MyExampleSteppingAction::~MyExampleSteppingAction(){
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  
  tid_copy->push_back(track->GetTrackID());
  pid_copy->push_back(track->GetDefinition()->GetPDGEncoding());
}
