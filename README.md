# Sample Postgres C code

Following the tutorial [PostgreSQL C tutorial](https://zetcode.com/db/postgresqlc/), you can find all the code in this repo. A simple [Makefile](./Makefile) has been provided to build all the code into individual executables.

## Prerequisites

Make sure you have `libpq` dev files installed. On a Debian based system you can do:

```
sudo aptitude install libpq-dev
```

Configure your Postgres DB so that the sample programs can connect to it using the following connection details:

```
host=localhost port=5432 user=postgres password=postgres dbname=api_data
```

You also need `gcc` and `make`.

## Building

Simply run `make`, and you will get an executable for each source code file. Run `make clean` to remove the built executables.

## License

The work is licensed under the [MIT](https://opensource.org/licenses/MIT) license. Please see [LICENSE](./LICENSE) for more details. Inside individual source code files, license is indicated using the [SPDX](https://spdx.org/licenses/) format.
