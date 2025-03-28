## prepare

the structure of the problem set

```
wronganswer
|-w1.c
|-w2.c
...
correctanswer
|-c1.c

input.txt # test case
```

## cluster

first step cluster
install dolos

```fish
bun  install @dodona/dolos-lib
```

现在只需要执行一个文件，全部流程自动完成

```fish
fish all_in_one.fish
```

> [!TIP]
> 可能遇到的问题，在动态生成trace的时候gdb发生达到最大递归深度，直接按q退出
> 原因是有人写了死循环，可以通过编译，但是运行时不能停止

## 统计

统计题目本身的数据，使用[tokei](https://github.com/XAMPPRocky/tokei), 可以统计一个文件夹中有多少个文件和文件有多少行

```
tokei .
```

需要统计的信息correctanswer和condense 里面的文件数量
统计bpex和ref的时间，精度,需要用到下面的脚本
计算时间或者精度，这些按照我的习惯一般在文件的第一行或者最后一行,
召回率没有办法自动化，我们没有办法计算所有真实的对齐，如果有，那我们的直接有那个工具就好了，需要手动看一下，可以挑几个有代表性的例子，不用全看

有些问题的对齐结果可能只有int main return 0之类的语句，不要惊慌，问题大概率是提交是空的或者压根就对不齐

```shell
set total 0
set count 0

for file in *.*
    set last_line (tail -n 1 $file) #如果是在最后一行
# set last_line (head -n 1 $file) #如果是在第一行
    set total (math "$total + $last_line")
    set count (math "$count + 1")
end
echo (math "$total / $count")
```
