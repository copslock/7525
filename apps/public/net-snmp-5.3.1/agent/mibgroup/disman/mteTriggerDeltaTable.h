/*
 * This file was generated by mib2c and is intended for use as a mib module
 * for the ucd-snmp snmpd agent. 
 */


#ifndef _MIBGROUP_MTETRIGGERDELTATABLE_H
#define _MIBGROUP_MTETRIGGERDELTATABLE_H


/*
 * we may use header_complex from the header_complex module 
 */


config_require(header_complex)


    /*
     * enum definitions from the covered mib sections 
     */
#define MTETRIGGERDELTADISCONTINUITYIDWILDCARD_TRUE 1
#define MTETRIGGERDELTADISCONTINUITYIDWILDCARD_FALSE 2
#define MTETRIGGERDELTADISCONTINUITYIDTYPE_TIMETICKS 1
#define MTETRIGGERDELTADISCONTINUITYIDTYPE_TIMESTAMP 2
#define MTETRIGGERDELTADISCONTINUITYIDTYPE_DATEANDTIME 3
    /*
     * function prototypes 
     */
     void            init_mteTriggerDeltaTable(void);
     FindVarMethod   var_mteTriggerDeltaTable;

     WriteMethod     write_mteTriggerDeltaDiscontinuityID;
     WriteMethod     write_mteTriggerDeltaDiscontinuityIDWildcard;
     WriteMethod     write_mteTriggerDeltaDiscontinuityIDType;

#endif                          /* _MIBGROUP_MTETRIGGERDELTATABLE_H */
