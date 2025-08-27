# libgpod-nogdk

A minimal fork of libgpod that provides core iPod database functionality without GdkPixbuf dependencies.

## What This Fork Changes

This fork makes a single but important modification to the original libgpod:

- **Adds `itdb_photos_dir_minimal.c`**: Provides a minimal implementation of the `itdb_get_photos_dir()` function that was previously only available when building with full GdkPixbuf support.

## Why This Fork Exists

When building libgpod without GdkPixbuf/photo support (which significantly reduces binary size and dependencies), the `itdb_get_photos_dir()` function becomes unavailable even though it doesn't actually require any photo framework functionality. This function is just a simple directory path resolver that uses only GLib.

This fork extracts and includes just this function, allowing projects to:
- Build without GdkPixbuf dependencies (saving ~4MB in binary size)
- Still have access to all core iPod database functionality
- Maintain full API compatibility

## Original libgpod

This is a fork of the fadingred/libgpod repository, which itself is based on the original libgpod project. For general libgpod information, see the original README file.

## Building

Build as you would normally build libgpod. The minimal implementation will be automatically included when compiling without GdkPixbuf support.

## License

Same as original libgpod - LGPL v2.