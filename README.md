# Sample Postgres C code

Following the tutorial [PostgreSQL C tutorial](https://zetcode.com/db/postgresqlc/), you can find all the code in this repo. A simple [Makefile](./Makefile) has been provided to build all the code into individual executables.

Big shout out to the original author [Jan Bodnar](https://github.com/janbodnar) for the sample code. Check out his [zetcode.com](http://zetcode.com) for more awesome stuff!

Motivation behind this repository is to make all examples build with one command on Linux and MacOS. I want a reference for myself in the future for how to work with Postgres via C code. In case original source `zetcode.com` ever goes down, this will remain intact :) Hopefully GitHub is here to stay for a long time to come!

## Prerequisites

In order for the code to compile and for you to be able to run the executables, you need to make sure several things have been setup properly.

### The libpq development sources

Make sure you have `libpq` dev files installed. On a Debian based system you can do:

```
sudo aptitude install libpq-dev
```

On a MacOS system you can do:

```
brew install libpq
```

### Running a Postgres DB server

Configure your Postgres DB so that the sample programs can connect to it using the following connection details:

```
host=localhost port=5432 user=postgres password=postgres dbname=api_data
```

### Standard build tools

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

## Distributing your executable for a fresh MacOS install

If the app is installed on a fresh/clean Mac running macOS that has no version of Postgres or Xcode installed, where will the Postgres lib/drivers be found? See some interesting discussion on this topic over at the Apple Developer forums: [Deploying a Postgres client app: where is libpq.tbd?](https://developer.apple.com/forums/thread/65619).

## License

The work is licensed under the [MIT](https://opensource.org/licenses/MIT) license. Please see [LICENSE](./LICENSE) for more details. Inside individual source code files, license is indicated using the [SPDX](https://spdx.org/licenses/) format.
