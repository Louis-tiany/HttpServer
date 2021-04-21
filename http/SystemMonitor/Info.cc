/*
	* File     : CPUInfo.cc
	* Author   : *
	* Mail     : *
	* Creation : Mon 19 Apr 2021 02:25:58 PM CST
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Info.h"


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
	unsigned total;
	unsigned mem_free;
	char name2[32];
	sscanf(buf, "%s %u %s\n", name, &total, name2);

	ret = fgets(buf, sizeof(buf), fd);
    (void)ret;
	sscanf(buf, "%s %u %s\n", name, &mem_free, name2);

	double rate = (1 - static_cast<double>(mem_free/total) * 100);

	total = total/(1024 * 1024);

    MemInfo info;
	info.total = total;
	info.usedRate = rate;

	return info;
}


DiskInfo getDiskInfo() {
    FILE *fp;
    char a[80], d[80], e[80], f[80], buf[256];
    double c, b;
    char *ret;
    fp = popen("df", "r");
    ret = fgets(buf, sizeof(buf), fp);                                                                                                   
    (void)ret;
    double disk_total = 0.0, disk_used = 0.0;
    while(6 == fscanf(fp,"%s %lf %lf %s %s %s", a, &b, &c, d, e, f)){
        disk_total += b;
        disk_used += c;
    }
    fclose(fp);
    DiskInfo info;
    info.total = disk_total/(1024 * 1024);
    info.usedRate = disk_used/disk_total;
    return info;
}

