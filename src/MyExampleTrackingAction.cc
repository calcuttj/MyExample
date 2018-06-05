#include "MyExampleTrackingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"

MyExampleTrackingAction::MyExampleTrackingAction(TreeBuffer * inputTreeBuffer) : G4UserTrackingAction(){

  MyTreeBuffer = inputTreeBuffer;

  G4cout << "Initializing tracking action" << G4endl;

}

MyExampleTrackingAction::~MyExampleTrackingAction(){
}

void MyExampleTrackingAction::PreUserTrackingAction(const G4Track * track){
  int parID = track->GetParentID();
  MyTreeBuffer->track_tid->push_back(track->GetTrackID());
  MyTreeBuffer->track_pid->push_back(track->GetDefinition()->GetPDGEncoding());

  
   
}

void MyExampleTrackingAction::PostUserTrackingAction(const G4Track * track){  
  //MyTreeBuffer->track_creator->push_back(track->GetCreatorProcess()->GetProcessName()); 
}
