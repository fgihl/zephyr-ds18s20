# Sample to show strncpy error in ARC

This sample show strncpy error, when compiling newlibc for arc cpus.  
arc_em : strncpy copies string with len 23-30 incorrect.  
arc_hs : strncpy copies string with len 23-39 incorrect.  

The error only show up when using the full version of newlibc.
Tested on sdk version 0.16.5-1 & 0.17.0

# Building and Running
```
west init -m https://github.com/fgihl/zephyr-ds18s20.git
cd zephyr
git checkout fgihl/strncpy-error
west update

west build -p -b qemu_arc/qemu_arc_em samples/strncpy_error/
west build -t run
```

# Sample Output

When working:  
```
*** Booting Zephyr OS build v3.7.0-12842-g05c3775fa9d5 ***
str (len:5) = ABCDE
str (len:6) = ABCDEF
str (len:7) = ABCDEFG
str (len:8) = ABCDEFGH
str (len:9) = ABCDEFGHI
str (len:10) = ABCDEFGHIJ
str (len:11) = ABCDEFGHIJK
str (len:12) = ABCDEFGHIJKL
str (len:13) = ABCDEFGHIJKLM
str (len:14) = ABCDEFGHIJKLMN
str (len:15) = ABCDEFGHIJKLMNO
str (len:16) = ABCDEFGHIJKLMNOP
str (len:17) = ABCDEFGHIJKLMNOPQ
str (len:18) = ABCDEFGHIJKLMNOPQR
str (len:19) = ABCDEFGHIJKLMNOPQRS
str (len:20) = ABCDEFGHIJKLMNOPQRST
str (len:21) = ABCDEFGHIJKLMNOPQRSTU
str (len:22) = ABCDEFGHIJKLMNOPQRSTUV
str (len:23) = ABCDEFGHIJKLMNOPQRSTUVW
str (len:24) = ABCDEFGHIJKLMNOPQRSTUVWX
str (len:25) = ABCDEFGHIJKLMNOPQRSTUVWXY
str (len:26) = ABCDEFGHIJKLMNOPQRSTUVWXYZ
str (len:27) = ABCDEFGHIJKLMNOPQRSTUVWXYZA
str (len:28) = ABCDEFGHIJKLMNOPQRSTUVWXYZAB
str (len:29) = ABCDEFGHIJKLMNOPQRSTUVWXYZABC
str (len:30) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCD
str (len:31) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE
str (len:32) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEF
str (len:33) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFG
str (len:34) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGH
str (len:35) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHI
str (len:36) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ
str (len:37) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK
str (len:38) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKL
str (len:39) = ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLM
```
On arc-em, len 23 to 30 failes.
```
*** Booting Zephyr OS build v3.7.0-12844-gba4c865539c4 ***
Test 5
Test 6
Test 7
Test 8
Test 9
Test 10
Test 11
Test 12
Test 13
Test 14
Test 15
Test 16
Test 17
Test 18
Test 19
Test 20
Test 21
Test 22
Test 23
strncpy failed(len=23). String: ABCDEFGHIJKLMNOPQRSTUV, expected: ABCDEFGHIJKLMNOPQRSTUVW
Test 24
strncpy failed(len=24). String: ABCDEFGHIJKLMNOPQRSTUV, expected: ABCDEFGHIJKLMNOPQRSTUVWX
Test 25
strncpy failed(len=25). String: ABCDEFGHIJKLMNOPQRST, expected: ABCDEFGHIJKLMNOPQRSTUVWXY
Test 26
strncpy failed(len=26). String: ABCDEFGHIJKLMNOPQRST, expected: ABCDEFGHIJKLMNOPQRSTUVWXYZ
Test 27
strncpy failed(len=27). String: ABCDEFGHIJKLMNOPQR, expected: ABCDEFGHIJKLMNOPQRSTUVWXYZA
Test 28
strncpy failed(len=28). String: ABCDEFGHIJKLMNOPQR, expected: ABCDEFGHIJKLMNOPQRSTUVWXYZAB
Test 29
strncpy failed(len=29). String: ABCDEFGHIJKLMNOP, expected: ABCDEFGHIJKLMNOPQRSTUVWXYZABC
Test 30
strncpy failed(len=30). String: ABCDEFGHIJKLMNOP, expected: ABCDEFGHIJKLMNOPQRSTUVWXYZABCD
Test 31
Test 32
Test 33
Test 34
Test 35
Test 36
Test 37
Test 38
Test 39

```
