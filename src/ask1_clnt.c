/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "ask1.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
in_prod_1(inputpair *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, IN_PROD,
		(xdrproc_t) xdr_inputpair, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

output_avg *
avg_1(inputpair *argp, CLIENT *clnt)
{
	static output_avg clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, AVG,
		(xdrproc_t) xdr_inputpair, (caddr_t) argp,
		(xdrproc_t) xdr_output_avg, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

output_prod_r *
prod_r_1(inputpair *argp, CLIENT *clnt)
{
	static output_prod_r clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PROD_R,
		(xdrproc_t) xdr_inputpair, (caddr_t) argp,
		(xdrproc_t) xdr_output_prod_r, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
