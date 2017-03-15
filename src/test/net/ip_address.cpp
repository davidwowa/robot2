/*
 * ip_address.cpp
 *
 *  Created on: 09.03.2017
 *      Author: http://stackoverflow.com/questions/2283494/get-ip-address-of-an-interface-on-linux
 */

#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/ioctl.h>

int main() {
	int fd;
	struct ifreq ifr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	/* I want to get an IPv4 IP address */
	ifr.ifr_addr.sa_family = AF_INET;

	/* I want IP address attached to "wlan0" */
	strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ - 1);

	ioctl(fd, SIOCGIFADDR, &ifr);

	close(fd);

	/* display result */
	printf("%s\n", inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr));

	return 0;
}
