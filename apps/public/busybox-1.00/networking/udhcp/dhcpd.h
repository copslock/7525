/* dhcpd.h */
#ifndef _DHCPD_H
#define _DHCPD_H

#include <netinet/ip.h>
#include <netinet/udp.h>

#include "libbb_udhcp.h"
#include "leases.h"
#include "version.h"

/************************************/
/* Defaults _you_ may want to tweak */
/************************************/

/* the period of time the client is allowed to use that address */
#define LEASE_TIME              (60*60*24*10) /* 10 days of seconds */
#define LEASES_FILE		"/var/lib/misc/udhcpd.leases"

/* where to find the DHCP server configuration file */
#define DHCPD_CONF_FILE         "/etc/udhcpd.conf"
#ifdef TCSUPPORT_FON_V2
#define FON_DHCPD_CONF_FILE         "/etc/udhcpd.fon.conf"
#endif

#ifdef DHCP_PROFILE
#define DHCPD_OPTION_CONF_FILE         "/etc/udhcpd_option.conf"
#if defined(TCSUPPORT_CT_E8GUI)
#define DHCPD_OPTION_STB_CONF_FILE         "/etc/udhcpd_stb_option.conf"
#define DHCPD_OPTION_PHONE_CONF_FILE         "/etc/udhcpd_phone_option.conf"
#define DHCPD_OPTION_CAMERA_CONF_FILE         "/etc/udhcpd_camera_option.conf"
#define DHCPD_OPTION_HGW_CONF_FILE			"/etc/udhcpd_hgw_option.conf"
#endif

#endif
/*****************************************************************/
/* Do not modify below here unless you know what you are doing!! */
/*****************************************************************/

/* DHCP protocol -- see RFC 2131 */
#define SERVER_PORT		67
#define CLIENT_PORT		68

#define DHCP_MAGIC		0x63825363

/* DHCP option codes (partial list) */
#define DHCP_PADDING		0x00
#define DHCP_SUBNET		0x01
#define DHCP_TIME_OFFSET	0x02
#define DHCP_ROUTER		0x03
#define DHCP_TIME_SERVER	0x04
#define DHCP_NAME_SERVER	0x05
#define DHCP_DNS_SERVER		0x06
#define DHCP_LOG_SERVER		0x07
#define DHCP_COOKIE_SERVER	0x08
#define DHCP_LPR_SERVER		0x09
#define DHCP_HOST_NAME		0x0c
#define DHCP_BOOT_SIZE		0x0d
#define DHCP_DOMAIN_NAME	0x0f
#define DHCP_SWAP_SERVER	0x10
#define DHCP_ROOT_PATH		0x11
#define DHCP_IP_TTL		0x17
#define DHCP_MTU		0x1a
#define DHCP_BROADCAST		0x1c
#define DHCP_NTP_SERVER		0x2a
#define DHCP_WINS_SERVER	0x2c
#define DHCP_REQUESTED_IP	0x32
#define DHCP_LEASE_TIME		0x33
#define DHCP_OPTION_OVER	0x34
#define DHCP_MESSAGE_TYPE	0x35
#define DHCP_SERVER_ID		0x36
#define DHCP_PARAM_REQ		0x37
#define DHCP_MESSAGE		0x38
#define DHCP_MAX_SIZE		0x39
#define DHCP_T1			0x3a
#define DHCP_T2			0x3b
#define DHCP_VENDOR		0x3c
#define DHCP_CLIENT_ID		0x3d

//#if defined (CWMP) && defined(TR111)
#define OPT_VENDOR_INFOR	0x7d
//#endif
#define DHCP_END		0xFF


#define BOOTREQUEST		1
#define BOOTREPLY		2

#define ETH_10MB		1
#define ETH_10MB_LEN		6

#define DHCPDISCOVER		1
#define DHCPOFFER		2
#define DHCPREQUEST		3
#define DHCPDECLINE		4
#define DHCPACK			5
#define DHCPNAK			6
#define DHCPRELEASE		7
#define DHCPINFORM		8
#if defined(TCSUPPORT_CT_DHCP_FORCERENEW)
#define DHCPFORCERENEW    9
#endif

