#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

#include "G4String.hh"

#include "G4VProcess.hh"

MyExampleSteppingAction::MyExampleSteppingAction(TreeBuffer * inputTreeBuffer, StepTreeBuffer * inputStepTreeBuffer, TTree * step) : G4UserSteppingAction(){

  MyTreeBuffer = inputTreeBuffer;
  MyStepTreeBuffer = inputStepTreeBuffer;

  G4cout << "Initializing stepping action" << G4endl;
  
  step_tree_copy = step;
}

MyExampleSteppingAction::~MyExampleSteppingAction(){
}

void MyExampleSteppingAction::UserSteppingAction(const G4Step * step){
  G4Track * track = step->GetTrack();
  auto prestep = step->GetPreStepPoint(); 
  auto poststep = step->GetPostStepPoint(); 

  MyTreeBuffer->tid->push_back(track->GetTrackID());
  MyTreeBuffer->pid->push_back(track->GetDefinition()->GetPDGEncoding());
  MyTreeBuffer->parid->push_back(track->GetParentID());
  MyTreeBuffer->ekin->push_back(prestep->GetKineticEnergy() / GeV);
  MyTreeBuffer->edep->push_back(step->GetTotalEnergyDeposit() / GeV); 

  
  MyTreeBuffer->xs->push_back(prestep->GetPosition().getX() / cm);
  MyTreeBuffer->ys->push_back(prestep->GetPosition().getY() / cm);
  MyTreeBuffer->zs->push_back(prestep->GetPosition().getZ() / cm);

  //Prestep Process
  auto prePro = prestep->GetProcessDefinedStep();
  if(prePro){
    auto preProName = prePro->GetProcessName(); 
    MyTreeBuffer->preStepProcess->push_back(preProName); 
  }
  else{
    MyTreeBuffer->preStepProcess->push_back("NULL"); 
  }



  //BEGIN STEP TREE FILLING

  //PostStep Process
  auto postPro = poststep->GetProcessDefinedStep(); 
  auto postProName = postPro->GetProcessName();
  MyTreeBuffer->postStepProcess->push_back(postProName); 
  MyStepTreeBuffer->stepChosenProc = postProName;
  ///

  int nPostProcs = step->postStepProcNames->size();
  std::cout << "PostStep Procs" << std::endl;
  std::cout << std::setw(15) << "Name" <<std::setw(15) << "MFP"  <<std::setw(15) << "IntLen" <<std::endl;

  MyStepTreeBuffer->stepActivePostProcNames->clear();
  MyStepTreeBuffer->stepActivePostProcMFPs->clear();
  for(int ip = 0; ip < nPostProcs; ++ip){
    std::cout << std::setw(15) << step->postStepProcNames->at(ip)  
              << std::setw(15) << step->postStepProcMFPs->at(ip) 
              << std::setw(15) << step->postStepProcIntLens->at(ip) << std::endl;
    
    MyStepTreeBuffer->stepActivePostProcNames->push_back(step->postStepProcNames->at(ip));
    MyStepTreeBuffer->stepActivePostProcMFPs->push_back(step->postStepProcMFPs->at(ip));
  }

  //MyTreeBuffer->postProcNameToMFP->push_back(tempProcNameToMFP);



  int nAlongProcs = step->alongStepProcNames->size();
  std::cout << "AlongStep Procs" << std::endl;
  std::cout << std::setw(15) << "Name" <<std::setw(15) << "MFP"  <<std::setw(15) << "IntLen" <<std::endl;

  MyStepTreeBuffer->stepActiveAlongProcNames->clear();
  MyStepTreeBuffer->stepActiveAlongProcMFPs->clear();
  for(int ip = 0; ip < nAlongProcs; ++ip){
    std::cout << std::setw(15) << step->alongStepProcNames->at(ip)  
              << std::setw(15) << step->alongStepProcMFPs->at(ip) 
              << std::setw(15) << step->alongStepProcIntLens->at(ip) << std::endl;

    MyStepTreeBuffer->stepActiveAlongProcNames->push_back(step->alongStepProcNames->at(ip));
    MyStepTreeBuffer->stepActiveAlongProcMFPs->push_back(step->alongStepProcMFPs->at(ip));
  }

  std::cout << "STEP LENGTH: " << step->GetStepLength() << std::endl;
  step_tree_copy->Fill();
}
