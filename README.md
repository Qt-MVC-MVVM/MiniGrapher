# MiniGrapher

### 项目介绍

- 本项目实现了一款根据函数解析式进行绘图并能进行定点微分值和定区间积分值计算的软件，同时实现了图像缩放、平移、选中删除等多种交互功能。
- 项目详细总体报告见[Doc/MiniGrapher总体报告](https://github.com/CcCody/MiniGrapher/raw/master/Doc/MiniGrapher总体报告.md)
- 项目详细需求分析见[Doc/MiniGrapher需求分析](https://github.com/CcCody/MiniGrapher/raw/master/Doc/MiniGrapher需求分析.md)
- 项目单元测试代码见[Test/MiniGrapher_Test.cpp](https://github.com/CcCody/MiniGrapher/blob/master/Test/MiniGrapher_Test.cpp)

### 项目概况

- 本项目使用 `C++` 以及 `Qt5` 开发，采用MVVM框架实现。
- 本项目支持跨平台编译（*Windows*, *macOS*, *Linux*），在已经下载安装Qt并配置好环境变量后可以直接编译。
- Windows版本可以在[Release页面](https://github.com/CcCody/MiniGrapher/releases)下载。
- 本项目使用Appveyor平台进行持续集成。

### 功能实现

#### 基本功能

- [x] 给定函数解析式的词法解析
- [x] 给定函数解析式的图像绘制
- [x] 给定区间的函数定积分计算
- [x] 给定横坐标的函数微分计算
- [x] 函数图像的缩放
- [x] 坐标轴的平移

#### 附加功能

- [x] 多个函数的同时显示
- [x] x轴单向缩放
- [x] y轴单向缩放
- [x] 函数解析式输入正确与否的交互提示
- [x] 增加随机函数曲线
- [x] 选中单个函数曲线
- [x] 删除指定函数曲线
- [x] 删除所有函数曲线
- [x] 绘制结果图名称更改
- [x] 坐标轴名称更改
- [x] 函数曲线注记名称更改
- [x] 函数曲线注记位置更改
- [x] 选中函数曲线画笔颜色自定义更改
- [x] 选中函数曲线阴影颜色自定义更改
- [x] 选中函数曲线类型自定义更改

### 支持函数

- 多项式函数，如`x^3+2*x^2+5*x+1`
- 三角函数 
  - `sin(x)`
  - `cos(x)`
  - `tan(x)`
- 对数函数
  - `lg(x)`
  - `ln(x)`
- 数学函数
  - `abs(x)`
  - `sqrt(x)`
- 上述所有函数的复合形式，如`sin(x^2+1)*ln(x^3*cos(2*x))/(x^2+1)`

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
### 小组成员

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