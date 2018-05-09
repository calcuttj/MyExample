#include "MyExampleEventAction.hh"

MyExampleEventAction::MyExampleEventAction(TTree * tree) : G4UserEventAction(){

  //Pass the pointer to this class;
  tree_copy = tree;
  std::cout << "Got tree at " << tree << std::endl;
}

MyExampleEventAction::~MyExampleEventAction(){ 
}

void MyExampleEventAction::BeginOfEventAction(const G4Event * event){
  
}

void MyExampleEventAction::EndOfEventAction(const G4Event * event){

}
