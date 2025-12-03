// based on tools/testing/selftests/bpf/progs/test_ksyms_btf.c

#include "vmlinux.h"

#include <bpf/bpf_helpers.h>

__u32 out__cpu_0_rq_cpu = -1; /* cpu_rq(0)->cpu */

extern const struct rq runqueues __ksym; /* struct type global var. */

SEC("raw_tp/sys_enter")
int handler(const void *ctx)
{
	struct rq *rq;

	// rq = (struct rq *)bpf_per_cpu_ptr(&runqueues, 0);
	rq = (struct rq *)&runqueues;

	// if (rq)
		out__cpu_0_rq_cpu = rq->cpu;

	return 0;
}

char _license[] SEC("license") = "GPL";
