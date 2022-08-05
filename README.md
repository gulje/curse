# curse
curse is a tool that allows you to control the mouse cursor on most of Linux systems.
It currently only works on systems using X11.

This tool is a frontend of `libcurse-x11` and `libcurse-wl`.

## How does curse work?
curse usually runs via a `*.curse` file.
`*.curse` files are binary files.

**NOTE:** Data in `*.curse` files is ALWAYS sorted in big-endian.

### `0x00` MOVE_CURSOR
| Argument                                                                   | Length  |
|----------------------------------------------------------------------------|---------|
| `x`                                                                        | 2 bytes |
| `y`                                                                        | 2 bytes |

## Building curse
- :heavy_check_mark: is always compiled
- :white_check_mark: is compiled by arguments
- :x: is never compiled

If the `curse_build_wl=1` argument is given, `libcurse-wl` is compiled and used.

### `make all`
| Part               | Compiles           |
|--------------------|--------------------|
| `curse` executable | :heavy_check_mark: |
| `libcurse-x11`     | :heavy_check_mark: |
| `libcurse-wl`      | :heavy_check_mark: |

Builds executable file, `libcurse-x11` and `libcurse-wl`.

If you don't use `curse_build_wl=1` argument, the executable file
will use `libcurse-x11`.

### `make curse`
| Part               | Compiles           |
|--------------------|--------------------|
| `curse` executable | :heavy_check_mark: |
| `libcurse-x11`     | :white_check_mark: |
| `libcurse-wl`      | :white_check_mark: |

Builds executable file by arguments.
If the `curse_build_wl=1` argument is not used, `libcurse-x11` is compiled and used.

### `make libcurse`
| Part               | Compiles           |
|--------------------|--------------------|
| `curse` executable | :x:                |
| `libcurse-x11`     | :white_check_mark: |
| `libcurse-wl`      | :white_check_mark: |

Builds `libcurse-*` files by arguments.
If the `curse_build_wl=1` argument is not used, `libcurse-x11` is compiled.

## License
curse is licensed under the [Apache License 2.0](LICENSE).