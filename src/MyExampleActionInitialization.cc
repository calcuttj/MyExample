#include "MyExampleActionInitialization.hh"
#include "MyExamplePrimaryGeneratorAction.hh"
#include "MyExampleTrackingAction.hh"
#include "MyExampleSteppingAction.hh"
#include "MyExampleEventAction.hh"



MyExampleActionInitialization::MyExampleActionInitialization() : G4VUserActionInitialization(){
  MyTreeBuffer = new TreeBuffer();
  fout = new TFile("try.root", "RECREATE");
  tree = new TTree("tree","");
  G4cout << "Making Branches" << G4endl;
  tree->Branch("pid", &MyTreeBuffer->pid);
  tree->Branch("tid", &MyTreeBuffer->tid);
  tree->Branch("track_pid", &MyTreeBuffer->track_pid);
  tree->Branch("track_tid", &MyTreeBuffer->track_tid);
  tree->Branch("track_creator", &MyTreeBuffer->track_creator);
  tree->Branch("secondaryProductIDs",  &MyTreeBuffer->secondaryProductIDs);
  tree->Branch("secondaryProductPIDs", &MyTreeBuffer->secondaryProductPIDs);
  tree->Branch("secondaryProcess",     &MyTreeBuffer->secondaryProcess);
  tree->Branch("interactionMode",      &MyTreeBuffer->interactionMode);

  tree->Branch("nPi0",     &MyTreeBuffer->nPi0);    
  tree->Branch("nPiPlus",  &MyTreeBuffer->nPiPlus);
  tree->Branch("nPiMinus", &MyTreeBuffer->nPiMinus);
  tree->Branch("nNuclear", &MyTreeBuffer->nNuclear);
  tree->Branch("nProton",  &MyTreeBuffer->nProton);
  tree->Branch("nNeutron", &MyTreeBuffer->nNeutron);
  tree->Branch("nGamma",   &MyTreeBuffer->nGamma);

  tree->Branch("fEvent", &MyTreeBuffer->fEvent);
  tree->Branch("xi", &MyTreeBuffer->xi);
  tree->Branch("yi", &MyTreeBuffer->yi);
  tree->Branch("zi", &MyTreeBuffer->zi);
  tree->Branch("primaryPDGs", &MyTreeBuffer->primaryPDGs);
  tree->Branch("primaryEnergy", &MyTreeBuffer->primaryEnergy);
  tree->Branch("parid", &MyTreeBuffer->parid);
  tree->Branch("ekin", &MyTreeBuffer->ekin);
  tree->Branch("edep", &MyTreeBuffer->edep);
  tree->Branch("xs", &MyTreeBuffer->xs);
  tree->Branch("ys", &MyTreeBuffer->ys);
  tree->Branch("zs", &MyTreeBuffer->zs);

  tree->Branch("postProcess", &MyTreeBuffer->postStepProcess);
  G4cout << "Made Branches" << G4endl;
}

MyExampleActionInitialization::~MyExampleActionInitialization(){
  tree->Write();
  fout->Close();
}

void MyExampleActionInitialization::Build() const{
  SetUserAction(new MyExamplePrimaryGeneratorAction);
  //Pass trees and branches to these
  std::cout << "Passing tree at " << tree << std::endl;
  SetUserAction(new MyExampleEventAction(tree, MyTreeBuffer));//Will have to fill tree in this
  SetUserAction(new MyExampleSteppingAction(MyTreeBuffer));
  SetUserAction(new MyExampleTrackingAction(MyTreeBuffer));
}
