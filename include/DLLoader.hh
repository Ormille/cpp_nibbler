//
// DLLoader.hh for DLLoader in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 10:04:04 2015 moran-_d
// Last update Thu Mar 26 11:24:45 2015 moran-_d
//

#ifndef DLLOADER_H_
#define DLLOADER_H_

#include <string>
#include <dlfcn.h>
#include "IObjGraph.hpp"

#define ENTRY_POINT_ST	"nibbler_entry_point"

class DLLoader {
private:
  void *_DL;

public:
  DLLoader();
  ~DLLoader();

  int LoadDL(const char *);
  void *ExtractFunction(const char *);
  int CloseDL();

  IObjGraph *getIOGInstance();
};

#endif
