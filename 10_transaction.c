// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

int main(void)
{
	PGconn *conn = PQconnectdb("host=localhost port=5432 user=postgres password=postgres dbname=api_data");

	if (PQstatus(conn) == CONNECTION_BAD) {
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		do_exit(conn);
	}

	PGresult *res = PQexec(conn, "BEGIN");

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("BEGIN command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	PQclear(res);

	res = PQexec(conn, "UPDATE Cars SET Price=23700 WHERE Id=8");

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("UPDATE command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	res = PQexec(conn, "INSERT INTO Cars VALUES(9,'Mazda',27770)");

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("INSERT command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	res = PQexec(conn, "COMMIT");

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("COMMIT command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	PQclear(res);
	PQfinish(conn);

	return 0;
}
