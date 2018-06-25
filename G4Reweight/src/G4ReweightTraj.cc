#include "G4ReweightTraj.hh"

G4ReweightTraj::G4ReweightTraj(){

}

G4ReweightTraj::~G4ReweightTraj(){
  stepChosenProc.clear();
  stepActivePostProcs.clear();
  stepActiveAlongProcs.clear();

  stepPx.clear();
  stepPy.clear();
  stepPz.clear();
}


