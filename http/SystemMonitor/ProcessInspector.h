/*
	* File     : ProcessInspector.h
	* Author   : *
	* Mail     : *
	* Creation : Wed 07 Apr 2021 08:39:24 PM CST
*/

#ifndef _PROCESSINSPECTOR_H
#define _PROCESSINSPECTOR_H


#include "Inspector.h"

namespace muduo
{
namespace net
{

class ProcessInspector : noncopyable
{
 public:
  void registerCommands(Inspector* ins);

  static string overview(HttpRequest::Method, const Inspector::ArgList&);
  static string pid(HttpRequest::Method, const Inspector::ArgList&);
  static string procStatus(HttpRequest::Method, const Inspector::ArgList&);
  static string openedFiles(HttpRequest::Method, const Inspector::ArgList&);
  static string threads(HttpRequest::Method, const Inspector::ArgList&);

  static string username_;
};

}  // namespace net
}  // namespace muduo

#endif
