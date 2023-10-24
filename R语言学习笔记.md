# R语言起源

R语言是S语言的一种实现，S-PLUS是商业软件，付费捏，大家不愿意花钱用

Ross Ihaka和Robert Gentlemen（这哥们是个生物学家，做生物统计的）两位R语言作者

R语言是通过编程把S语言的功能实现了一遍，函数方面有差别

==彻底面向对象的统计编程语言==



R语言扩展包很多，并且有的不容易学习



数据分析过程：数据采集、数据存储、数据分析、数据挖掘、数据可视化、进行决策



# R语言环境

### 安装R软件、Rstudio

Rstudio中集成了四个界面，左上写代码，点击run运行，结果在左下

左下也可以写代码，很像MATLAB

右上是environment，可以看到变量等信息

右下是各种文档和R包的下载，可以查看帮助文档等

可以改主题，在Tools里，毕竟一个好的主题是写代码好心情的开始（不过这玩意感觉不是很合理，如果换成深蓝色什么只有两个窗口改变，不如不换，整个好看的关键字提示就好）



# R的基本操作

## 设置工作目录

> 所有输入和输出文件的默认位置，脚本文件，保存空间映像

在R中使用绝对路径非常麻烦，如果将文件放在默认目录下，直接写文件名即可找到

```R
# 显示当前默认目录
> getwd()
# 修改默认目录，R语言用正斜线（linux），反斜线需要转义
> setwd(dir = "C:/Users/Desktop/RData/")

# 查看目录下包含的文件
> list.files()
> dir()
```

## 变量与赋值

R语言**不需要定义变量名**，定义变量名不能以数字开头

**赋值符号==<-==**，或者用=（不够专业，并且有时候有问题）

```R
# 向左赋值，用alt + -快捷键
> x <- 3
> x
[1] 3

# 向右赋值
> 5 -> x

# 强制赋值给全局变量，在函数中可能用到
> x <<- 5

# 调用各种函数
> sum(1,2,3,4,5)
> y <- sum(1,2,3,4,5)

> z <- mean(1,2,3,4,5)
# 调用了print函数，print可以省略
> z
[1] 1

# 显示所有变量
> ls()
[1] "x" "y" "z"
> ls.str()
x : num 3
y : num 15
z : num 1
> str(x)
 num 3
> ls(all.names = TRUE)
[1] ".Random.seed" "x"		"y"		  "z"

# 删除一个或多个对象remove，删除后无法恢复
> rm(x)
> x
Error: object 'x' not found
# 删除多个对象
> rm(y,z)
# 删除所有
> rm(list = ls())

# 列出所有指令
> history()
# 列出近25条指令
> history(25)

# 清屏
> ctrl + l

# 保存工作空间，只会保留数据和绘制函数，绘制出的图片不会单独保存
> save.image()
# 退出
> q()
```



# R包的安装与使用

## R包安装

