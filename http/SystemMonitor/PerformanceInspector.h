/*
	* File     : PerformanceInspector.h
	* Author   : *
	* Mail     : *
	* Creation : Wed 07 Apr 2021 08:35:41 PM CST
*/

#ifndef _PERFORMANCEINSPECTOR_H
#define _PERFORMANCEINSPECTOR_H

#include "Inspector.h"

namespace muduo
{
namespace net
{

class PerformanceInspector : noncopyable
{
 public:
  void registerCommands(Inspector* ins);

  static string heap(HttpRequest::Method, const Inspector::ArgList&);
  static string growth(HttpRequest::Method, const Inspector::ArgList&);
  static string profile(HttpRequest::Method, const Inspector::ArgList&);
  static string cmdline(HttpRequest::Method, const Inspector::ArgList&);
  static string memstats(HttpRequest::Method, const Inspector::ArgList&);
  static string memhistogram(HttpRequest::Method, const Inspector::ArgList&);
  static string releaseFreeMemory(HttpRequest::Method, const Inspector::ArgList&);

  static string symbol(HttpRequest::Method, const Inspector::ArgList&);
};

}  // namespace net
}  // namespace muduo


#endif
