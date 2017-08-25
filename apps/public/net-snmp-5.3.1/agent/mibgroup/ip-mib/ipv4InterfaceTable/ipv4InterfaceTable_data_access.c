/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id: //BBN_Linux/Branch/Branch_for_Rel_SDK_CUCTC_General_20151029/tclinux_phoenix/apps/public/net-snmp-5.3.1/agent/mibgroup/ip-mib/ipv4InterfaceTable/ipv4InterfaceTable_data_access.c#1 $
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ipv4InterfaceTable.h"


#include "ipv4InterfaceTable_data_access.h"


/** @ingroup interface 
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv4InterfaceTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * IP-MIB::ipv4InterfaceTable is subid 28 of ip.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.4.28, length: 8
 */

/**
 * initialization for ipv4InterfaceTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ipv4InterfaceTable_reg
 *        Pointer to ipv4InterfaceTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ipv4InterfaceTable_init_data(ipv4InterfaceTable_registration *
                             ipv4InterfaceTable_reg)
{
    DEBUGMSGTL(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_init_data",
                "called\n"));

    /*
     * TODO:303:o: Initialize ipv4InterfaceTable data.
     */

    return MFD_SUCCESS;
}                               /* ipv4InterfaceTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ipv4InterfaceTable_container_init(netsnmp_container **container_ptr_ptr)
{
    DEBUGMSGTL(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_container_init", "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to ipv4InterfaceTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
}                               /* ipv4InterfaceTable_container_init */


/**
 * @internal
 * determine if we want a ifTable row in our container
 */
void
ipv4InterfaceTable_check_entry_for_updates(const ifTable_rowreq_ctx *
                                           ift_rrc,
                                           netsnmp_interface_entry *entry)
{
    netsnmp_container *c = ipv4InterfaceTable_container_get();
    ifTable_rowreq_ctx *ip4if_rrc;
    int             changed = 0;

    DEBUGMSGTL(("verbose:ipv4InterfaceTable:check_entry_for_updates",
                "called\n"));

    /*
     * do we have a corresponding row?
     */
    ip4if_rrc = CONTAINER_FIND(c, ift_rrc);
    if (NULL == ip4if_rrc) {
        /*
         * no corresponding row. should we have one?
         */
        if ((NULL != entry) &&
            (entry->ns_flags & NETSNMP_INTERFACE_FLAGS_HAS_IPV4)) {
            /*
             * yes.
             */
            DEBUGMSGTL(("ipv4InterfaceTable:check_entry_for_updates",
                        "inserted row for %d\n", entry->index));
            CONTAINER_INSERT(c, ift_rrc);
            changed = 1;
        }
    } else {
        /*
         * found corresponding row. is it still applicable?
         */
        if ((NULL == entry) ||
            (0 == (entry->ns_flags & NETSNMP_INTERFACE_FLAGS_HAS_IPV4))) {
            /*
             * no
             */
            DEBUGMSGTL(("ipv4InterfaceTable:check_entry_for_updates",
                        "removed  row for %d\n",
                        ift_rrc->data.ifentry->index));
            CONTAINER_REMOVE(c, ift_rrc);
            changed = 1;
        } else {
            /*
             * still applicable. anything changed?
             */
            if ((entry->retransmit_v4 !=
                 ift_rrc->data.ifentry->retransmit_v4) ||
                (entry->reasm_max != ift_rrc->data.ifentry->reasm_max)) {
                DEBUGMSGTL(("ipv4InterfaceTable:check_entry_for_updates",
                            "row changed for %d\n",
                            ift_rrc->data.ifentry->index));
                changed = 1;
            }
        }
    }

    /*
     * if something changed, update table last changed
     */
    if (changed)
        ipv4InterfaceTable_lastChange_set(netsnmp_get_agent_uptime());
}


/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before ipv4InterfaceTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
ipv4InterfaceTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to ipv4InterfaceTable_container_shutdown\n");
        return;
    }

}                               /* ipv4InterfaceTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement ipv4InterfaceTable data load
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ipv4InterfaceTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ipv4InterfaceTable_container_load(netsnmp_container *container)
{
    DEBUGMSGT(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_container_load", "illegal call!\n"));

    return MFD_ERROR;
}                               /* ipv4InterfaceTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
ipv4InterfaceTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_container_free", "called\n"));

    /*
     * TODO:380:M: Free ipv4InterfaceTable container data.
     */
}                               /* ipv4InterfaceTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ipv4InterfaceTable_row_prep(ipv4InterfaceTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ipv4InterfaceTable:ipv4InterfaceTable_row_prep",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* ipv4InterfaceTable_row_prep */

/** @} */
