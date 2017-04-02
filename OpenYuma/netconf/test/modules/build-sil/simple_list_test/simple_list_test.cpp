
/* 
 * Copyright (c) 2008-2012, Andy Bierman, All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.2.1732

    Combined SIL module
    module simple_list_test
    revision 2008-11-20
    namespace http://netconfcentral.org/ns/simple_list_test

 */

extern "C" {
#include <xmlstring.h>

#include "procdefs.h"
#include "agt.h"
#include "agt_cb.h"
#include "agt_rpc.h"
#include "agt_timer.h"
#include "agt_util.h"
#include "dlq.h"
#include "ncx.h"
#include "ncx_feature.h"
#include "ncxmod.h"
#include "ncxtypes.h"
#include "rpc.h"
#include "ses.h"
#include "status.h"
#include "val.h"
#include "val_util.h"
#include "xml_util.h"
#include "simple_list_test.h"
}

#include "test/support/callbacks/sil-callback-log.h"
#include "test/support/callbacks/sil-callback-controller.h"

/* module static variables */
static ncx_module_t *simple_list_test_mod;
static obj_template_t *simple_list_obj;
static obj_template_t *inc_counter_obj;
static obj_template_t *get_counter_obj;
static val_value_t *simple_list_val;

/* put your static variables here */
static uint32 count_static;

/********************************************************************
* FUNCTION y_simple_list_test_init_static_vars
* 
* initialize module static variables
* 
********************************************************************/
static void y_simple_list_test_init_static_vars (void)
{
    simple_list_test_mod = NULL;
    simple_list_obj = NULL;
    inc_counter_obj = NULL;
    get_counter_obj = NULL;
    simple_list_val = NULL;

    /* init your static variables here */
    count_static = 0;

} /* y_simple_list_test_init_static_vars */


/********************************************************************
* FUNCTION simple_list_test_simple_list_theList_theKey_edit
* 
* Edit database object callback
* Path: /simple_list/theList/theKey
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t simple_list_test_simple_list_theList_theKey_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter simple_list_test_simple_list_theList_theKey_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "simple_list_test_simple_list_theList_theKey_edit";
    val_value_t* value = (newval) ? newval : curval;
    std::string module_name = (char*) val_get_mod_name(value);

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        cbData.cbType = "validate";
        cbLog.addCallback(module_name, cbData);
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        cbData.cbType = "apply";
        cbLog.addCallback(module_name, cbData);
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        cbData.cbType = "commit";
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            cbData.cbPhase = "load";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_MERGE:
            cbData.cbPhase = "merge";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_REPLACE:
            cbData.cbPhase = "replace";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_CREATE:
            cbData.cbPhase = "create";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_DELETE:
            cbData.cbPhase = "delete";
            cbLog.addCallback(module_name, cbData);
            break;
        default:
            cbData.cbPhase = "default";
            cbLog.addCallback(module_name, cbData);
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        cbData.cbType = "rollback";
        cbLog.addCallback(module_name, cbData);
        /* undo device instrumentation here */
        break;
    default:
        cbData.cbType = "default";
        cbLog.addCallback(module_name, cbData);
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* simple_list_test_simple_list_theList_theKey_edit */


/********************************************************************
* FUNCTION simple_list_test_simple_list_theList_theVal_edit
* 
* Edit database object callback
* Path: /simple_list/theList/theVal
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t simple_list_test_simple_list_theList_theVal_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter simple_list_test_simple_list_theList_theVal_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "simple_list_test_simple_list_theList_theVal_edit";
    val_value_t* value = (newval) ? newval : curval;
    std::string module_name = (char*) val_get_mod_name(value);

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        cbData.cbType = "validate";
        cbLog.addCallback(module_name, cbData);
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        cbData.cbType = "apply";
        cbLog.addCallback(module_name, cbData);
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        cbData.cbType = "commit";
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            cbData.cbPhase = "load";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_MERGE:
            cbData.cbPhase = "merge";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_REPLACE:
            cbData.cbPhase = "replace";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_CREATE:
            cbData.cbPhase = "create";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_DELETE:
            cbData.cbPhase = "delete";
            cbLog.addCallback(module_name, cbData);
            break;
        default:
            cbData.cbPhase = "default";
            cbLog.addCallback(module_name, cbData);
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        cbData.cbType = "rollback";
        cbLog.addCallback(module_name, cbData);
        /* undo device instrumentation here */
        break;
    default:
        cbData.cbType = "default";
        cbLog.addCallback(module_name, cbData);
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* simple_list_test_simple_list_theList_theVal_edit */


