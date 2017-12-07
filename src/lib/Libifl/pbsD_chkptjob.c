/* Copyright 2008 Cluster Resources
*/
/* pbs_chkptjob.c

 Send the Checkpoint Job request to the server --
 really just an instance of the "manager" request.
*/

#include <pbs_config.h>   /* the master config generated by configure */

#include <stdio.h>
#include "libpbs.h"
#include "server_limits.h"

int pbs_checkpointjob_err(
    
  int   c,
  char *jobid,
  char *extend,
  int  *local_errno)

  {
  if ((jobid == (char *)0) || (*jobid == '\0'))
    return (PBSE_IVALREQ);
  
  if ((c < 0) || 
      (c >= PBS_NET_MAX_CONNECTIONS))
    {
    return(PBSE_IVALREQ);
    }

  return PBSD_manager(c, PBS_BATCH_CheckpointJob,
                      MGR_CMD_SET,
                      MGR_OBJ_JOB,
                      jobid,
                      NULL,
                      extend,
                      local_errno);
  } /* END pbs_checkpointjob_err() */





int pbs_checkpointjob(
    
  int   c,
  char *jobid,
  char *extend)

  {
  pbs_errno = 0;

  return(pbs_checkpointjob_err(c, jobid, extend, &pbs_errno));
  } /* END pbs_checkpointjob() */



