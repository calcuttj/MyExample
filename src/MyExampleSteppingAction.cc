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

  int nProcs = step->postStepProcNames->size();
  std::cout << step->postStepProcNames->size() << " Names" << std::endl;
  std::cout << step->postStepProcMFPs->size() << " MFPs" << std::endl;
  std::cout << step->postStepProcIntLens->size() << " IntLens" << std::endl;

  std::cout << std::setw(15) << "Name" <<std::setw(10) << "MFP"  <<std::setw(10) << "IntLen" <<std::endl;

  for(int ip = 0; ip < nProcs; ++ip){
    std::cout << std::setw(15) << step->postStepProcNames->at(ip)  
              << std::setw(15) << step->postStepProcMFPs->at(ip) 
              << std::setw(15) << step->postStepProcIntLens->at(ip) << std::endl;
  }
  std::cout << "STEP LENGTH: " << step->GetStepLength << std::endl;
  

/*  for(int i = 0; i < step->postStepProcList->size(); ++i){    
    std::cout << step->postStepProcList->at(i).name << std::endl;
  }*/

/*  auto preMat = prestep->GetMaterial();
  if(preMat){
    MyTreeBuffer->preStepMat->push_back(preMat->GetName());
  }
  else{
    MyTreeBuffer->preStepMat->push_back("NoMat");
  }

  auto postMat = poststep->GetMaterial();
  if(postMat){
    MyTreeBuffer->postStepMat->push_back(postMat->GetName());
  }
  else{
    MyTreeBuffer->postStepMat->push_back("NoMat");
  } */
}
