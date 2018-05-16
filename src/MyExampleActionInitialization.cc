#include "MyExampleActionInitialization.hh"
#include "MyExamplePrimaryGeneratorAction.hh"
#include "MyExampleTrackingAction.hh"
#include "MyExampleSteppingAction.hh"
#include "MyExampleEventAction.hh"



MyExampleActionInitialization::MyExampleActionInitialization() : G4VUserActionInitialization(){
  fout = new TFile("try.root", "RECREATE");
  tree = new TTree("tree","");
  tree->Branch("pid", &MyTreeBuffer.pid);
  tree->Branch("tid", &MyTreeBuffer.tid);
  tree->Branch("track_pid", &MyTreeBuffer.track_pid);
  tree->Branch("track_tid", &MyTreeBuffer.track_tid);
  tree->Branch("fEvent", &MyTreeBuffer.fEvent);
  tree->Branch("xi", &MyTreeBuffer.xi);
  tree->Branch("yi", &MyTreeBuffer.yi);
  tree->Branch("zi", &MyTreeBuffer.zi);
  tree->Branch("primaryPDGs", &MyTreeBuffer.primaryPDGs);
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
