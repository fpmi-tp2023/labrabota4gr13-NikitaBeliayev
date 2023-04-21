#include "../include/insert_query.h"
#include<stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int insert_query(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char* sql;

    rc = sqlite3_open("database.db", &db);

    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       return(0);
    } else {
       fprintf(stderr, "Opened database successfully\n");
    }
    
    sql = "INSERT INTO car (id, brand, color, serial_number, registration_number, release_year, inspection_year, price, vendor_id) "  \
          "VALUES (10, 'tesla', 'white', '117', '711', '2019', '2019', 100000, 2 ); " \
          "INSERT INTO car (id, brand, color, serial_number, registration_number, release_year, inspection_year, price, vendor_id) "  \
          "VALUES (11, 'ford', 'black', '118', '811', '2020', '2021', 55000, 1 ); "     \
          "INSERT INTO car (id, brand, color, serial_number, registration_number, release_year, inspection_year, price, vendor_id)" \
          "VALUES (12, 'dodge', 'red', '119', '911', '2022', '2023', 120000, 3 );";
     rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
}