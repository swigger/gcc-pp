#define A(x,y) x-y
#if A(3,1)
void foo();
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "config.h"
#include "system.h"
#include "cpplib.h"

line_maps * g_linetbl = 0;

bool error_xx(cpp_reader * rd, int errtype, int b, rich_location * richloc,
	const char * msg, va_list *ap)
{
	const line_map_ordinary *map;
	source_location location = richloc->get_loc();
	linemap_resolve_location(g_linetbl, location, LRK_SPELLING_LOCATION, &map);
	expanded_location loc = linemap_expand_location(g_linetbl, map, location);
	fprintf(stderr, "%s:%d:%d %s: ", loc.file, loc.line, loc.column,
		(errtype == CPP_DL_WARNING) ? "warning" : "error");
	vfprintf(stderr, msg, *ap);
	fprintf(stderr, "\n");
	if (errtype == CPP_DL_FATAL)
		exit(1);
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
	g_linetbl = line_table;

	cpp_reader * rd = cpp_create_reader(CLK_CXX1Z, 0, line_table);
	//printf("reader is %p\n", rd);
	cpp_callbacks * cb = cpp_get_callbacks(rd);
	cb->error = error_xx;
	//cpp_init_builtins(rd, 0);

	const char * dirs[] = {
		"/usr/lib/gcc/x86_64-linux-gnu/5/include",
		"/usr/local/include",
		"/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed",
		"/usr/include/x86_64-linux-gnu",
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
	cpp_push_default_include(rd, "/home/xungeng/projects/gcc-pp/gcc-c.h");
	for (;;)
	{
		const cpp_token * tk = cpp_get_token(rd);
		if (!tk) break;
		switch (tk->type)
		{
		case CPP_PADDING:
			printf(" ");
			break;
		default:
			cpp_output_token(tk, stdout);
			printf(" ");
			break;
		}
		//printf("%s \n", tk->val.str.text);
		fflush(stdout);
	}

    return 0;
}
