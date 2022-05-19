make:
	mpic++ anillo.cpp -o anillo.x
	for number in 1 2 4 8 ; do \
		$$number ; \
		mpirun -np $$number ./anillo.x ; \
	done
	rm anillo.x