#define BROADCAST_FLAG		0x8000

#define OPTION_FIELD		0
#define FILE_FIELD		1
#define SNAME_FIELD		2

/* miscellaneous defines */
#define MAC_BCAST_ADDR		(uint8_t *) "\xff\xff\xff\xff\xff\xff"
#define OPT_CODE 0
#define OPT_LEN 1
#define OPT_DATA 2

struct option_set {
	uint8_t *data;
	struct option_set *next;
};

struct static_lease {
	uint8_t *mac;
	uint32_t *ip;
	struct static_lease *next;
};

struct server_config_t {
	uint32_t server;		/* Our IP, in network order */
	uint32_t start;		/* Start address of leases, network order */
	uint32_t end;			/* End of leases, network order */
	struct option_set *options;	/* List of DHCP options loaded from the config file */
	char *interface;		/* The name of the interface to use */
	int ifindex;			/* Index number of the interface to use */
	uint8_t arp[6];		/* Our arp address */
	unsigned long lease;		/* lease time in seconds (host order) */
	unsigned long max_leases; 	/* maximum number of leases (including reserved address) */
	char remaining; 		/* should the lease file be interpreted as lease time remaining, or
			 		 * as the time the lease expires */
	unsigned long auto_time; 	/* how long should udhcpd wait before writing a config file.
					 * if this is zero, it will only write one on SIGUSR1 */
	unsigned long decline_time; 	/* how long an address is reserved if a client returns a
				    	 * decline message */
	unsigned long conflict_time; 	/* how long an arp conflict offender is leased for */
	unsigned long offer_time; 	/* how long an offered address is reserved */
	unsigned long min_lease; 	/* minimum lease a client can request*/
	char *lease_file;
	char *pidfile;
	char *notify_file;		/* What to run whenever leases are written */
	uint32_t siaddr;		/* next server bootp option */
	char *sname;			/* bootp server name */
	char *boot_file;		/* bootp boot file option */
	struct static_lease *static_leases; /* List of ip/mac pairs to assign static leases */
};

#if defined(TCSUPPORT_CT_IPTV_NODE)
#define CLINETID_LEN 7
typedef struct STBDev_S
{
	uint8_t clientID[CLINETID_LEN];
	struct STBDev_S* next;	
}STBDev_t;

typedef struct STB_Param_s
{
	uint32_t 	iTotalNumber; /* Number of STB */
	STBDev_t* header;	
	STBDev_t* tail;
} STB_Param_t;
#endif

#if defined (CWMP) && defined(TR111)
#define CLINETID_LENGTH 7
typedef struct ManageableDev_S
{
	char oui[7];
	char sn[65];
	char pclass[65];
	uint8_t clientID[CLINETID_LENGTH];
	uint32_t hostnum; 
	uint32_t hostindex[8];
	struct ManageableDev_S* next;	
}mDev_t;

typedef struct Tr111_Param_s
{
	uint32_t 	iTotalNumber; /* Number of Entries */
	uint32_t	iNotifyTimer; /* Notification timer */
	uint32_t  iNotifyFlag;
	mDev_t* VIHeader;	
	mDev_t* VITail;
} Tr111_Param_t;

#endif

#ifdef DHCP_PROFILE
#define VENDOR_CLASS_ID_LEN_MAX	64

typedef struct Option60_Param_s{
	uint8_t enable;
	char *dhcp_opt60_vid;

} Option60_Param_s;

typedef struct Option240_Param_s{
	uint8_t enable;
	char *dhcp_opt240_value;
} Option240_Param_s;
#endif

extern struct server_config_t server_config;
extern struct dhcpOfferedAddr *leases;

#ifdef DHCP_PROFILE
extern struct server_config_t option60_config;
extern struct Option60_Param_s gOption60_Param;
extern struct Option240_Param_s gOption240_Param;
#endif
extern struct server_config_t dhcp_config;
extern unsigned long gTotalMaxLeases;

#endif
