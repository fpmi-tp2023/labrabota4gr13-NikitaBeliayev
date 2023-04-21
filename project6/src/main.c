#include <stdio.h>
#include<sqlite3.h>
#include "../include/select_query.h"
#include "../include/insert_query.h"
#include "../include/delete_query.h"
#include "../include/parameter_query.h"

int main(int argc, char* argv[]) {
   select_query();
   insert_query();
   delete_query();
   parameter_query(7);
   return 0;
}