> 通过网站上的Task View浏览各种包，[R官网](https://cran.r-project.org/)

### 1.联网在线安装

> 推荐，自动解决包与包之间的依赖关系

在R中输入**install.packages()**函数，选择站点；在Rstudio中输入命令安装，会自动安装依赖

```R
> install.packages("vcd")

# 显示库安装的位置，在线安装会安装到R安装的目录下
> .libPaths()
# 显示库中有哪些安装包
> library()

# 一次安装或加载多个R包，使用R向量
> install.packages(c("AER","ca"))
# 更新安装的软件包
> update.packages()
```

### 2.源代码安装：在官网下载源代码

需要注意依赖关系，根据依赖关系用R CMD INSTALL安装（这里就不写了，麻烦，而且只有很少部分包只能用源代码安装）



## R包使用

### 1.使用

R本身也是由一些包组成的，提供了种类繁多的默认函数和数据集

```R
# 加载R包，不需要加双引号
> library(vcd)
> require(vcd)

# 显示哪些包已经加载并且可以使用
> search()

# 列出这个包的帮助文档，在右下
> help(package="vcd")
# 列出包的一些基本信息
> library(help="vcd")

# 列出包中所有包含的函数
> ls("package:vcd")
# 列出包中包含的所有数据集
> data(package="vcd")

# 使用完后移除加载的包（将包从内存中移除）
> detach("package:vcd")
# 删除已下载的R包
> remove.package("vcd")
```

### 2.批量移植

```R
# 列出当前环境中已安装的所有R包
> installed.packages()
# 使用下标访问第一列
> installed.packages()[,1]

# 将所有名字保存到一个文件中
> Rpack <- installed.packages()[,1]
> save(Rpack, file="Rpack.Rdata")
# 将这个文件移到另一台设备上用load打开，并存到一个变量Rpack中，用for循环批量安装
> for (i in Rpack) install.packages(i)
```

### 3.查看帮助文档

工具栏中**Help->R Help**

可以在控制台终端中使用help.start()，使用帮助窗口打开

```R
# 查看帮助文档
> help.start()
# 列出函数详细信息
> help(sum)
> ?sum
# 输出函数参数
> args(plot)

# 给出示例，绘图函数会给出绘图案例
> example(mean)
# 给出R的一些示例图
> demo (graphics)

# 查看R安装的某个包的帮助文档
> help(package=ggplot2)
# 有些R包还包含vignette文档
> vignette("xts")

# 不加载包搜索函数帮助
> ??gplot
# 模糊搜索，本地搜索与热图有关的信息
> help.search("heatmap")
> ??heatmap

# 筛选有关键字的内容
> apropos("sum")
# 只列出函数
> aprpos("sum",mod="function")
# 进行网络搜索，在官网中进行搜索
> RSiteSerch("matlab")
```

[rseek](rseek.org)将谷歌搜索的大量内容中挑选出包含R关键字的内容（科学上网）



# Excel案例

一个优秀的数据分析软件，并且可以用鼠标直接框选、复制、粘贴、填充、排序，在R中都需要敲代码（批量化和自动化，往往用于处理大数据）

Excel中的单元格可以存储各种类型的数据，ctrl + 1快捷键打开单元格存储的数据格式

总之超级好用，各种函数或者画图的功能，但这个视频音画不同步，在这里就不写笔记了



# 内置数据集

## 简单操作

```R
# R中的内置数据集所在的包，都是非常经典的数据集，主要是收集美国或者欧洲的真实情况，比如好多年的太阳黑子数据
> help(paclage="datasets")

# 访问数据集，在左上列出很多数据集和介绍
> data()
# 直接输入数据集的名字就可以使用，下面是北美141条河流的长度（挺6的这也有，向量形式）
> rivers
  [1]  735  320  325  392  524  450 1459  135  465  600  330  336  280  315  870  906  202
 [18]  329  290 1000  600  505 1450  840 1243  890  350  407  286  280  525  720  390  250
 [35]  327  230  265  850  210  630  260  230  360  730  600  306  390  420  291  710  340
 [52]  217  281  352  259  250  470  680  570  350  300  560  900  625  332 2348 1171 3710
 [69] 2315 2533  780  280  410  460  260  255  431  350  760  618  338  981 1306  500  696
 [86]  605  250  411 1054  735  233  435  490  310  460  383  375 1270  545  445 1885  380
[103]  300  380  377  425  276  210  800  420  350  360  538 1100 1205  314  237  610  360
[120]  540 1038  424  310  300  444  301  268  620  215  652  900  525  246  360  529  500
[137]  720  270  430  671 1770

# 给变量命名时不要和数据集名字重复，如果重复重新用data函数加载
> data("rivers")
> rivers
  [1]  735  320  325  392  524  450 1459  135  465  600  330  336  280  315  870  906  202
 [18]  329  290 1000  600  505 1450  840 1243  890  350  407  286  280  525  720  390  250
 [35]  327  230  265  850  210  630  260  230  360  730  600  306  390  420  291  710  340
 [52]  217  281  352  259  250  470  680  570  350  300  560  900  625  332 2348 1171 3710
 [69] 2315 2533  780  280  410  460  260  255  431  350  760  618  338  981 1306  500  696
 [86]  605  250  411 1054  735  233  435  490  310  460  383  375 1270  545  445 1885  380
[103]  300  380  377  425  276  210  800  420  350  360  538 1100 1205  314  237  610  360
[120]  540 1038  424  310  300  444  301  268  620  215  652  900  525  246  360  529  500
[137]  720  270  430  671 1770

# 除了直接敲数据集名字显示数据集的内容外，还可以用help函数
# 右下显示此数据集具体内容
> help("mtcars")

> names(euro)
 [1] "ATS" "BEF" "DEM" "ESP" "FIM" "FRF" "IEP" "ITL" "LUF" "NLG" "PTE"

# 用data.frame函数将5个数据构成一个数据框
> state <- data.frame(state.name,state.abb,state.area,state.division,state.region)
> state
       state.name state.abb state.area     state.division  state.region
1         Alabama        AL      51609 East South Central         South
2          Alaska        AK     589757            Pacific          West
3         Arizona        AZ     113909           Mountain          West
4        Arkansas        AR      53104 West South Central         South
5      California        CA     158693            Pacific          West
6        Colorado        CO     104247           Mountain          West
7     Connecticut        CT       5009        New England     Northeast
8        Delaware        DE       2057     South Atlantic         South
9         Florida        FL      58560     South Atlantic         South
10        Georgia        GA      58876     South Atlantic         South
11         Hawaii        HI       6450            Pacific          West
12          Idaho        ID      83557           Mountain          West
13       Illinois        IL      56400 East North Central North Central
14        Indiana        IN      36291 East North Central North Central
15           Iowa        IA      56290 West North Central North Central
16         Kansas        KS      82264 West North Central North Central
17       Kentucky        KY      40395 East South Central         South
18      Louisiana        LA      48523 West South Central         South
19          Maine        ME      33215        New England     Northeast
20       Maryland        MD      10577     South Atlantic         South
21  Massachusetts        MA       8257        New England     Northeast
22       Michigan        MI      58216 East North Central North Central
23      Minnesota        MN      84068 West North Central North Central
24    Mississippi        MS      47716 East South Central         South
25       Missouri        MO      69686 West North Central North Central
26        Montana        MT     147138           Mountain          West
27       Nebraska        NE      77227 West North Central North Central
28         Nevada        NV     110540           Mountain          West
29  New Hampshire        NH       9304        New England     Northeast
30     New Jersey        NJ       7836    Middle Atlantic     Northeast
31     New Mexico        NM     121666           Mountain          West
32       New York        NY      49576    Middle Atlantic     Northeast
33 North Carolina        NC      52586     South Atlantic         South
34   North Dakota        ND      70665 West North Central North Central
35           Ohio        OH      41222 East North Central North Central
36       Oklahoma        OK      69919 West South Central         South
37         Oregon        OR      96981            Pacific          West
38   Pennsylvania        PA      45333    Middle Atlantic     Northeast
39   Rhode Island        RI       1214        New England     Northeast
40 South Carolina        SC      31055     South Atlantic         South
41   South Dakota        SD      77047 West North Central North Central
42      Tennessee        TN      42244 East South Central         South
43          Texas        TX     267339 West South Central         South
44           Utah        UT      84916           Mountain          West
45        Vermont        VT       9609        New England     Northeast
46       Virginia        VA      40815     South Atlantic         South
47     Washington        WA      68192            Pacific          West
48  West Virginia        WV      24181     South Atlantic         South
49      Wisconsin        WI      56154 East North Central North Central
50        Wyoming        WY      97914           Mountain          West

# 画热力图
> heatmap(volcano)

# 显示R中所有可用的数据集
> data(package=.packages(all.available = TRUE))
# 不想下载R包，但想使用其中的数据集
# data(数据集名字，package="R包名字")
> data(Chile,package="car")
> Chile
```



## 常用内置数据集

### 向量

euro #欧元汇率，长度为11，每个元素都有命名

landmasses #48个陆地的面积，每个都有命名

precip #长度为70的命名向量

rivers #北美141条河流长度

state.abb #美国50个州的双字母缩写

<font color="#dd0000">state.area #美国50个州的面积</font>

state.name #美国50个州的全称

### 因子

<font color="#dd0000">state.division #美国50个州的分类，9个类别</font>

<font color="#dd0000">state.region #美国50个州的地理分类</font>

### 矩阵、数组

euro.cross #11种货币的汇率矩阵

freeny.x #每个季度影响收入四个因素的记录

<font color="#dd0000">state.x77 #美国50个州的八个指标</font>

USPersonalExpenditure #5个年份在5个消费方向的数据

VADeaths #1940年弗吉尼亚州死亡率（每千人）

volcano #某火山区的地理信息（10米×10米的网格）

WorldPhones #8个区域在7个年份的电话总数

<font color="#dd0000">iris3 #3种鸢尾花形态数据</font>

Titanic #泰坦尼克乘员统计

UCBAdmissions #伯克利分校1973年院系、录取和性别的频数

crimtab #3000个男性罪犯左手中指长度和身高关系

HairEyeColor #592人头发颜色、眼睛颜色和性别的频数

occupationalStatus #英国男性父子职业联系

### 类矩阵

eurodist #欧洲12个城市的距离矩阵，只有下三角部分

Harman23.cor #305个女孩八个形态指标的相关系数矩阵

Harman74.cor #145个儿童24个心理指标的相关系数矩阵

### 数据框

airquality #纽约1973年5-9月每日空气质量

anscombe #四组x-y数据，虽有相似的统计量，但实际数据差别较大

attenu #多个观测站对加利福尼亚23次地震的观测数据

attitude #30个部门在七个方面的调查结果，调查结果是同一部门35个职员赞成的百分比

beaver1 #一只海狸每10分钟的体温数据，共114条数据

beaver2 #另一只海狸每10分钟的体温数据，共100条数据

BOD #随水质的提高，生化反应对氧的需求（mg/l）随时间（天）的变化

cars #1920年代汽车速度对刹车距离的影响

chickwts #不同饮食种类对小鸡生长速度的影响

esoph #法国的一个食管癌病例对照研究

faithful #一个间歇泉的爆发时间和持续时间

Formaldehyde #两种方法测定甲醛浓度时分光光度计的读数

Freeny #每季度收入和其他四因素的记录

dating from #配对的病例对照数据，用于条件logistic回归

InsectSprays #使用不同杀虫剂时昆虫数目

<font color="#dd0000">iris #3种鸢尾花形态数据</font>

LifeCycleSavings #50个国家的存款率

longley #强共线性的宏观经济数据

morley #光速测量试验数据

<font color="#dd0000">mtcars #32辆汽车在11个指标上的数据</font>

OrchardSprays #使用拉丁方设计研究不同喷雾剂对蜜蜂的影响

PlantGrowth #三种处理方式对植物产量的影响

pressure #温度和气压

Puromycin #两种细胞中辅因子浓度对酶促反应的影响

quakes #1000次地震观测数据（震级>4）

randu #在VMS1.5中使用FORTRAN中的RANDU三个一组生成随机数字，共400组。

\#该随机数字有问题。在VMS2.0以上版本已修复。

rock #48块石头的形态数据

sleep #两药物的催眠效果

stackloss #化工厂将氨转为硝酸的数据

swiss #瑞士生育率和社会经济指标

ToothGrowth #VC剂量和摄入方式对豚鼠牙齿的影响

trees #树木形态指标

USArrests #美国50个州的四个犯罪率指标

USJudgeRatings #43名律师的12个评价指标

warpbreaks #织布机异常数据

women #15名女性的身高和体重

### 列表

state.center #美国50个州中心的经度和纬度

### 类数据框

ChickWeight #饮食对鸡生长的影响

CO2 #耐寒植物CO2摄取的差异

DNase #若干次试验中，DNase浓度和光密度的关系

Indometh #某药物的药物动力学数据

Loblolly #火炬松的高度、年龄和种源

Orange #桔子树生长数据

Theoph #茶碱药动学数据

### 时间序列数据

<font color="#dd0000">airmiles #美国1937-1960年客运里程营收（实际售出机位乘以飞行哩数）</font>

AirPassengers #Box &Jenkins航空公司1949-1960年每月国际航线乘客数

austres #澳大利亚1971-1994每季度人口数（以千为单位）

BJsales #有关销售的一个时间序列

BJsales.lead #前一指标的先行指标（leading indicator）

co2 #1959-1997年每月大气co2浓度（ppm）

discoveries #1860-1959年每年巨大发现或发明的个数

ldeaths #1974-1979年英国每月支气管炎、肺气肿和哮喘的死亡率

fdeaths #前述死亡率的女性部分

mdeaths #前述死亡率的男性部分

freeny.y #每季度收入

JohnsonJohnson #1960-1980年每季度Johnson &Johnson股票的红利

LakeHuron #1875-1972年某一湖泊水位的记录

lh #黄体生成素水平，10分钟测量一次

lynx #1821-1934年加拿大猞猁数据

nhtemp #1912-1971年每年平均温度

Nile #1871-1970尼罗河流量

nottem #1920-1939每月大气温度

<font color="#dd0000">presidents #1945-1974年每季度美国总统支持率</font>

UKDriverDeaths #1969-1984年每月英国司机死亡或严重伤害的数目

sunspot.month #1749-1997每月太阳黑子数

sunspot.year #1700-1988每年太阳黑子数

sunspots #1749-1983每月太阳黑子数

treering #归一化的树木年轮数据

UKgas #1960-1986每月英国天然气消耗USAccDeaths #1973-1978美国每月意外死亡人数

uspop #1790–1970美国每十年一次的人口总数（百万为单位）

WWWusage #每分钟网络连接数

Seatbelts #多变量时间序列。和UKDriverDeaths时间段相同，反映更多因素。

EuStockMarkets #多变量时间序列。欧洲股市四个主要指标的每个工作日记录。



# 数据结构

> 数值型（数值可以用于直接结算，加减乘除）、字符串型（可以进行连接，转换，提取等）、逻辑型（真或假）、日期型等

## R 对象(object)

指可以赋值给任何变量的任何事物，包括常量、数据结构、函数、甚至图形。对象都拥有某种模式，描述了此对象是如何存储的，以及某个类。

## R中数据结构

向量，标量、矩阵、数组、列表、数据框因子、时间序列



# 向量

> vector，R中最重要的一个概念，它是构成其他数据结构的基础。
>
> R中的向量概念与数学中不同，而是类似于数学上的集合概念，由一个或多个元素所构成。

## 向量基础

向量其实是用于**存储数值型、字符型或逻辑型数据**的一维数组                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            

```R
# 定义了一个向量，可以是各种类型
> x <- c(1,2,3,4,5)
> x
[1] 1 2 3 4 5
# 字符串要加引号
> y <- c("one","two","three")
> y 
[1] "one"  "two"  "three"
# 逻辑型，不用加引号，全部大写或者简写为T或F，不能只是首字母大写
> z <- c(TRUE,T,F)
> z
[1] TRUE  TRUE  FALSE
# 如果向量中只有一个元素也可以不使用c函数赋值，这样是标量
> a=2
> c="hello"
> d=TRUE

# 可以用:简便的构造
# 输出等差数列
> c(1:100)
  [1]   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
 [25]  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48
 [49]  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70  71  72
 [73]  73  74  75  76  77  78  79  80  81  82  83  84  85  86  87  88  89  90  91  92  93  94  95  96
 [97]  97  98  99 100
# 调整等差差值，用seq函数
> seq(from=1,to=50)
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
[33] 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
> seq(from=1,to=50,by=2)
 [1]  1  3  5  7  9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49

# 生成重复序列，用rep函数（repeat的简写）
# 第一个参数是要重复的内容，第二个是重复的次数，可以省略，重复的方式可以用each控制
> rep(2,5)
[1] 2 2 2 2 2
> rep(x,5)
 [1] 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
> rep(x,each=5)
 [1] 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
> rep(x,each=5,times=2)
 [1] 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 1 1 1 1 1 2 2 2 2 2 3 3 3
[39] 3 3 4 4 4 4 4 5 5 5 5 5
```

向量的特点：所有元素**必须是同一类型**，比如都是数值型、字符串型等，因为同一类型才可以进行计算（在Excel中也是）

```R
# 查看向量数据类型
> mode(z)
[1] "logical"
```

R中使用**向量化编程**，因为R是统计软件

```R
# 将x的每一项乘2加上y的对应项
> x <- c(1,2,3,4,5)
> y <- c(6,7,8,9,10)
> x*2+y
[1]  8 11 14 17 20
# 取出x中大于3的数字
> x[x>3]
[1] 4 5
# 分别控制每一个元素循环的次数
> rep(x,c(2,4,6,1,3))
 [1] 1 1 2 2 2 2 3 3 3 3 3 3 4 5 5 5
```



## 向量索引

> 如何访问一个向量中的元素，这些索引方法也可以应用于其他数据结构

### 1.正（负）整数索引

根据元素**在集合中的位置**访问

```R
> x <- c(1:100)
# 求向量中元素个数（向量长度）
> length(x)
[1] 100
# R中下标从1开始
> x[1]
[1] 1
> x[0]
integer(0)
> x <- c(1:50)
> x[c(4:18)]
 [1]  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
> x[c(1,23,34,14)]
[1]  1 23 34 14
> x[c(11,11,23,23)]
[1] 11 11 23 23

# 负整数进行索引表示访问除了这个元素的其他所有元素
> x[-19]
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 20 21 22 23 24 25 26
[26] 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
# 不可以这样，逻辑上错误
> x[c(-2,3,4)]
Error in x[c(-2, 3, 4)] : only 0's may be mixed with negative subscripts
```

### 2.逻辑向量索引

```R
# 输出逻辑值为T的
> y <- c(1:10)
> y[c(T,F,T,T,F,F,T,T,T,F)]
[1] 1 3 4 7 8 9
# 逻辑值个数不一定与向量中元素个数相等，会进行循环判断
> y[c(T)]
 [1]  1  2  3  4  5  6  7  8  9 10
> y[c(T,F)]
[1] 1 3 5 7 9
> y[c(T,F,F)]
[1]  1  4  7 10
# 如果逻辑值个数多余向量中的元素个数，会多出一个NA缺失值
> y[c(T,F,T,T,F,F,T,T,T,F,T)]
[1]  1  3  4  7  8  9 NA

# 在索引中直接给出条件判断表达式
> y[y>5]
[1]  6  7  8  9 10
> y[y>5 & y<9]
[1] 6 7 8

> z <- c("one","two","three","four","five")
# 判断字符串型是否在向量中
> "one" %in% z
[1] TRUE
> z[z %in% c("one","two")]
[1] "one" "two"
> z %in% c("one","two")
[1]  TRUE  TRUE FALSE FALSE FALSE
> k <- z %in% c("one","two")
> k
[1]  TRUE  TRUE FALSE FALSE FALSE
> z[k]
[1] "one" "two"
```

### 3.名称索引

```R
# 使用names函数为向量的每个元素添加名称
> names(y) <- c("one","two","three","four","five","six","seven","eight","nine","ten")
# 第一行是向量的属性，第二行是value
> y
  one   two three  four  five   six seven eight  nine   ten 
    1     2     3     4     5     6     7     8     9    10 
# 使用每个元素的name访问其值
> y["one"]
one 
  1 
> euro
        ATS         BEF         DEM         ESP         FIM         FRF 
  13.760300   40.339900    1.955830  166.386000    5.945730    6.559570 
        IEP         ITL         LUF         NLG         PTE 
   0.787564 1936.270000   40.339900    2.203710  200.482000 
> euro["ATS"]
    ATS 
13.7603 
```



## 向量修改

### 1.添加元素

```R
# 插入单个数据
> x
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
[26] 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
> x[51] <- 51
> x
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
[26] 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
[51] 51

# 插入多个数据
> v <- 1:3
> v[c(4,5,6)] <- c(4,5,6)
> v
[1] 1 2 3 4 5 6
> v[20] <- 4
> v
 [1]  1  2  3  4  5  6 NA NA NA NA NA NA NA NA NA NA NA NA NA  4
# 在指定位置插入数据，after = 0表明在表头插入
> append(x = v,values = 99,after = 5)
 [1]  1  2  3  4  5 99  6 NA NA NA NA NA NA NA NA NA NA NA NA NA  4
```

### 2.删除与修改元素

```R
# 删除整个向量
> rm(v)
# 删除向量中部分元素
> y[-c(1:3)]
 four  five   six seven eight  nine   ten 
    4     5     6     7     8     9    10 
> y <- y[-c(1:3)]
> y
 four  five   six seven eight  nine   ten 
    4     5     6     7     8     9    10 

# 修改向量中某一项的值
> v[2] <- "one"
```



## 向量运算

### 1.加减乘除

```R
> x <- 1:10
# 加减法
> x+1
 [1]  2  3  4  5  6  7  8  9 10 11
> x-3
 [1] -2 -1  0  1  2  3  4  5  6  7
> x <- x+1
> x
 [1]  2  3  4  5  6  7  8  9 10 11
> y <- seq(1,100,length.out = 10)
> y
 [1]   1  12  23  34  45  56  67  78  89 100
# 两个向量相加相乘
> x+y
 [1]   3  15  27  39  51  63  75  87  99 111
> x*y
 [1]    2   36   92  170  270  392  536  702  890 1100
# 求幂
> x**y
 [1]  2.000000e+00  5.314410e+05  7.036874e+13  5.820766e+23  1.039456e+35
 [6]  2.115876e+47  3.213876e+60  2.697216e+74  1.000000e+89 1.378061e+104
# 求余
> y%%x
 [1] 1 0 3 4 3 0 3 6 9 1
# 整除
> y%/%x
 [1] 0 4 5 6 7 8 8 8 8 9
# 如果两个向量长度不一样，进行加法和乘法等短的那个向量会循环利用，但长的必须是短的的倍数
> z <- c(1,2)
> x+z
 [1]  3  5  5  7  7  9  9 11 11 13
```

### 2.逻辑运算

```R
# 大于小于，大于等于小于等于等都可以，和其他语言一样
> x>5
 [1] FALSE FALSE FALSE FALSE  TRUE  TRUE  TRUE  TRUE  TRUE  TRUE
> x>y
 [1]  TRUE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE
# 包含运算符%in%，判断左边的每个坐标是否包含在右边里面
> c(1,2,3) %in% c(1,2,2,4,5,6)
[1]  TRUE  TRUE FALSE
# 判断两个向量是否相等
> x==y
 [1] FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE
```



## 常用函数

```R
> x <- -5:5
# 绝对值函数
> abs(x)
 [1] 5 4 3 2 1 0 1 2 3 4 5
# 平方根函数
> sqrt(25)
[1] 5
# 对数函数，base为底数
> log(16,base=2)
[1] 4
# 不加base默认e为底数
> log(16)
[1] 2.772589
# 以10为底数也可以这样写
> log10(10)
[1] 1
# 指数函数，计算向量中每个元素的指数（求e的几次方）
> exp(x)
 [1] 6.737947e-03 1.831564e-02 4.978707e-02 1.353353e-01 3.678794e-01 1.000000e+00 2.718282e+00
 [8] 7.389056e+00 2.008554e+01 5.459815e+01 1.484132e+02
# 返回不小于一个数的最小整数
> ceiling(c(-2.3,3.1415))
[1] -2  4
# 返回不大于一个数的最大整数
> floor(c(-2.3,3.1415))
[1] -3  3
# 返回一个数的整数部分
> trunc(c(-2.3,3.1415))
[1] -2  3
# 四舍五入函数，第一个参数为向量，第二个控制位数
> round(c(-2.3,3.1415))
[1] -2  3
> round(c(-2.3,3.1415),digits = 2)
[1] -2.30  3.14
# 保留小数部分有效数字
> signif(c(-2.3,3.1415),digits = 2)
[1] -2.3  3.1
# 三角函数
> sin(x)
 [1]  0.9589243  0.7568025 -0.1411200 -0.9092974 -0.8414710  0.0000000  0.8414710  0.9092974
 [9]  0.1411200 -0.7568025 -0.9589243
> cos(x)
 [1]  0.2836622 -0.6536436 -0.9899925 -0.4161468  0.5403023  1.0000000  0.5403023 -0.4161468
 [9] -0.9899925 -0.6536436  0.2836622

> vec <- 1:100
# 求和
> sum(vec)
[1] 5050
# 求最小、最大
> min(vec)
[1] 1
> max(vec)
[1] 100
# 求范围，返回最大最小值
> range(vec)
[1]   1 100
# 求向量均值
> mean(vec)
[1] 50.5
# 求向量方差，利用round保存两位
> var(vec)
[1] 841.6667
> round(var(vec),digits = 2)
[1] 841.67
# 求向量标准差
> round(sd(vec),digits = 2)
[1] 29.01
# 求向量连乘的积
> prod(vec)
[1] 9.332622e+157
# 求中位数
> median(vec)
[1] 50.5
# 求分位数
> quantile(vec)
    0%    25%    50%    75%   100% 
  1.00  25.75  50.50  75.25 100.00 
# 求四分位数，中位数，八分位数
> quantile(vec,c(0.4,0.5,0.8))
 40%  50%  80% 
40.6 50.5 80.2 

# 求向量值的索引
> t <- c(1,4,2,5,7,9,6)
> which.max(t)
[1] 6
> which.min(t)
[1] 1
> which(t==7)
[1] 5
> which(t>5)
[1] 5 6 7
```



# 矩阵与数组

## 矩阵

> 矩阵（Matrix）是一个按照长方阵列排列的复数或实数集合。向量是一维的，而矩阵是二维的，需要有行和列。



在R软件中，矩阵是有维数的向量，这里的矩阵元素可以是数值型，字符型或逻辑型，但每个元素必须拥有相同的模式

很多数据集都是用矩阵存储的

```R
> iris3
> state.x77
# 用heatmap + 数据集可以直接画出热图
> heatmap(state.x77)
```

### 1.矩阵的创建

```R
# 行数和列数的分配必须满足分配条件
# 20个元素，4*5可以，4*6不行（元素不够），5*5可以（行和列能被整除就可以循环补齐），4*4可以，3*3不行（不能整除）
> x <- 1:20
> m <- matrix(x,nrow = 4,ncol = 5)
> m <- matrix(1:20,4,5)
> m
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20
# 可以只写行
> m <- matrix(1:20,4)
# byrow = T表明按行分布
> m <- matrix(1:20,4,byrow = T)
> m
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    2    3    4    5
[2,]    6    7    8    9   10
[3,]   11   12   13   14   15
[4,]   16   17   18   19   20
# byrow = F表示按列分布
> m <- matrix(1:20,4,byrow = F)
> m
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20
# 通过列表定义矩阵行和列的名字
>  rnames <- c("R1","R2","R3","R4")
> cnames <- c("C1","C2","C3","C4","C5")
> dimnames(m) <- list(rnames,cnames)
> m
   C1 C2 C3 C4 C5
R1  1  5  9 13 17
R2  2  6 10 14 18
R3  3  7 11 15 19
R4  4  8 12 16 20、
# 显示矩阵维数，可以利用dim函数构造矩阵
> dim(x)
NULL
> dim(x) <- c(4,5)
> x
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20
```

### 2.矩阵的索引

利用 **i 为行号，j 为列号**进行索引

```R
> m <- matrix(1:20,4,5,byrow = T)
> m
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    2    3    4    5
[2,]    6    7    8    9   10
[3,]   11   12   13   14   15
[4,]   16   17   18   19   20
# 访问一个元素
> m[1,2]
[1] 2
# 访问多个元素
> m[1,c(2,3,4)]
[1] 2 3 4
# 输出矩阵的一个子集
> m[c(2:4),c(2,3)]
     [,1] [,2]
[1,]    7    8
[2,]   12   13
[3,]   17   18
# 访问第2行
> m[2,]
[1]  6  7  8  9 10
# 访问第2列
> m[,2]
[1]  2  7 12 17
# 不加逗号默认访问行
> m[2]
[1] 6
# 负整数表示去除，下面表示去除第一行
> m[-1,2]
[1]  7 12 17
# 如果给矩阵行列起名，可以通过行列的名字访问
> dimnames(m)=list(rnames,cnames)
> m
   C1 C2 C3 C4 C5
R1  1  2  3  4  5
R2  6  7  8  9 10
R3 11 12 13 14 15
R4 16 17 18 19 20
> m["R1","C2"]
[1] 2
# head显示前六行数据
> head(state.x77)
           Population Income Illiteracy Life Exp Murder HS Grad Frost   Area
Alabama          3615   3624        2.1    69.05   15.1    41.3    20  50708
Alaska            365   6315        1.5    69.31   11.3    66.7   152 566432
Arizona          2212   4530        1.8    70.55    7.8    58.1    15 113417
Arkansas         2110   3378        1.9    70.66   10.1    39.9    65  51945
California      21198   5114        1.1    71.71   10.3    62.6    20 156361
Colorado         2541   4884        0.7    72.06    6.8    63.9   166 103766
```

### 3.矩阵的运算

```R
# 每个元素+1
> m+1
# 每个元素×2
> m*2
# 矩阵相加需要行列相等
> m+n
# 矩阵每一列相加的值
> colSums(m)
C1 C2 C3 C4 C5 
34 38 42 46 50 
# 矩阵每一行相加的值
> rowSums(m)
R1 R2 R3 R4 
15 40 65 90 
# 同理，每行每列均值
> colMeans(m)
  C1   C2   C3   C4   C5 
 8.5  9.5 10.5 11.5 12.5 
> rowMeans(m)
R1 R2 R3 R4 
 3  8 13 18

# 矩阵的乘法，分为内积和外积
> n <- matrix(1:9,3,3)
> t <- matrix(2:10,3,3)
# 内积，对应元素相乘
> n*t
     [,1] [,2] [,3]
[1,]    2   20   56
[2,]    6   30   72
[3,]   12   42   90
# 外积，线性代数相乘方法
> n %*% t
     [,1] [,2] [,3]
[1,]   42   78  114
[2,]   51   96  141
[3,]   60  114  168

# 求矩阵对角线元素
> diag(n)
[1] 1 5 9
> diag(m)
[1]  1  7 13 19
# 矩阵转置
> t(m)
   R1 R2 R3 R4
C1  1  6 11 16
C2  2  7 12 17
C3  3  8 13 18
C4  4  9 14 19
C5  5 10 15 20
```



## 数组

> 多维矩阵

```R
> x <- 1:20
# 规定数组维度
> dim(x) <- c(2,2,5)
> x
, , 1

     [,1] [,2]
[1,]    1    3
[2,]    2    4

, , 2

     [,1] [,2]
[1,]    5    7
[2,]    6    8

, , 3

     [,1] [,2]
[1,]    9   11
[2,]   10   12

, , 4

     [,1] [,2]
[1,]   13   15
[2,]   14   16

, , 5

     [,1] [,2]
[1,]   17   19
[2,]   18   20
# 显示数组维度
> dim(x)
[1] 2 2 5

# 每一维度起名字，利用列表
> dim1 <- c("A1","A2")
> dim2 <- c("B1","B2","B3")
> dim3 <- c("C1","C2","C3","C4")
> z <- array(1:24,c(2,3,4),dimnames = list(dim1,dim2,dim3))
> z
, , C1

   B1 B2 B3
A1  1  3  5
A2  2  4  6

, , C2

   B1 B2 B3
A1  7  9 11
A2  8 10 12

, , C3

   B1 B2 B3
A1 13 15 17
A2 14 16 18

, , C4

   B1 B2 B3
A1 19 21 23
A2 20 22 24
# 数组可以存储字符串等类型，也可以更高维度
```



# 列表

> 用来存储很多内容的一个集合，在其他编程语言中，列表一般和数组是等同的，但在R语言中，列表是最复杂的一种数据结构，也是非常重要的一种数据结构

## 列表基础

列表是一些对象的有序集合，列表中**可以存储若干向量、矩阵、数据框、甚至其他列表的组合**

在模式上与向量类似，都是一位数据集合

```R
# 很多数据集本身就是列表
> state.center
$x
 [1]  -86.7509 -127.2500 -111.6250  -92.2992 -119.7730 -105.5130  -72.3573  -74.9841  -81.6850
[10]  -83.3736 -126.2500 -113.9300  -89.3776  -86.0808  -93.3714  -98.1156  -84.7674  -92.2724
[19]  -68.9801  -76.6459  -71.5800  -84.6870  -94.6043  -89.8065  -92.5137 -109.3200  -99.5898
[28] -116.8510  -71.3924  -74.2336 -105.9420  -75.1449  -78.4686 -100.0990  -82.5963  -97.1239
[37] -120.0680  -77.4500  -71.1244  -80.5056  -99.7238  -86.4560  -98.7857 -111.3300  -72.5450
[46]  -78.2005 -119.7460  -80.6665  -89.9941 -107.2560

$y
 [1] 32.5901 49.2500 34.2192 34.7336 36.5341 38.6777 41.5928 38.6777 27.8744 32.3329 31.7500 43.5648
[13] 40.0495 40.0495 41.9358 38.4204 37.3915 30.6181 45.6226 39.2778 42.3645 43.1361 46.3943 32.6758
[25] 38.3347 46.8230 41.3356 39.1063 43.3934 39.9637 34.4764 43.1361 35.4195 47.2517 40.2210 35.5053
[37] 43.9078 40.9069 41.5928 33.6190 44.3365 35.6767 31.3897 39.1063 44.2508 37.5630 47.4231 38.4204
[49] 44.5937 43.0504

> a <- 1:20
> b <- matrix(1:20,4)
> c <- mtcars
> d <- "This is a test list"
# 分号表示换行
> a;b;c;d
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20
                     mpg cyl  disp  hp drat    wt  qsec vs am gear carb
Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4
[1] "This is a test list"
# 用list函数构造列表
> mlist <- list(a,b,c,d)
> mlist
[[1]]
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

[[2]]
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20

[[3]]
                     mpg cyl  disp  hp drat    wt  qsec vs am gear carb
Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4

[[4]]
[1] "This is a test list"

# 给列表每一项起名
> mlist <- list(first=a,second=b,third=c,forth=d)
> mlist
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

$second
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20

$third
                     mpg cyl  disp  hp drat    wt  qsec vs am gear carb
Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4

$forth
[1] "This is a test list"
```



## 列表索引

```R
# 用数字下标访问
> mlist[1]
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
# 一次访问多个元素，要用c()向量形式
> mlist[1,4]
Error in mlist[1, 4] : incorrect number of dimensions
> mlist[c(1,4)]
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

$forth
[1] "This is a test list"
# 用名字访问
> mlist["first"]
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
# 一次访问多个元素
> mlist[c("first","forth")]
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

$forth
[1] "This is a test list"
# 用$符号访问
> mlist$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

# 单中括号和双中括号打印相同，但数据类型不同
# 单中括号是列表类型，双中括号是数据本身类型，用class()函数可以查看数据类型
> mlist[1]
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
> mlist[[1]]
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
> class(mlist[1])
[1] "list"
> class(mlist[[1]])
[1] "integer"
```



## 列表修改

```R
# 添加元素
> mlist[[5]] <- iris

# 用负整数删除元素，将其赋给原来的列表
> mlist <- mlist[-5]
> mlist
$first
 [1]  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

$second
     [,1] [,2] [,3] [,4] [,5]
[1,]    1    5    9   13   17
[2,]    2    6   10   14   18
[3,]    3    7   11   15   19
[4,]    4    8   12   16   20

$third
                     mpg cyl  disp  hp drat    wt  qsec vs am gear carb
Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4

$forth
[1] "This is a test list"
# 直接将要删除的一项赋值为NULL
> mlist[[5]] <- NULL
```



# 数据框

> 数据框是一种表格式的数据结构，数据框旨在模拟数据集，与其他统计软件例如SAS或者SPSS中的数据集概念一致

## 数据框基础

数据集通常是由数据构成的一个矩形数组，行表示观测，列表示向量，不同行业对于数据集的行和列叫法不同



数据框实际上是一个列表，列表中的元素是向量，这些向量构成数据框的列，每一列必须具有相同的长度，所以数据框是矩形结构，而且数据框的**列必须命名**



数据框**每一列必须是同一类型，每一行可以不同** 

```R
# 很多数据集的数据类型是数据框
> iris
    Sepal.Length Sepal.Width Petal.Length Petal.Width    Species
1            5.1         3.5          1.4         0.2     setosa
2            4.9         3.0          1.4         0.2     setosa
51           7.0         3.2          4.7         1.4 versicolor
52           6.4         3.2          4.5         1.5 versicolor
100          5.7         2.8          4.1         1.3 versicolor
101          6.3         3.3          6.0         2.5  virginica
102          5.8         2.7          5.1         1.9  virginica
> mtcars
                     mpg cyl  disp  hp drat    wt  qsec vs am gear carb
Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4
> rock
    area     peri     shape   perm
1   4990 2791.900 0.0903296    6.3
2   7002 3892.600 0.1486220    6.3
3   7558 3930.660 0.1833120    6.3

# 利用data.frame构造数据框
> state <- data.frame(state.name,state.abb,state.region,state.x77)
> state
                   state.name state.abb  state.region Population Income Illiteracy Life.Exp Murder
Alabama               Alabama        AL         South       3615   3624        2.1    69.05   15.1
Alaska                 Alaska        AK          West        365   6315        1.5    69.31   11.3
Arizona               Arizona        AZ          West       2212   4530        1.8    70.55    7.8
               HS.Grad Frost   Area
Alabama           41.3    20  50708
Alaska            66.7   152 566432
Arizona           58.1    15 113417
```



## 数据框索引

需要数据框某一列进行分析时，可以取出此列赋给一个向量再进行分析

```R
# 用数字直接访问某一列
> state[1]
                   state.name
Alabama               Alabama
Alaska                 Alaska
Arizona               Arizona
# 一次访问多列
> state[c(2,4)]
               state.abb Population
Alabama               AL       3615
Alaska                AK        365
Arizona               AZ       2212
# 用名称访问某一列
> state[,"state.abb"]
 [1] "AL" "AK" "AZ" "AR" "CA" "CO" "CT" "DE" "FL" "GA" "HI" "ID" "IL" "IN" "IA" "KS" "KY" "LA" "ME"
[20] "MD" "MA" "MI" "MN" "MS" "MO" "MT" "NE" "NV" "NH" "NJ" "NM" "NY" "NC" "ND" "OH" "OK" "OR" "PA"
[39] "RI" "SC" "SD" "TN" "TX" "UT" "VT" "VA" "WA" "WV" "WI" "WY"
# 用名称访问某一行
> state["Alabama",]
        state.name state.abb state.region Population Income Illiteracy Life.Exp Murder HS.Grad Frost
Alabama    Alabama        AL        South       3615   3624        2.1    69.05   15.1    41.3    20
         Area
Alabama 50708
# 用$符号访问某一列
> state$Murder
 [1] 15.1 11.3  7.8 10.1 10.3  6.8  3.1  6.2 10.7 13.9  6.2  5.3 10.3  7.1  2.3  4.5 10.6 13.2  2.7
[20]  8.5  3.3 11.1  2.3 12.5  9.3  5.0  2.9 11.5  3.3  5.2  9.7 10.9 11.1  1.4  7.4  6.4  4.2  6.1
[39]  2.4 11.6  1.7 11.0 12.2  4.5  5.5  9.5  4.3  6.7  3.0  6.9

# $符号很好用，在用plot绘图时非常方便
> women
   height weight
1      58    115
2      59    117
3      60    120
4      61    123
5      62    126
> plot(women$height,women$weight)
# 线性回归
> lm (weight ~height,data = women)

Call:
lm(formula = weight ~ height, data = women)

Coefficients:
(Intercept)       height  
     -87.52         3.45  

# 用attach函数加载一个数据集，之后其每一列可以直接输入名字访问，不用加$符号，用完之后用detach函数取消加载
> attach(mtcars)
> mpg
 [1] 21.0 21.0 22.8 21.4 18.7 18.1 14.3 24.4 22.8 19.2 17.8 16.4 17.3 15.2 10.4 10.4 14.7 32.4 30.4
[20] 33.9 21.5 15.5 15.2 13.3 19.2 27.3 26.0 30.4 15.8 19.7 15.0 21.4
> hp
 [1] 110 110  93 110 175 105 245  62  95 123 123 180 180 180 205 215 230  66  52  65  97 150 150 245
[25] 175  66  91 113 264 175 335 109
> detach(mtcars)
# 用with函数也可以不用$符号
> with(mtcars,(hp))
 [1] 110 110  93 110 175 105 245  62  95 123 123 180 180 180 205 215 230  66  52  65  97 150 150 245
[25] 175  66  91 113 264 175 335 109
```



## 数据框删除

```R
# 用负整数进行某一列或者多列的删除
> state[-c(2,4)]
                   state.name  state.region Income Illiteracy Life.Exp Murder HS.Grad Frost   Area
Alabama               Alabama         South   3624        2.1    69.05   15.1    41.3    20  50708
Alaska                 Alaska          West   6315        1.5    69.31   11.3    66.7   152 566432
Arizona               Arizona          West   4530        1.8    70.55    7.8    58.1    15 113417
```



# 因子







# 字符串

```R
> nchar("hello world")
[1] 11
> month.name
 [1] "January"   "February"  "March"     "April"     "May"       "June"      "July"      "August"   
 [9] "September" "October"   "November"  "December" 
> nchar(month.name)
 [1] 7 8 5 5 3 4 4 6 9 7 8 8
> length(month.name)
[1] 12
> nchar(c(12,2,345))
[1] 2 1 3
> paste(c("Everyone","loves","stars"))
[1] "Everyone" "loves"    "stars"   
> paste("Everyone","loves","stars")
[1] "Everyone loves stars"
> paste("Everyone","loves","stars",sep = )
[1] "Everyone loves stars"
> paste("Everyone","loves","stars",sep = "-")
[1] "Everyone-loves-stars"
> names <- c("Moe","Larry","Curly")
> paste(names,"loves stars")
[1] "Moe loves stars"   "Larry loves stars" "Curly loves stars"
> substr(x)
Error: object 'x' not found
> substr(x = month.name,start = 1,stop = 3)
 [1] "Jan" "Feb" "Mar" "Apr" "May" "Jun" "Jul" "Aug" "Sep" "Oct" "Nov" "Dec"
> temp <- substr(x = month.name,start = 1,stop = 3)
> toupper(temp)
 [1] "JAN" "FEB" "MAR" "APR" "MAY" "JUN" "JUL" "AUG" "SEP" "OCT" "NOV" "DEC"
> tolower(temp)
 [1] "jan" "feb" "mar" "apr" "may" "jun" "jul" "aug" "sep" "oct" "nov" "dec"
> gsub("^(\\w)","\\U\\1",tolower(temp))
 [1] "Ujan" "Ufeb" "Umar" "Uapr" "Umay" "Ujun" "Ujul" "Uaug" "Usep" "Uoct" "Unov" "Udec"
> gsub("^(\\w)","\\U\\1",tolower(temp),perl = T)
 [1] "Jan" "Feb" "Mar" "Apr" "May" "Jun" "Jul" "Aug" "Sep" "Oct" "Nov" "Dec"
> 
> 
> gsub("^(\\w)","\\L\\1",tolower(temp),perl = T)
 [1] "jan" "feb" "mar" "apr" "may" "jun" "jul" "aug" "sep" "oct" "nov" "dec"
> gsub("^(\\w)","\\L\\1",tolower(temp),perl = T)
 [1] "jan" "feb" "mar" "apr" "may" "jun" "jul" "aug" "sep" "oct" "nov" "dec"
> gsub("^(\\w)","\\L\\1",toupper(temp),perl = T)
 [1] "jAN" "fEB" "mAR" "aPR" "mAY" "jUN" "jUL" "aUG" "sEP" "oCT" "nOV" "dEC"
> x <- c("b","A+","ac")
> grep("A+",x)
[1] 2
> grep ("A+",x)
[1] 2
> grep ("A+",x,fixed = T)
[1] 2
> grep ("A+",x,fixed = F)
[1] 2
> match("ac",x)
[1] 3
> path <- "/usr/local/bin/R"
> strsplit(path,"/")
[[1]]
[1] ""      "usr"   "local" "bin"   "R"    

> strsplit(c(path,paht),"/")
Error: object 'paht' not found
> strsplit(c(path,path),"/")
[[1]]
[1] ""      "usr"   "local" "bin"   "R"    

[[2]]
[1] ""      "usr"   "local" "bin"   "R"    

> face <- 1:13
> suit <- c("spades","clubs","hearts","diamonds")
> outer(suit,face,FUN = paste)
     [,1]         [,2]         [,3]         [,4]         [,5]         [,6]         [,7]        
[1,] "spades 1"   "spades 2"   "spades 3"   "spades 4"   "spades 5"   "spades 6"   "spades 7"  
[2,] "clubs 1"    "clubs 2"    "clubs 3"    "clubs 4"    "clubs 5"    "clubs 6"    "clubs 7"   
[3,] "hearts 1"   "hearts 2"   "hearts 3"   "hearts 4"   "hearts 5"   "hearts 6"   "hearts 7"  
[4,] "diamonds 1" "diamonds 2" "diamonds 3" "diamonds 4" "diamonds 5" "diamonds 6" "diamonds 7"
     [,8]         [,9]         [,10]         [,11]         [,12]         [,13]        
[1,] "spades 8"   "spades 9"   "spades 10"   "spades 11"   "spades 12"   "spades 13"  
[2,] "clubs 8"    "clubs 9"    "clubs 10"    "clubs 11"    "clubs 12"    "clubs 13"   
[3,] "hearts 8"   "hearts 9"   "hearts 10"   "hearts 11"   "hearts 12"   "hearts 13"  
[4,] "diamonds 8" "diamonds 9" "diamonds 10" "diamonds 11" "diamonds 12" "diamonds 13"
> outer(suit,face,FUN = paste,sep="-")
     [,1]         [,2]         [,3]         [,4]         [,5]         [,6]         [,7]        
[1,] "spades-1"   "spades-2"   "spades-3"   "spades-4"   "spades-5"   "spades-6"   "spades-7"  
[2,] "clubs-1"    "clubs-2"    "clubs-3"    "clubs-4"    "clubs-5"    "clubs-6"    "clubs-7"   
[3,] "hearts-1"   "hearts-2"   "hearts-3"   "hearts-4"   "hearts-5"   "hearts-6"   "hearts-7"  
[4,] "diamonds-1" "diamonds-2" "diamonds-3" "diamonds-4" "diamonds-5" "diamonds-6" "diamonds-7"
     [,8]         [,9]         [,10]         [,11]         [,12]         [,13]        
[1,] "spades-8"   "spades-9"   "spades-10"   "spades-11"   "spades-12"   "spades-13"  
[2,] "clubs-8"    "clubs-9"    "clubs-10"    "clubs-11"    "clubs-12"    "clubs-13"   
[3,] "hearts-8"   "hearts-9"   "hearts-10"   "hearts-11"   "hearts-12"   "hearts-13"  
[4,] "diamonds-8" "diamonds-9" "diamonds-10" "diamonds-11" "diamonds-12" "diamonds-13"
```



# 日期和时间

```R

```











