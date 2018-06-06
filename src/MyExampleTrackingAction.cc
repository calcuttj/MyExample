#include "MyExampleTrackingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4String.hh"

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
  if(track->GetCreatorProcess()){//Skips primary particles which have no creator process

    G4String processName = track->GetCreatorProcess()->GetProcessName();
    MyTreeBuffer->track_creator->push_back(processName); 
    
    if(track->GetParentID() == 1){//If the parent is primary
      if((processName != "hIoni") && (processName != "eIoni")){//Skip ionization
  	G4cout << "Non-ionization created track: " << processName << G4endl;        
        MyTreeBuffer->secondaryProductIDs->push_back(track->GetTrackID());
        MyTreeBuffer->secondaryProductPIDs->push_back(track->GetDefinition()->GetPDGEncoding());
        *(MyTreeBuffer->secondaryProcess) = processName;
      }

    }
  }
}
