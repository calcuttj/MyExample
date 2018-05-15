#include "MyExampleEventAction.hh"

MyExampleEventAction::MyExampleEventAction(TTree * tree, TreeBuffer inputTreeBuffer) : G4UserEventAction(){

  //Pass the pointers to this class;
  tree_copy = tree;  
  std::cout << "Got tree at " << tree << std::endl;

  MyTreeBuffer = inputTreeBuffer;
}

MyExampleEventAction::~MyExampleEventAction(){ 
}

void MyExampleEventAction::BeginOfEventAction(const G4Event * event){
  MyTreeBuffer.tid->clear();
  MyTreeBuffer.pid->clear();
  MyTreeBuffer.primaryPDGs->clear();
}

void MyExampleEventAction::EndOfEventAction(const G4Event * event){

  G4PrimaryVertex* vtx = event->GetPrimaryVertex();

  //Positions
  MyTreeBuffer.xi = vtx->GetX0();
  MyTreeBuffer.yi = vtx->GetY0();
  MyTreeBuffer.zi = vtx->GetZ0();

  //Primary particles
  int nPrimary = vtx->GetNumberOfParticle();
  G4cout << "Got primaries: " << nPrimary << G4endl;
  for(int ip = 0; ip < nPrimary; ++ip){
    G4PrimaryParticle * part = vtx->GetPrimary(ip);    
    G4cout<< "\t" << ip << " " << part->GetPDGcode() << G4endl;
    MyTreeBuffer.primaryPDGs->push_back(part->GetPDGcode());
  }

  tree_copy->Fill();
}
