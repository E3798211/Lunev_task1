
#include <stdio.h>
#include "dl_list.h"

#define N_LISTS 100

int main()
{
    srand(time(NULL));
    
    list_t* lists[N_LISTS] = {};

    for(size_t i = 0; i < N_LISTS; i++)
    {
        lists[i] = create_node();
        if (!lists[i])
            DBG_MSG("%2lu create_node() failed\n", i);
    }
    
    list_t* first = lists[0];
    
    for(size_t i = 0; i < N_LISTS - 1; i++)
    {
        if (!lists[i])    continue;
        if (!lists[i+1])  continue;
        if (!insert_after(lists[i], lists[i+1]))
            DBG_MSG("fuck\n");
    }

    while((first = delete_node(first)));
//    for(size_t i = 0; i < N_LISTS; i++)
//        set_value(lists[i], (int)i);
//
//    size_t i = 0;
//    while(!lists[i++]); i--;
//
//    printf("================    start printing [%lu]\n", i);
//    print_list(lists[i]);
//    printf("================      end printing\n");

//    for(size_t i = 0; i < N_LISTS; i++)
//        free(lists[i]);

    return 0;
}

