#include "MyExampleActionInitialization.hh"
#include "MyExamplePrimaryGeneratorAction.hh"
#include "MyExampleTrackingAction.hh"
#include "MyExampleSteppingAction.hh"
#include "MyExampleEventAction.hh"
#include "TROOT.h"

MyExampleActionInitialization::MyExampleActionInitialization() : G4VUserActionInitialization(){

  MyTreeBuffer = new TreeBuffer();
  MyStepTreeBuffer = new StepTreeBuffer();

  fout = new TFile("try.root", "RECREATE");
  tree = new TTree("tree","");
  step = new TTree("step","");
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
  tree->Branch("interactionModeName",      &MyTreeBuffer->interactionModeName);

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
  tree->Branch("preProcess", &MyTreeBuffer->preStepProcess);
  tree->Branch("preMat", &MyTreeBuffer->preStepMat);
  tree->Branch("postMat", &MyTreeBuffer->postStepMat);

  G4cout << "Made tree Branches" << G4endl;

  step->Branch("trackID", &MyStepTreeBuffer->trackID);
  step->Branch("eventNum", &MyStepTreeBuffer->eventNum);
  step->Branch("PID", &MyStepTreeBuffer->PID);
  step->Branch("parID", &MyStepTreeBuffer->parID);
  step->Branch("stepChosenProc", &MyStepTreeBuffer->stepChosenProc);
  step->Branch("stepActivePostProcNames", &MyStepTreeBuffer->stepActivePostProcNames);
  step->Branch("stepActiveAlongProcNames", &MyStepTreeBuffer->stepActiveAlongProcNames);
  step->Branch("stepActivePostProcMFPs", &MyStepTreeBuffer->stepActivePostProcMFPs);
  step->Branch("stepActiveAlongProcMFPs", &MyStepTreeBuffer->stepActiveAlongProcMFPs);
  step->Branch("px", &MyStepTreeBuffer->px);
  step->Branch("py", &MyStepTreeBuffer->py);
  step->Branch("pz", &MyStepTreeBuffer->pz);
  step->Branch("ekin", &MyStepTreeBuffer->ekin);
  G4cout << "Made step Branches" << G4endl;
}

MyExampleActionInitialization::~MyExampleActionInitialization(){
  tree->Write();
  step->Write();
  fout->Close();
}

void MyExampleActionInitialization::Build() const{
  
  SetUserAction(new MyExamplePrimaryGeneratorAction());
  //Pass trees and branches to these
  std::cout << "Passing tree at " << tree << std::endl;
  SetUserAction(new MyExampleEventAction(tree, MyTreeBuffer, MyStepTreeBuffer));//Will have to fill tree in this
  SetUserAction(new MyExampleSteppingAction(MyTreeBuffer, MyStepTreeBuffer, step));
  SetUserAction(new MyExampleTrackingAction(MyTreeBuffer, MyStepTreeBuffer));
}
