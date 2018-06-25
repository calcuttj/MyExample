#ifndef G4ReweightTraj_h
#define G4ReweightTraj_h 1


#include <vector>
#include <string>
#include <map>

class G4ReweightTraj{

  public:

    G4ReweightTraj();
    ~G4ReweightTraj();
    
    int TrackID;
    int PID;
    int parID;

    std::vector< std::string > stepChosenProc;
    std::vector< std::vector<std::string> > stepActivePostProcs;
    std::vector< std::vector<std::string> > stepActiveAlongProcs;

    std::vector<double> stepPx;
    std::vector<double> stepPy;
    std::vector<double> stepPz;

    
    //Possibly: 
    //Function: append traj
    //Function: return index of main interaction (i.e. scattering)

  protected:

  private:

};


#endif
