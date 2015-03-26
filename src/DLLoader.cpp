//
// DLLoader.cpp for dlloader in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 10:21:22 2015 moran-_d
// Last update Thu Mar 26 10:45:26 2015 moran-_d
//

#include <iostream>
#include "DLLoader.hh"

DLLoader::DLLoader()
  : _DL(NULL)
{}

DLLoader::~DLLoader()
{
  if (this->_DL != NULL)
    this->CloseDL();
}

int DLLoader::LoadDL(const std::string &st)
{
  void *handler;

  if ((handler = dlopen(st.c_str(), RTLD_LAZY | RTLD_LOCAL)) == NULL)
    {
      std::cout << "DLLoader: couldn't open from " << st << std::endl
		<< dlerror() << std::endl;
      return (-1);
    }
  this->_DL = handler;
  return (0);
}

void *DLLoader::ExtractFunction(const char *st)
{
  void *handler;

  if (this->_DL == NULL)
    {
      std::cout << "DLLoader: ExtractFunction when _DL == NULL" << std::endl;
      return (NULL);
    }
  if ((handler = dlsym(this->_DL, st)) == NULL)
    std::cout << "DLLoader: dlsym failed." << std::endl
	      << dlerror() << std::endl;
  return (handler);
}

int DLLoader::CloseDL()
{
  int ret;

  if (this->_DL == NULL)
    return (-1);
  if ((ret = dlclose(this->_DL)) < 0)
    std::cout << "DLLeror: CloseDL failed." << std::endl
	      << dlerror() << std::endl;
  this->_DL = NULL;
  return (ret);
}

IObjGraph *DLLoader::getIOGInstance()
{
  void *(*fptr)();

  if ((fptr = (void*(*)())ExtractFunction(ENTRY_POINT_ST)) == NULL)
    return (NULL);
  return ((IObjGraph*)fptr());
}
