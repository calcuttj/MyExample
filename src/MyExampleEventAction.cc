#include "MyExampleEventAction.hh"

MyExampleEventAction::MyExampleEventAction(TTree * tree, TreeBuffer * inputTreeBuffer) : G4UserEventAction(){

  //Pass the pointers to this class;
  tree_copy = tree;  
  std::cout << "Got tree at " << tree << std::endl;

  MyTreeBuffer = inputTreeBuffer;
}

MyExampleEventAction::~MyExampleEventAction(){ 
}

void MyExampleEventAction::BeginOfEventAction(const G4Event * event){
  MyTreeBuffer->tid->clear();
  MyTreeBuffer->pid->clear();
  MyTreeBuffer->track_tid->clear();
  MyTreeBuffer->track_pid->clear();
  MyTreeBuffer->track_creator->clear();
  MyTreeBuffer->primaryPDGs->clear();
  MyTreeBuffer->parid->clear();
  MyTreeBuffer->ekin->clear();
  MyTreeBuffer->edep->clear();
  MyTreeBuffer->xs->clear();
  MyTreeBuffer->ys->clear();
  MyTreeBuffer->zs->clear();

  MyTreeBuffer->postStepProcess->clear();
}

void MyExampleEventAction::EndOfEventAction(const G4Event * event){

  G4PrimaryVertex* vtx = event->GetPrimaryVertex();

  //Positions
  MyTreeBuffer->xi = vtx->GetX0();
  MyTreeBuffer->yi = vtx->GetY0();
  MyTreeBuffer->zi = vtx->GetZ0();

  //Primary particles
  int nPrimary = vtx->GetNumberOfParticle();
  G4cout << "Got primaries: " << nPrimary << G4endl;
  for(int ip = 0; ip < nPrimary; ++ip){
    G4PrimaryParticle * part = vtx->GetPrimary(ip);    
    G4cout<< "\t" << ip << " " << part->GetPDGcode() << G4endl;
    MyTreeBuffer->primaryPDGs->push_back(part->GetPDGcode());
  }

  G4cout << "track vec size" << MyTreeBuffer->track_tid->size() << G4endl; 

  MyTreeBuffer->fEvent = event->GetEventID();

  G4cout << "Event: " << event->GetEventID() << G4endl;
  G4cout << "Event: " << MyTreeBuffer->fEvent << G4endl;
  G4cout << "primarypdgs " << MyTreeBuffer->primaryPDGs << G4endl;
  tree_copy->Fill();
}
