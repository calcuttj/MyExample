#include "MyExampleSteppingAction.hh"
#include "G4UImanager.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

#include "G4String.hh"

#include "G4VProcess.hh"


MyExampleSteppingAction::MyExampleSteppingAction(TreeBuffer * inputTreeBuffer) : G4UserSteppingAction(){

  MyTreeBuffer = inputTreeBuffer;

  G4cout << "Initializing stepping action" << G4endl;

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

  auto prePro = prestep->GetProcessDefinedStep();
  if(prePro){
    auto preProName = prePro->GetProcessName(); 
    MyTreeBuffer->preStepProcess->push_back(preProName); 
  }
  else{
    MyTreeBuffer->preStepProcess->push_back("NULL"); 
  }

  auto postPro = poststep->GetProcessDefinedStep(); 
  auto postProName = postPro->GetProcessName();
  MyTreeBuffer->postStepProcess->push_back(postProName); 

  int nPostProcs = step->postStepProcNames->size();
  std::cout << "PostStep Procs" << std::endl;
  std::cout << std::setw(15) << "Name" <<std::setw(15) << "MFP"  <<std::setw(15) << "IntLen" <<std::endl;

  for(int ip = 0; ip < nPostProcs; ++ip){
    std::cout << std::setw(15) << step->postStepProcNames->at(ip)  
              << std::setw(15) << step->postStepProcMFPs->at(ip) 
              << std::setw(15) << step->postStepProcIntLens->at(ip) << std::endl;
    MyTreeBuffer->postProcNameToMFP[step->postStepProcNames->at(ip)] = step->postStepProcMFPs->at(ip);
  }

  int nAlongProcs = step->alongStepProcNames->size();
  std::cout << "AlongStep Procs" << std::endl;
  std::cout << std::setw(15) << "Name" <<std::setw(15) << "MFP"  <<std::setw(15) << "IntLen" <<std::endl;

  for(int ip = 0; ip < nAlongProcs; ++ip){
    std::cout << std::setw(15) << step->alongStepProcNames->at(ip)  
              << std::setw(15) << step->alongStepProcMFPs->at(ip) 
              << std::setw(15) << step->alongStepProcIntLens->at(ip) << std::endl;
    MyTreeBuffer->alongProcNameToMFP[step->alongStepProcNames->at(ip)] = step->alongStepProcMFPs->at(ip);
  }
  std::cout << "STEP LENGTH: " << step->GetStepLength() << std::endl;
  

}
