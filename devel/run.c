#include <assert.h>
#include <unistd.h>

#include "snippet.skel.h"

int main(int argc, char *argv[]) {
	struct snippet *skel;
	// struct snippet__data *data;
	int r;

	skel = snippet__open_and_load();
	assert(skel);

	r = snippet__attach(skel);
	assert(r == 0);

	usleep(1);

	printf("out=%d\n", skel->data->out__cpu_0_rq_cpu);

	return 0;
}
