#ifndef TreeBuffer_h
#define TreeBuffer_h 1

#include <vector>

struct TreeBuffer{
  std::vector<int> * tid;
  std::vector<int> * pid;
  std::vector<int> * track_tid;
  std::vector<int> * track_pid;
  std::vector<int> * primaryPDGs;
  std::vector<int> * parid;
  std::vector<double> * ekin;
  std::vector<double> * edep;
  std::vector<double> * xs, * ys, * zs;

  int   fEvent;

  double xi, yi, zi;
};

#endif
