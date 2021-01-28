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

## Linting C Code

The source code mostly follows Linux source code conventions. You can use the wonderful [checkpatch.pl](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/scripts/checkpatch.pl) utility to check the code for lint/style type errors. To do this, you need the following files (get them from the Linux git tree):

```
scripts/checkpatch.pl
scripts/spelling.txt
scripts/const_structs.checkpatch
```

Make sure that `checkpatch.pl` script can be executed by the user (use `chmod u+x ...` to set exec permissions). Assuming all the above 3 files were placed in the folder `~/scripts`, you can use `checkpatch` like so:

```
~/scripts/checkpatch.pl --no-tree -f ./01_lib_version.c
```

You should see something along the lines of:

```
total: 0 errors, 0 warnings, 13 lines checked

./01_lib_version.c has no obvious style problems and is ready for submission.
```

## License

The work is licensed under the [MIT](https://opensource.org/licenses/MIT) license. Please see [LICENSE](./LICENSE) for more details. Inside individual source code files, license is indicated using the [SPDX](https://spdx.org/licenses/) format.
