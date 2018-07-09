# NodeTox
Make working with c-toxcore low-level api more easy

Mission:
+ [x] Create NodeJs wrapper for c-toxcore api (based on [[c-toxcore](https://github.com/TokTok/c-toxcore)])
+ [ ] Create material web ui for tox client
+ [ ] Create cross-platform tox client

## What is it?

[Addon](https://nodejs.org/api/addons.html) that provide using [toxcore](https://github.com/TokTok/c-toxcore) api in Node.js environment.

## How to build

### Windows build (Visual Studio 17)

1. Download the 
	- [toxcore (v0.2.0)](https://github.com/TokTok/c-toxcore/archive/v0.2.0.zip)
	- [libsodium (libsodium-1.0.15-msvc)](https://download.libsodium.org/libsodium/releases/libsodium-1.0.15-msvc.zip)
	-  [pthreads (pthreads-w32-2-9-1-release)](http://sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip)
2. Build toxcore [using these instructions](https://github.com/TokTok/c-toxcore/blob/master/INSTALL.md#microsoft-visual-studios-developer-command-prompt)
3. Create new Visual Studio project with master of classic windows application (select app type as static library and remove check mark from precompiled header).
4. Add this libs as a dependencies: advapi32.lib;iphlpapi.lib;psapi.lib;shell32.lib;ws2_32.lib;libsodium.lib (don't forget specify path of libsodium.lib placed folder. You need to build libsodium.lib from sources additionaly for your platform).
5. Add exists elements: libsodium.lib, pthreadVC2.lib and toxcore.lib to project and build. Then you get one file *.lib, that contain above libs as one.
6. Create empty folder and init new npm package:
```sh
npm init
npm install node-addon-api
```
7. In file binding.gyp specify your own path to the include files and libs
8. In package root, as administrator, type [node-gyp clean configure build --verbose --arch=ia32](https://stackoverflow.com/questions/22448885/how-do-i-build-32-bit-binaries-on-a-64-bit-system-using-npm)
9. Put `libsodium.dll` and `pthreadVC2.dll` into root package folder. You must put these files in another projects that uses obtained ToxAddon.
10. Ok, you would get build folder where lay files ToxAddon.node and ToxAddon.lib. After that you may type `node index.js` and you would see "connected 2" over time. That works!

## How to use

- Example provides in file `index.js`
- You may call tox methods that contains in file `toxcore.c`.
- You may install this addon as dependency package to another project.
