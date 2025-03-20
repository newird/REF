## prepare

the structure of the problem set

```
0
|-w1.c
|-w2.c
10
|-w3.c
...
100
|-c1.c

input.txt # test case
```

## cluster

first step cluster
install dolos

```fish
bun  install @dodona/dolos-lib
```

and then run

```fish
fish cluster
```

## compile

```fish
fish compile.fish
```

## dynamic trace

```fish
fish gen_trace.fish
```

## align

```
fish align.fish

```

## feedback

```
python feedback.py w.c c.c

```
