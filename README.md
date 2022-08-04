# curse
curse is a tool that allows you to control the mouse cursor on most of Linux systems.
It currently only works on systems using X11.

## How does curse work?
curse usually runs via a `*.curse` file.
`*.curse` files contain predetermined coordinates and operations.

**NOTE:** Data in `*.curse` files is ALWAYS sorted in big-endian.

### `0x00` MOVE_CURSOR
| Argument                                                                   | Length  |
|----------------------------------------------------------------------------|---------|
| `duration` (in how many miliseconds the mouse will move `x`, `y` position) | 2 bytes |
| `x`                                                                        | 2 bytes |
| `y`                                                                        | 2 bytes |

## License
curse is licensed under the [Apache License 2.0](LICENSE).