/********************************************************************
* FUNCTION simple_list_test_simple_list_theList_edit
* 
* Edit database object callback
* Path: /simple_list/theList
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t simple_list_test_simple_list_theList_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter simple_list_test_simple_list_theList_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "simple_list_test_simple_list_theList_edit";
    val_value_t* value = (newval) ? newval : curval;
    std::string module_name = (char*) val_get_mod_name(value);

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        cbData.cbType = "validate";
        cbLog.addCallback(module_name, cbData);
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        cbData.cbType = "apply";
        cbLog.addCallback(module_name, cbData);
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        cbData.cbType = "commit";
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            cbData.cbPhase = "load";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_MERGE:
            cbData.cbPhase = "merge";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_REPLACE:
            cbData.cbPhase = "replace";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_CREATE:
            cbData.cbPhase = "create";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_DELETE:
            cbData.cbPhase = "delete";
            cbLog.addCallback(module_name, cbData);
            break;
        default:
            cbData.cbPhase = "default";
            cbLog.addCallback(module_name, cbData);
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }
        break;
    case AGT_CB_ROLLBACK:
        cbData.cbType = "rollback";
        cbLog.addCallback(module_name, cbData);
        /* undo device instrumentation here */
        break;
    default:
        cbData.cbType = "default";
        cbLog.addCallback(module_name, cbData);
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* simple_list_test_simple_list_theList_edit */


/********************************************************************
* FUNCTION simple_list_test_simple_list_edit
* 
* Edit database object callback
* Path: /simple_list
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t simple_list_test_simple_list_edit (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
    status_t res = NO_ERR;
    val_value_t *errorval = (curval) ? curval : newval;

    if (LOGDEBUG) {
        log_debug("\nEnter simple_list_test_simple_list_edit callback for %s phase",
            agt_cbtype_name(cbtyp));
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackController& cbController = YumaTest::SILCallbackController::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "simple_list_test_simple_list_edit";
    val_value_t* value = (newval) ? newval : curval;
    std::string module_name = (char*) val_get_mod_name(value);

    switch (cbtyp) {
    case AGT_CB_VALIDATE:
        cbData.cbType = "validate";
        cbLog.addCallback(module_name, cbData);
        /* description-stmt validation here */
        break;
    case AGT_CB_APPLY:
        cbData.cbType = "apply";
        cbLog.addCallback(module_name, cbData);
        /* database manipulation done here */
        break;
    case AGT_CB_COMMIT:
        cbData.cbType = "commit";
        /* device instrumentation done here */
        switch (editop) {
        case OP_EDITOP_LOAD:
            cbData.cbPhase = "load";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_MERGE:
            cbData.cbPhase = "merge";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_REPLACE:
            cbData.cbPhase = "replace";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_CREATE:
            if(!cbController.createSuccess()) {
                res = SET_ERROR(ERR_INTERNAL_VAL);
            }
            cbData.cbPhase = "create";
            cbLog.addCallback(module_name, cbData);
            break;
        case OP_EDITOP_DELETE:
            cbData.cbPhase = "delete";
            cbLog.addCallback(module_name, cbData);
            break;
        default:
            cbData.cbPhase = "default";
            cbLog.addCallback(module_name, cbData);
            res = SET_ERROR(ERR_INTERNAL_VAL);
        }

        if (res == NO_ERR) {
            res = agt_check_cache(&simple_list_val, newval, curval, editop);
        }
        
        break;
    case AGT_CB_ROLLBACK:
        cbData.cbType = "rollback";
        cbLog.addCallback(module_name, cbData);
        /* undo device instrumentation here */
        break;
    default:
        cbData.cbType = "default";
        cbLog.addCallback(module_name, cbData);
        res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_CONTENT,
            res,
            NULL,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }
    return res;

} /* simple_list_test_simple_list_edit */


/********************************************************************
* FUNCTION y_simple_list_test_inc_counter_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_simple_list_test_inc_counter_validate (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;
    val_value_t *errorval = NULL;


    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_OPERATION,
            res,
            methnode,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "y_simple_list_test_inc_counter_validate";
    cbLog.addCallback("simple_list_test", cbData);

    return res;

} /* y_simple_list_test_inc_counter_validate */


/********************************************************************
* FUNCTION y_simple_list_test_inc_counter_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_simple_list_test_inc_counter_invoke (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;


    /* remove the next line if scb is used */
    (void)scb;

    /* remove the next line if msg is used */
    (void)msg;

    /* remove the next line if methnode is used */
    (void)methnode;

    /* invoke your device instrumentation code here */
    count_static++;

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "y_simple_list_test_inc_counter_invoke";
    cbLog.addCallback("simple_list_test", cbData);

    return res;

} /* y_simple_list_test_inc_counter_invoke */


/********************************************************************
* FUNCTION y_simple_list_test_get_counter_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_simple_list_test_get_counter_validate (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;
    val_value_t *errorval = NULL;


    if (res != NO_ERR) {
        agt_record_error(
            scb,
            &msg->mhdr,
            NCX_LAYER_OPERATION,
            res,
            methnode,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval,
            (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
            errorval);
    }

    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "y_simple_list_test_get_counter_validate";
    cbLog.addCallback("simple_list_test", cbData);

    return res;

} /* y_simple_list_test_get_counter_validate */


