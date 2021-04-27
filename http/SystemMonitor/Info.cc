/*
	* File     : CPUInfo.cc
	* Author   : *
	* Mail     : *
	* Creation : Mon 19 Apr 2021 02:25:58 PM CST
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include "Info.h"

#include "muduo/base/Logging.h"


double calculateCpuRateUtil(CpuInfo &last, CpuInfo &now) {
	double od, nd;
	double id, sd;
	double cpu_use;

	od = static_cast<double>(last.user + last.nice + last.system + last.idle
				   + last.softirq + last.iowait + last.irq);
	nd = static_cast<double>(now.user + now.nice + now.system + now.idle
		   + now.softirq + now.iowait + now.irq);
	id =  static_cast<double>(now.idle);
	sd =  static_cast<double>(last.idle);

	if((nd - od) != 0) {
		cpu_use = 100.0 - (id - sd)/(nd - od)*100;
	}
	else {
		cpu_use = 0.0;
	}
	return cpu_use;
}

MemInfo getMemInfo() {
	char buf[256];
    FILE *fd = fopen("/proc/meminfo", "r");
	char *ret = fgets(buf, sizeof(buf), fd);
	char name[32];
	unsigned long total;
	unsigned long mem_free;
	sscanf(buf, "%s %lu ", name, &total);

	ret = fgets(buf, sizeof(buf), fd);
    (void)ret;
	sscanf(buf, "%s %lu \n", name, &mem_free);

    long memfree = static_cast<long>(mem_free);
    long to = static_cast<long>(total);
	double rate = (1 - (static_cast<double>(memfree)/static_cast<double>(to))) * 100;

    MemInfo info;
	info.total = static_cast<double>(to)/(1024.0 * 1024.0);
	info.usedRate = rate;

    fclose(fd);
	return info;
}


DiskInfo getDiskInfo() {
    static const int KB = 1024;
    static const int MB = KB * 1024;
    static const int GB = MB * 1024;

    int state;
    struct statvfs vfs;
    DiskInfo info;
    
	fsblkcnt_t block_size = 0;
	fsblkcnt_t total_size;
	fsblkcnt_t free_size;
	fsblkcnt_t used_size;
	fsblkcnt_t avail_size;

    state = statvfs("/", &vfs);

    if(state == 0) {
        /*获取一个block的大小*/
        block_size = vfs.f_bsize; 
        /*获取总容量*/
        total_size = vfs.f_blocks * block_size;
        /*获取可用容量*/
        free_size = vfs.f_bfree * block_size;
        (void)free_size;
        /*获取使用容量*/
        used_size = (vfs.f_blocks - vfs.f_bavail) * block_size;
        /*获取有效容量*/

        avail_size = vfs.f_bavail * block_size;
        (void)avail_size;

        double disk_total = static_cast<double>(total_size);
        double disk_used = static_cast<double>(used_size) / disk_total;

        info.total = disk_total / (GB);
        info.usedRate = disk_used;

    }
    return info;
}


std::vector<std::string> split(const std::string& str, const std::string delimeter)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t pos = str.find(delimeter);
    while (pos != std::string::npos)
    {
        if (pos > start)
        {
            result.push_back(str.substr(start, pos-start));
        }
        start = pos + delimeter.size();
        pos = str.find(delimeter, start);
    }

    if (start < str.length())
    {
        result.push_back(str.substr(start));
    }

    return result;
}


NetInfo getNetInfo() {
    FILE *fd = fopen("/proc/net/dev", "r");

    NetInfo netinfo;
    std::vector<std::string> lines;
    char buf[128];
    std::string eth0;

    while(fgets(buf, sizeof(buf), fd)) {
        std::string line(buf);
        if(line.find("eth0") != std::string::npos) {
            eth0 = std::move(line);
        }
    }

    char tmp[32];
    long long RBytes;
    long long RPackets;
    long long RErrs;
    long long RDrop;
    long long RFifo;
    long long RFrame;
    long long RCompressed;
    long long RMulticast;

    long long TBytes;
    long long TPackets;
    long long TErrs;
    long long TDrop;
    long long TFifo;
    long long TFrame;
    long long TCompressed;
    long long TMulticast;

    std::stringstream ssm(eth0);
    ssm >> tmp;
    ssm >> RBytes;
    ssm >> RPackets;
    ssm >> RErrs;
    ssm >> RDrop;
    ssm >> RFifo;
    ssm >> RFrame;
    ssm >> RCompressed;
    ssm >> RMulticast;

    ssm >> TBytes;
    ssm >> TPackets;
    ssm >> TErrs;
    ssm >> TDrop;
    ssm >> TFifo;
    ssm >> TFrame;
    ssm >> TCompressed;
    ssm >> TMulticast;

    netinfo.BytesRXTotal = RBytes;
    netinfo.BytesTXTotal = TBytes;
    netinfo.BytesTotal = RBytes + TBytes;

    fclose(fd);
    return netinfo;
}

