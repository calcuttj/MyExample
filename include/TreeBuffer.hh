#ifndef TreeBuffer_h
#define TreeBuffer_h 1

#include <vector>

struct TreeBuffer{
  std::vector<int> * tid;
  std::vector<int> * pid;
  std::vector<int> * track_tid;
  std::vector<int> * track_pid;
  std::vector<int> * primaryPDGs;
  int   fEvent;

  double xi, yi, zi;
};

#endif
