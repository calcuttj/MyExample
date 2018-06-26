#include "MyExampleTrackingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4String.hh"

MyExampleTrackingAction::MyExampleTrackingAction(TreeBuffer * inputTreeBuffer, StepTreeBuffer * inputStepTreeBuffer, TrackTreeBuffer * inputTrackTreeBuffer, TTree * track) : G4UserTrackingAction(){

  MyTreeBuffer = inputTreeBuffer;
  MyStepTreeBuffer = inputStepTreeBuffer;
  MyTrackTreeBuffer = inputTrackTreeBuffer; 

  G4cout << "Initializing tracking action" << G4endl;
  track_tree_copy = track;
}

MyExampleTrackingAction::~MyExampleTrackingAction(){
}

void MyExampleTrackingAction::PreUserTrackingAction(const G4Track * track){
  int parID = track->GetParentID();
  MyTreeBuffer->track_tid->push_back(track->GetTrackID());
  MyTreeBuffer->track_pid->push_back(track->GetDefinition()->GetPDGEncoding());

  //G4ThreeVector mom = track->GetMomentum();
  //G4cout << "Momentum: " <<  mom[0] << " " << mom[1] << " " << mom[2] << G4endl;

  MyStepTreeBuffer->parID = parID; 
  MyStepTreeBuffer->trackID = track->GetTrackID();
  MyStepTreeBuffer->PID = track->GetDefinition()->GetPDGEncoding();
   
  MyTrackTreeBuffer->steps->clear();
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

  track_tree_copy->Fill();

}
