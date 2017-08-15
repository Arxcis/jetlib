@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
set compilerflags=/Od /Zi /EHsc
set linkerflags=/out:C:\Users\Tor-KontorPC\github\jetlib\bin\main.exe
cl.exe %compilerflags% "C:\Users\Tor-KontorPC\github\jetlib\main.cpp" /link %linkerflags%

call "C:\Users\Tor-KontorPC\github\jetlib\bin\main"