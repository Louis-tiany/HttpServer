/*
	* File     : InspectorTest.cc
	* Author   : *
	* Mail     : *
	* Creation : Wed 07 Apr 2021 09:00:36 PM CST
*/

#include <iostream>
  
#include "http/SystemMonitor/Inspector.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/EventLoopThread.h"

using namespace muduo;
using namespace muduo::net;

int main()
{
  EventLoop loop;
  EventLoopThread t;
  Inspector ins(t.startLoop(), InetAddress(8888), "louis");
  loop.loop();
}

