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