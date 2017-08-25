#ifndef _CP_LAN_INTERFACES_H_
#define _CP_LAN_INTERFACES_H_

#include "cp_core.h"

#define LANINTERFACENUM 4

extern CwmpParameterStruct LANEthernetInterfaceConfigIndex[];
extern CwmpParameterStruct LANEthernetInterfaceConfig[];

int8 getMACAddressNumValue(char** value, ParameterType* type, DeviceNode*  deviceNode);
int8 setMACAddressNumValue(void* value, struct DeviceNode*  deviceNode);
int8 getMACAddressNumAttribute(uint8* notification, AccessEntry** acl, DeviceNode* deviceNode);
int8 setMACAddressNumAttribute(uint8 notificationChange, uint8 notification, uint8 accessListChange, AccessEntry* acl, struct DeviceNode*  deviceNode);

int8 getLanEtherTypeFilterValue(char** value, ParameterType* type, DeviceNode*  deviceNode);
int8 setLanEtherTypeFilterValue(void* value, struct DeviceNode*  deviceNode);
int8 getLanEtherTypeFilterAttribute(uint8* notification, AccessEntry** acl, DeviceNode* deviceNode);
int8 setLanEtherTypeFilterAttribute(uint8 notificationChange, uint8 notification, uint8 accessListChange, AccessEntry* acl, struct DeviceNode*  deviceNode);

#ifdef TCSUPPORT_WLAN
int8 getAssociateNumValue(char** value, ParameterType* type, DeviceNode*  deviceNode);
int8 setAssociateNumValue(void* value, struct DeviceNode*  deviceNode);
int8 getAssociateNumAttribute(uint8* notification, AccessEntry** acl, DeviceNode* deviceNode);
int8 setAssociateNumAttribute(uint8 notificationChange, uint8 notification, uint8 accessListChange, AccessEntry* acl, struct DeviceNode*  deviceNode);

int8 getWlanEtherTypeFilterValue(char** value, ParameterType* type, DeviceNode*  deviceNode);
int8 setWlanEtherTypeFilterValue(void* value, struct DeviceNode*  deviceNode);
int8 getWlanEtherTypeFilterAttribute(uint8* notification, AccessEntry** acl, DeviceNode* deviceNode);
int8 setWlanEtherTypeFilterAttribute(uint8 notificationChange, uint8 notification, uint8 accessListChange, AccessEntry* acl, struct DeviceNode*  deviceNode);

int	cwmpInitWLANConfigurationFuncsSubTree( DeviceNodePtr deviceNode );
extern CwmpParameterStruct WLANConfigurationIndex[];
extern CwmpParameterStruct WLANConfiguration[];
#endif
int	cwmpInitLANEthernetInterfaceConfigfuncsSubTree( DeviceNodePtr deviceNode );

#endif
