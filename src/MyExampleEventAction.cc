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
}

void MyExampleEventAction::EndOfEventAction(const G4Event * event){
  tree_copy->Fill();
}
