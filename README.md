# PyBFD3

This clone of [PyBFD](https://github.com/Groundworkstech/pybfd) mainly adds support for Python 3.x while keeping compatibility with Python 2.x. To prevent conflicts and possible confusion, the name of the module/package has changed to **pybfd3**

Because it seems that **pybfd** is no longer maintained, I decided to create my own independent repository.

## Changelog

**[Version 0.1.5]**
- Remove legacy distutils usage. (thanks to [@Bidski](https://github.com/Bidski))

**[Version 0.1.4]**
- Update PyBFD3 to be compatible with binutils > 2.29. (thanks to [@Bidski](https://github.com/Bidski))

**[Version 0.1.3]**
- Initial release.

## Requirements

### Linux

- The **binutils-dev** package must be installed first.

### macOS

The default brew install doesn't include the required library `libiberty`, because of this you need to modify the brew formula to build and install `libiberty`. To do this run:

```
$ brew edit binutils
```

Scroll down the `def install` section and add `--enable-install-libiberty` to the `configure` arguments so that it looks like the following:

```
                          "--disable-nls",
                          "--enable-install-libiberty"
    system "make"
```

Now run the following command to force brew to build locally instead of from a bottle:

```
$ brew install --build-from-source binutils
```

## Install

Method 1: Via Python Package Index (PyPI).

```
$ pip install pybfd3
````

Method 2: Local installation.

```
$ git clone https://github.com/b-2-r/pybfd3.git
$ pip install ./pybfd3
```

**Note:**  

Depending on your pip version, you may need to add pip's ***--egg*** install option to successfully complete the installation.

## Sample Session

```
$ cd pybfd3/examples
$ chmod +x sample-session.py
$ ./sample-session.py
Usage : ./sample-session.py <binary>
$ ./sample-session.py `which sudo`
[+] Creating BFD instance...
[+] File format     : Linker/assembler/compiler output.
[+] Architecture    : Intel 386 (9)
[+] BFD target name : elf64-x86-64
[+] Entry point     : 0x403970
[+] Sections        : 27
[+] Selected section information:
	Name   : .text
	Index  : 13
	Length : 59 Kbytes
0x402B60 SZ=2 BD=0 IT=1	push   r15
0x402B62 SZ=2 BD=0 IT=1	push   r14
0x402B64 SZ=2 BD=0 IT=1	push   r13
0x402B66 SZ=2 BD=0 IT=1	push   r12
0x402B68 SZ=1 BD=0 IT=1	push   rbp
0x402B69 SZ=1 BD=0 IT=1	push   rbx
0x402B6A SZ=5 BD=0 IT=1	mov    ebx,0x63ec80
0x402B6F SZ=3 BD=0 IT=1	mov    rbp,rsi
0x402B72 SZ=7 BD=0 IT=1	sub    rsp,0xb8
[...]
```

## TODOs

- ~~improve ***get_symbols*** to not throwing an error if no symbols are present~~
- macOS testing
