#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "config.h"
#include "system.h"
#include "cpplib.h"

bool error_xx(cpp_reader * rd, int a, int b, rich_location * loc,
	const char * msg, va_list *v)
{
	char * msgo = 0;
	vasprintf(&msgo, msg, *v);
	fprintf(stderr, "ERROR: %s\n", msgo);
	free(msgo);
	abort();
	return true;
}


static size_t round_alloc_size(size_t s)
{
	return s;
}

int main(int argc, const char * argv[])
{
	line_maps * line_table;
	line_table = XCNEW(struct line_maps);
	linemap_init(line_table, 0);
	line_table->reallocator = realloc;
	line_table->round_alloc_size = round_alloc_size;

	cpp_reader * rd = cpp_create_reader(CLK_CXX1Z, 0, line_table);
	printf("%p\n", rd);
	cpp_callbacks * cb = cpp_get_callbacks(rd);
	cb->error = error_xx;
	
	const char * dirs[] = {
		"/usr/include",
		0
	};
	cpp_dir * head = 0, **cur = &head;
	for (uint32_t i=0; dirs[i]; ++i)
	{
		(*cur) = XCNEW(cpp_dir);
		(*cur)->name = (char*) dirs[i];
		cur = & (*cur)->next;
	}
	cpp_set_include_chains(rd, head, head,  false);

	cpp_read_main_file(rd, __FILE__);
	for (;;)
	{
		const cpp_token * tk = cpp_get_token(rd);
		printf("%s \n", tk->val.str.text);
		fflush(stdout);
	}

    return 0;
}
