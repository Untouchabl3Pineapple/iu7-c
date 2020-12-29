#ifndef __UNIT_H__

#define __UNIT_H__

#include <check.h>
#include <stdlib.h>

#include "../inc/constants.h"
#include "../inc/io_lib.h"
#include "../inc/process_lib.h"

#define ARRAY_SIZE 10

Suite *parse_args_suite(Suite *s);

Suite *key_suite(Suite *s);

#endif // __UNIT_H__
