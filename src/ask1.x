struct inputpair {
	int choice;
	float r;
	int n;
	int X<>;
	int Y<>;
};

struct output_avg {
	float avg<2>;
};

struct output_prod_r {
	float arr<>;
};

program OP_PROG {
		version OP_VERS {
			int IN_PROD(inputpair) = 1;
			output_avg AVG(inputpair) = 2;
			output_prod_r PROD_R(inputpair) = 3;
	} = 1;
} = 0x23451111;
