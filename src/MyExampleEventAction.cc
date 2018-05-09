#include "MyExampleEventAction.hh"

MyExampleEventAction::MyExampleEventAction(TTree * tree, std::vector<int> * tid, std::vector<int> * pid) : G4UserEventAction(){

  //Pass the pointers to this class;
  tree_copy = tree;  
  std::cout << "Got tree at " << tree << std::endl;

  tid_copy = tid;
  pid_copy = pid;
}

MyExampleEventAction::~MyExampleEventAction(){ 
}

void MyExampleEventAction::BeginOfEventAction(const G4Event * event){
  tid_copy->clear();
  pid_copy->clear();
}

void MyExampleEventAction::EndOfEventAction(const G4Event * event){
  tree_copy->Fill();
}
