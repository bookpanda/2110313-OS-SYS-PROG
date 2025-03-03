# cat
```bash
cat

# create a file
cat > 1.txt
1
2
3
4
^D

# append to a file
cat >> 1.txt
```

# cal
```bash
# this month
cal
# whole year
cal 2020
# specific month (1-12)
cal 1 2020
```

# wc (lines, words, characters)
```bash
wc
123
456
^D

wc 3.c
wc -l 3.c
wc -lw 3.c # same as wc -l -w 3.c or wc -wl 3.c
wc -w -l -c 3.c # same as wc 3.c
```

# head/tail
```bash
# first 10 lines
head 3.c
# first 5 lines
head -5 3.c
tail 3.c

# append to a file
head -5 3.c > 3_5.c

# get the 5th line
head -5 3.c | tail -1

# get lines 8-10
head -10 3.c | tail -3

# first 2 lines and last line
head -2 3.c; tail -1 3.c
```

# script
```bash
script
ls
# ctrl+d
# rerun the script
cat typescript

# append pwd command to typescript
script -c pwd

# save the script as "some_script" instead of "typescript"
script -a some_script
```

# ln
```bash
# -l: permission, owner, size, modified date, -i: inode (e.g. 82412496) 
ls -l

# creates a hard link "1.linked" (same inode as 1.txt, edit either will change the other)
ln 1.txt 1.linked
rm 1.linked

# creates a symbolic (soft) link "1.sl" (inode is different, edit one will change the other)
ln -s 1.txt 1.sl

rm 1.txt
cat 1.sl # cat: 1.sl: No such file or directory
```

# grep
```bash
grep main 3.c
# main() {

grep -i M 3.c
# main() { // case insensitive

grep -v main 3.c # everything except lines with main
# #include <stdio.h>
# #include <unistd.h>
# #include <sys/types.h>
#     int i;
#     int n;
#     pid_t childpid;
#     n = 4;
#     for (i = 0; i < n; ++i) {
#         childpid = fork() ;
#         if (childpid > 0)
#             break;
#     }
#     wait(0);
#     printf("This is process %ld with parent %ld\n",(long) getpid(), (long) getppid());
# }

grep -n main 3.c
# 4:main() { // line number

grep -c int 3.c
# 3 (number of lines with "int")

# whole word
grep -w mai 3.c # no output
grep -w main 3.c
# main() { // whole word
```

# sort
```bash
sort 3.c # sort by line
sort -r 3.c # reverse sort
sort -f 3.c # case insensitive sort (e.g. AaBbCc, case sensitive sort would be ABCabc)
sort -u b.txt # remove duplicate lines
# A
# B
# a
# b
# hello b

sort numbers 
# 10
# 2
# 23
# 45
# 5
sort -n numbers
# 2
# 5
# 10
# 23
# 45
sort -n numbers -o sorted_numbers # sort -n numbers > sorted_numbers also works

sort provinces 
# bangkok 02
# chiangmai   053
# khonkhan    043
# lopburi 036
# phuket  076

sort -k2n provinces # sort by the second column, numerically
# bangkok 02
# lopburi 036
# khonkhan    043
# chiangmai   053
# phuket  076
```