/*
	* File     : SystemInspector.h
	* Author   : *
	* Mail     : *
	* Creation : Wed 07 Apr 2021 08:42:10 PM CST
*/

#ifndef _SYSTEMINSPECTOR_H
#define _SYSTEMINSPECTOR_H

#include "Inspector.h"

#include "Info.h"

namespace muduo
{
namespace net
{

class SystemInspector : noncopyable
{
 public:
  void registerCommands(Inspector* ins);

  static string overview(HttpRequest::Method, const Inspector::ArgList&);
  static string loadavg(HttpRequest::Method, const Inspector::ArgList&);
  static string version(HttpRequest::Method, const Inspector::ArgList&);
  static string cpuinfo(HttpRequest::Method, const Inspector::ArgList&);
  static string meminfo(HttpRequest::Method, const Inspector::ArgList&);
  static string stat(HttpRequest::Method, const Inspector::ArgList&);
 public:
};

}  // namespace net
}  // namespace muduo



#endif
