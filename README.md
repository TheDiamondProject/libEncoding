# libEncoding ![BuildCIBadge](https://travis-ci.org/TheDiamondProject/libEncoding.svg?branch=master)
**libEncoding** is part of _The Diamond Project_ and is reponsible for handling
legacy text encodings, such as MacRoman. The library is currently very light ]
weight and by no means features rich/feature full implementations of either 
Unicode or MacRoman.

## Building
To build **libEncoding** you will need to have a C Compiler on your machine,
such as GCC or Clang. You will also need to have Make installed.

To install you simply need to enter the following command:

```sh
make
```

This will produce an archive called `libEncoding.a` in the project directory.
You will need to include this into your own project along with the `macroman.h`
and `utf8.h` header files.

## License
**libEncoding** is provided by the Diamond Project under the MIT License.
 
