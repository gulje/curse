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
### `make all`
Builds executable file, `libcurse-x11` and `libcurse-wl`

## License
curse is licensed under the [Apache License 2.0](LICENSE).