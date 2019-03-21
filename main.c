#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

void finish_with_error(MYSQL *con) {
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

void create_db() {
	MYSQL *con = mysql_init(NULL);	
	if (con == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}	
	if (mysql_real_connect(con, "localhost", "root", "p@ssw0rd2535", NULL, 0, NULL, 0 )== NULL) {
		finish_with_error(con);
	}	
	if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS testdb")) {
		finish_with_error(con);
	}
	
	mysql_close(con);	
}

void init_data(MYSQL *con) {	
	if (mysql_query(con, "DROP TABLE IF EXISTS Cars")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(1, 'Audi', 52642)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(2, 'Mercedes', 57127)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(3, 'Skoda', 9000)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(4, 'Volvo', 29000)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(5, 'Bentley', 350000)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(6, 'Citroen', 21000)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(7, 'Hummer', 41400)")) {
		finish_with_error(con);
	}
	
	if (mysql_query(con, "INSERT INTO cars VALUES(8, 'Volkswagen', 21600)")) {
		finish_with_error(con);
	}
}

void fetch_data(MYSQL *con) {
	if (mysql_query(con, "SELECT * FROM Cars")) {
		finish_with_error(con);
	}
	
	MYSQL_RES *result = mysql_store_result(con);
	if (result == NULL) {
		finish_with_error(con);
	}
	
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
		int i;
		for(i=0;i<num_fields;i++){
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	mysql_free_result(result);
}

void fetch_data_column(MYSQL *con) {
	if (mysql_query(con, "SELECT * FROM Cars")) {
		finish_with_error(con);
	}
	
	MYSQL_RES *result = mysql_store_result(con);
	if (result == NULL) {
		finish_with_error(con);
	}
	
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	
	while((row = mysql_fetch_row(result))) {
		int i;
		for (i = 0; i < num_fields; i++) {
			if (i == 0) {
				while(field = mysql_fetch_field(result)) {
					printf("%s ", field->name);
				}
				
				printf("\n");
			}
			
			printf("%s ", row[i] ? row[i] : "NULL");
		}
	}
	
	printf("\n");
	
	mysql_free_result(result);
}

void update_data(MYSQL *con) {
	if (mysql_query(con, "UPDATE Cars SET price=9999 WHERE id=3")) {
		finish_with_error(con);
	}
}

void delete_data(MYSQL *con) {
	if (mysql_query(con, "DELETE from Cars where id=8")) {
		finish_with_error(con);
	}
}

int main() {
	printf("MySQL client version: %s\n", mysql_get_client_info());
	
	// create new database
	create_db();
	
	// open exist connection
	MYSQL *con = mysql_init(NULL);	
	if (con == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}
	
	if (mysql_real_connect(con, "localhost", "root", "p@ssw0rd2535", "testdb", 0, NULL, 0) == NULL) {
		finish_with_error(con);
	}
	
	// initial data
//	init_data(con);
	
	// fetch data from table
//	fetch_data(con);

	// fetch data with header column
//	fetch_data_column(con);

	// update data
//	update_data(con);

	// delete data
//	delete_data(con);
	
	// close connection
	mysql_close(con);
	exit(0);
}
