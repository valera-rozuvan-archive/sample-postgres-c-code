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

	int ver = PQserverVersion(conn);

	printf("Server version: %d\n", ver);

	PQfinish(conn);

	return 0;
}