/********************************************************************
* FUNCTION y_simple_list_test_get_counter_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_simple_list_test_get_counter_invoke (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
    status_t res = NO_ERR;
    val_value_t     *countVal;
    xmlChar          countBuff[100];

    /* remove the next line if scb is used */
    (void)scb;

    /* remove the next line if msg is used */
    (void)msg;

    /* remove the next line if methnode is used */
    (void)methnode;

    /* invoke your device instrumentation code here */
    YumaTest::SILCallbackLog& cbLog = YumaTest::SILCallbackLog::getInstance();
    YumaTest::SILCallbackLog::CallbackInfo cbData;
    cbData.cbName = "y_simple_list_test_get_counter_invoke";
    cbLog.addCallback("simple_list_test", cbData);

    snprintf((char *)countBuff, sizeof(countBuff), "%u", count_static);
    countVal = val_make_string(0,
                               (xmlChar*)"count",
                               countBuff);
    if (countVal == NULL) {
        val_free_value(countVal);
        return ERR_INTERNAL_MEM;
    }

    dlq_enque(countVal, &msg->rpc_dataQ);
    msg->rpc_data_type = RPC_DATA_STD;

    return res;

} /* y_simple_list_test_get_counter_invoke */

/********************************************************************
* FUNCTION y_simple_list_test_init
* 
* initialize the simple_list_test server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_simple_list_test_init (
    const xmlChar *modname,
    const xmlChar *revision)
{
    status_t res = NO_ERR;
    agt_profile_t *agt_profile = agt_get_profile();

    y_simple_list_test_init_static_vars();

    /* change if custom handling done */
    if (xml_strcmp(modname, y_simple_list_test_M_simple_list_test)) {
        return ERR_NCX_UNKNOWN_MODULE;
    }

    if (revision && xml_strcmp(revision, y_simple_list_test_R_simple_list_test)) {
        return ERR_NCX_WRONG_VERSION;
    }
    res = ncxmod_load_module(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_R_simple_list_test,
        &agt_profile->agt_savedevQ,
        &simple_list_test_mod);
    if (res != NO_ERR) {
        return res;
    }

    simple_list_obj = ncx_find_object(
        simple_list_test_mod,
        y_simple_list_test_N_simple_list);
    if (simple_list_test_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    inc_counter_obj = ncx_find_object(
        simple_list_test_mod,
        y_simple_list_test_N_inc_counter);
    if (simple_list_test_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    get_counter_obj = ncx_find_object(
        simple_list_test_mod,
        y_simple_list_test_N_get_counter);
    if (simple_list_test_mod == NULL) {
        return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    res = agt_rpc_register_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_inc_counter,
        AGT_RPC_PH_VALIDATE,
        y_simple_list_test_inc_counter_validate);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_inc_counter,
        AGT_RPC_PH_INVOKE,
        y_simple_list_test_inc_counter_invoke);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_get_counter,
        AGT_RPC_PH_VALIDATE,
        y_simple_list_test_get_counter_validate);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_rpc_register_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_get_counter,
        AGT_RPC_PH_INVOKE,
        y_simple_list_test_get_counter_invoke);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list",
        y_simple_list_test_R_simple_list_test,
        simple_list_test_simple_list_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList",
        y_simple_list_test_R_simple_list_test,
        simple_list_test_simple_list_theList_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList/theKey",
        y_simple_list_test_R_simple_list_test,
        simple_list_test_simple_list_theList_theKey_edit);
    if (res != NO_ERR) {
        return res;
    }

    res = agt_cb_register_callback(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList/theVal",
        y_simple_list_test_R_simple_list_test,
        simple_list_test_simple_list_theList_theVal_edit);
    if (res != NO_ERR) {
        return res;
    }

    /* put your module initialization code here */
    
    return res;
} /* y_simple_list_test_init */

/********************************************************************
* FUNCTION y_simple_list_test_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_simple_list_test_init2 (void)
{
    status_t res = NO_ERR;

    simple_list_val = agt_init_cache(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_simple_list,
        &res);
    if (res != NO_ERR) {
        return res;
    }

    /* put your init2 code here */

    return res;
} /* y_simple_list_test_init2 */

/********************************************************************
* FUNCTION y_simple_list_test_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
void y_simple_list_test_cleanup (void)
{
    
    agt_rpc_unregister_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_inc_counter);
    
    agt_rpc_unregister_method(
        y_simple_list_test_M_simple_list_test,
        y_simple_list_test_N_get_counter);
    agt_cb_unregister_callbacks(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list");

    agt_cb_unregister_callbacks(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList");

    agt_cb_unregister_callbacks(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList/theKey");

    agt_cb_unregister_callbacks(
        y_simple_list_test_M_simple_list_test,
        (const xmlChar *)"/simple_list/theList/theVal");

    /* put your cleanup code here */
    
} /* y_simple_list_test_cleanup */

/* END simple_list_test.c */
