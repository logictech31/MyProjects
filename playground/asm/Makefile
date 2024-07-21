%.o: %.S
	as -gstabs -o $@ $<
%.out: %.o
	ld -o $@ $<
.PHONY:
	clean
clean:
	rm -f *.o *.out
