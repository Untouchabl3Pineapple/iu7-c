#include "unit.h"

START_TEST(test_sort_array)
{
    item_t *items_array;

    items_array = (item_t*)malloc(2 * sizeof(item_t));

    items_array[0].title = (char*)malloc(10 * sizeof(char));
    strcpy(items_array[0].title, "hamit");
    items_array[0].weight = 2;
    items_array[0].volume = 1;

    items_array[1].title = (char*)malloc(10 * sizeof(char));
    strcpy(items_array[1].title, "gadzhi");
    items_array[1].weight = 1;
    items_array[1].volume = 1;

    insertion_sort(items_array, 2);

    int flag = 0;
    if (strcmp(items_array[0].title, "gadzhi") == 0 && \
    strcmp(items_array[1].title, "hamit") == 0 && items_array[0].weight == 1 && \
    items_array[0].volume == 1 && items_array[1].weight == 2 && items_array[1].volume == 1)
        flag = 1;

    free(items_array[0].title);
    free(items_array[1].title);
    free(items_array);

    ck_assert_int_eq(flag, 1);
}
END_TEST

Suite *test_sort_array_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_array);

    suite_add_tcase(s, tc_pos);

    return s;
}
