/*
 * common.h
 *
 *  Created on: 02.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <getopt.h>
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <string>

#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

extern int is_running(std::string file_path);

#endif /* COMMON_H_ */
