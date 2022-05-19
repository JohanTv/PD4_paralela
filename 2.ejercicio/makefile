make:
	mpic++ anillo.cpp -o anillo.x
	for number in 1 2 4 8 16 32 ; do \
		$$number ; \
		mpirun -np $$number ./anillo.x ; \
	done
