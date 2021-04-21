/*
	* File     : Inspector.h
	* Author   : *
	* Mail     : *
	* Creation : Wed 07 Apr 2021 08:20:52 PM CST
*/

#ifndef _INSPECTOR_H
#define _INSPECTOR_H

#include "muduo/base/Mutex.h"
#include "http/HttpRequest.h"
#include "http/HttpServer.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "Info.h"

#include <map>

namespace muduo
{
namespace net
{

class ProcessInspector;
class PerformanceInspector;
class SystemInspector;

// An internal inspector of the running process, usually a singleton.
// Better to run in a seperated thread, as some method may block for seconds
class Inspector : noncopyable
{
 public:
  typedef std::vector<string> ArgList;
  typedef std::function<string (HttpRequest::Method, const ArgList& args)> Callback;
  Inspector(EventLoop* loop,
            const InetAddress& httpAddr,
            const string& name);
  ~Inspector();

  /// Add a Callback for handling the special uri : /mudule/command
  void add(const string& module,
           const string& command,
           const Callback& cb,
           const string& help);
  void remove(const string& module, const string& command);

 private:
  typedef std::map<string, Callback> CommandList;
  typedef std::map<string, string> HelpList;

  void start();
  void onRequest(const HttpRequest& req, HttpResponse* resp);

  HttpServer server_;
  std::unique_ptr<ProcessInspector> processInspector_;
  std::unique_ptr<PerformanceInspector> performanceInspector_;
  std::unique_ptr<SystemInspector> systemInspector_;
  MutexLock mutex_;
  std::map<string, CommandList> modules_ GUARDED_BY(mutex_);
  std::map<string, HelpList> helps_ GUARDED_BY(mutex_);
 private:
  static double cpurate();
  static void getCpuInfo();
  static double calculateCpuRate();
 private:
  void CPUINFO();
  void MEMINFO();
  void DISKINFO();
  std::string getMemDiskInfo();
  DiskInfo diskinfo_;
  MemInfo meminfo_;

}; 
}  // namespace net
}  // namespace muduo



#endif
