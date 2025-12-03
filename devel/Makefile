all: run

# this requires also libbpf-devel

snippet.bpf.c: vmlinux.h
run: snippet.skel.h

LDFLAGS=-lbpf

.PRECIOUS: snippet.bpf.o

%.o: %.bpf.o
	bpftool gen object $@ $<

%.bpf.o: %.bpf.c
	clang --target=bpf -g -c $< -o $@

%.skel.h: %.bpf.o
	bpftool gen skeleton $< name $* >$@

vmlinux.h:
	bpftool btf dump file /sys/kernel/btf/vmlinux format c >$@
