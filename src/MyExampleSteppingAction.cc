#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"

MyExampleSteppingAction::MyExampleSteppingAction() : G4UserSteppingAction(){
  G4cout << "Initializing stepping action" << G4endl;
//  fout.open("try.txt");
//  fout << "Steps IDs\n";

/*  //Initialize TFile and TTree for output
  fout = new TFile("out.root", "RECREATE");
  tree = new TTree("tree",""); 
  
  tree->Branch("pid", &pid);
  tree->Branch("tid", &tid);*/
}

MyExampleSteppingAction::~MyExampleSteppingAction(){
 // fout.close();
//  fout->Close();
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  
//  fout << "Track ID: " << track->GetTrackID() << "\n";
//  std::cout << "Track ID: " << track->GetTrackID() << std::endl;
//  tid.push_back(track->GetTrackID());
//  pid.push_back(track->GetDefinition()->GetPDGEncoding());
}
