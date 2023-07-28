/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "ask1.h"

int *
in_prod_1_svc(inputpair *argp, struct svc_req *rqstp)
{
	static int  result;

	for (int i = 0; i < argp->n; i++) { //calc inner product
		result += argp->X.X_val[i] * argp->Y.Y_val[i];
	}

	return &result;
}

output_avg *
avg_1_svc(inputpair *argp, struct svc_req *rqstp)
{
	static output_avg  result;
	result.avg.avg_len = 2;
	result.avg.avg_val = (float *) malloc(2 * sizeof(float));

	int sumX = 0;
	int sumY = 0;
	for (int i = 0; i < argp->n; i++) { //calc sum
		sumX += argp->X.X_val[i];
		sumY += argp->Y.Y_val[i];
	}

	//calc avg
	result.avg.avg_val[0] = (float) sumX / argp->X.X_len; //typecast to convert to float division
	result.avg.avg_val[1] = (float) sumY / argp->Y.Y_len;

	return &result;
}

output_prod_r *
prod_r_1_svc(inputpair *argp, struct svc_req *rqstp)
{
	static output_prod_r  result;

	result.arr.arr_len = argp->n;
	result.arr.arr_val = (float *) malloc(argp->n * sizeof(float));

	for (int i = 0; i < argp->n; i++) { //calc r * (X + Y)
		result.arr.arr_val[i] = argp->r * (argp->X.X_val[i] + argp->Y.Y_val[i]);
	}

	return &result;
}
