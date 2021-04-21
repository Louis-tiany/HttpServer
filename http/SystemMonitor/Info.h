/*
	* File     : CPUInfo.h
	* Author   : *
	* Mail     : *
	* Creation : Mon 19 Apr 2021 11:27:07 AM CST
*/

#ifndef _CPUINFO_H
#define _CPUINFO_H

#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>

struct CpuInfo {
    char names[32];
    unsigned int user;
    unsigned int nice;
    unsigned int system;
    unsigned int idle;
    unsigned int iowait;
    unsigned int irq;
    unsigned int softirq;
    CpuInfo(){  }
};

double calculateCpuRateUtil(CpuInfo &last, CpuInfo &now);

struct MemInfo {
    double total;
    double usedRate;
};

MemInfo getMemInfo();


struct DiskInfo {
    double total;
    double usedRate;
};

DiskInfo getDiskInfo();


#endif
