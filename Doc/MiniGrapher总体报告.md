# MiniGrapher 总体报告

### 问题及背景

- 在Mac OS X系统上有一款Apple公司开发的强大的方程作图软件`Grapher.app`，受这款软件的启发，我们决定自己制作一个Windows版本的可以实现其部分功能的软件，并命名为`MiniGrapher`。
- 项目采用MVVM框架设计开发。

### 开发计划和分工

#### 开发计划

1. 首先根据需求分析设计初步的UI，并进行Appveyor持续集成环境的搭建，发布可执行的应用程序，以熟悉和测试Appveyor持续集成环境的功能。
2. 深入了解MVVM框架，并根据MVVM框架以及需求分析初步实现MVVM框架的搭建，进一步优化UI界面。
3. 实现Model层中算法层的词法解析功能。
4. 实现View层中函数图像放大缩小等基本交互功能。
5. 利用ViewModel层的通讯，实现给定函数解析式，通过Model层的词法解析在View层中绘制出指定函数的功能。
6. 实现给定横坐标的微分、给定区间的积分等计算功能。

#### 分工

- 组长
  - [吴宁超](https://github.com/CcCody)
    - 进行分工协调，MVVM框架的搭建以及Appveyor持续集成环境的搭建
    - 负责View层中给定横纵坐标数据的函数图像的绘制和显示、微分积分结果的显示
    - 负责App层的组装，以生成可以发布执行的应用程序
- 组员
  - [余亚鑫](https://github.com/ySilencex)
    - Model层以及Algorithm层词法解析算法的实现
    - Model层中给定横坐标的微分、给定区间的积分等底层数据计算的实现
    - ViewModel层相关命令与接口实现
  - [萧芷晴](https://github.com/crownX)
    - 应用程序UI设计、美化与实现
    - View层函数图像操作以及缩放、拖动、更名等交互功能的实现
    - View层自定义画笔颜色、笔刷颜色的实现

### 每轮迭代效果说明

#### 第一轮迭代

- [x] 设计初步的UI
- [x] 完成Appveyor持续集成环境的搭建

#### 第二轮迭代

- [x] 优化UI界面
- [x] 增加初始化界面入口
- [x] 基本实现MVVM框架的搭建

#### 第三轮迭代

- [x] 优化UI界面
- [x] 实现部分图像操作功能
  - [x] 增加随机函数曲线
  - [x] 选中单个函数曲线
  - [x] 删除指定函数曲线
  - [x] 删除所有函数曲线
  - [x] 坐标轴可拖动
  - [x] 更改结果图名称
  - [x] 更改坐标轴名称
  - [x] 更改曲线注记名称
  - [x] 更改曲线注记位置
  - [x] x轴单向缩放
  - [x] y轴单向缩放
  - [x] 图像放大缩小

#### 第四轮迭代

- [x] 优化UI界面
- [x] 实现给定函数解析式的函数绘制功能
  - [x] 支持三角函数`sin(x)`, `cos(x)`, `tan(x)`
  - [x] 支持对数函数`lg(x)`, `ln(x)`
  - [x] 支持数学函数`abs(x)`, `sqrt(x)`
  - [x] 支持多项式函数，如`x^3+x+1`
  - [x] 支持上述函数的复合形式，如`sin(x^2+1)*ln(x^3*cos(2*x))/(x^2+1)`

##### 第五轮迭代

- [x] 优化UI界面
- [x] 实现给定横坐标的微分计算功能
- [x] 实现给定区间的积分计算功能
- [x] 实现选中函数图像的画笔颜色自定义功能
- [x] 实现选中函数图像的阴影颜色自定义功能
- [x] 增加输入解析式格式正确与否的提示

### 单元测试

#### 测试原理

- 测试利用了Qt的 `QTest` 库，将`ViewModel`、`Model`、`Algorithm`层的数据整合进行测试
- 测试代码中共有11个测试函数，测试函数覆盖：
  - 一次函数
  - 二次函数
  - 三次函数
  - 正弦函数
  - 余弦函数
  - 正切函数
  - 常用对数函数
  - 自然对数函数
  - 绝对值函数
  - 开方函数
  - 复合函数
- 在每一个测试函数中，分以下三步进行测试：
  - 测试x，y的关系在误差范围内是否满足函数关系式
  - 测试函数定积分计算是否在误差范围之内
  - 测试函数微分计算是否在误差范围之内
- 误差范围设置为`1e-3`

#### 测试截图

![Test_Result](https://github.com/CcCody/MiniGrapher/raw/master/Images/Test_Result.png)

### 最终运行效果图

#### 软件主界面

![MainWindow](https://github.com/CcCody/MiniGrapher/raw/master/Images/MainWindow.png)

#### 函数绘图

![sine](https://github.com/CcCody/MiniGrapher/raw/master/Images/sine.png)

![linear](https://github.com/CcCody/MiniGrapher/raw/master/Images/linear.png)

![PlotGraph](https://github.com/CcCody/MiniGrapher/raw/master/Images/PlotGraph.gif)

#### 随机生成图像、选中、删除功能

![random_selection_deletion](https://github.com/CcCody/MiniGrapher/raw/master/Images/random_selection_deletion.gif)

#### 图像缩放、坐标轴平移缩放、名称更改、画笔/笔刷颜色更改等功能

![interactions](https://github.com/CcCody/MiniGrapher/raw/master/Images/interactions.gif)

#### 绘图成功/失败提示、单击点纵坐标显示（左下角）

![info](https://github.com/CcCody/MiniGrapher/raw/master/Images/info.gif)

### 项目目录

```
.
├── Algorithm
│   ├── lexer.cpp
│   ├── lexer.h
│   ├── prefixtree.cpp
│   └── prefixtree.h
├── App
│   ├── app.cpp
│   ├── app.h
│   ├── commands
│   │   ├── startcommand.cpp
│   │   └── startcommand.h
│   └── main.cpp
├── Common
│   └── etlbase.h
├── Doc
│   ├── MiniGrapher总体报告.md
│   ├── MiniGrapher需求分析.md
│   └── Model&ViewModel.md
├── Images
│   ├── 1:200*x.png
│   ├── MainWindow.png
│   ├── PlotGraph.gif
│   ├── info.gif
│   ├── interactions.gif
│   ├── random_selection_deletion.gif
│   └── sin(2*x):(x+1).png
├── Lib
│   ├── qcustomplot.cpp
│   └── qcustomplot.h
├── MiniGrapher.pro
├── Model
│   ├── model.cpp
│   └── model.h
├── README.md
├── Src
│   └── libstdc++-6.dll
├── View
│   ├── brushtool.cpp
│   ├── brushtool.h
│   ├── initial.cpp
│   ├── initial.h
│   ├── initial.ui
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   ├── mainwindow.ui
│   ├── pentool.cpp
│   ├── pentool.h
│   └── sinks
│       ├── mainwindowprosink.cpp
│       ├── mainwindowprosink.h
│       ├── mainwindowsetsink.cpp
│       └── mainwindowsetsink.h
├── ViewModel
│   ├── commands
│   │   ├── PaintCommand.cpp
│   │   ├── PaintCommand.h
│   │   ├── calculuscommand.cpp
│   │   └── calculuscommand.h
│   ├── sinks
│   │   ├── viewmodelsink.cpp
│   │   └── viewmodelsink.h
│   ├── viewmodel.cpp
│   └── viewmodel.h
├── appveyor.yml
└── tree.txt

14 directories, 51 files
```

