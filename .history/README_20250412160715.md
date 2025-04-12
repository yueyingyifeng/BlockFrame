# BlockFrame

一个轻量级的C++控制台绘图库，用于创建基于字符的图形界面和游戏。

## 简介

BlockFrame是一个简单的控制台绘图库，它提供了一系列工具来帮助开发者在控制台环境中创建交互式图形应用和游戏。该库使用基于字符的块作为基本绘图单元，支持颜色和位置控制。

## 特性

- 简单的2D向量系统用于位置和移动计算
- 基于字符的块系统，支持前景和背景颜色
- 块缓冲区管理，用于高效绘制
- 画布抽象，支持自定义绘图逻辑
- 双缓冲绘图支持，减少屏幕闪烁
- 内置示例：推箱子(Sokoban)游戏实现

## 组件

### Vector2D

二维向量类，用于表示位置和处理位置计算：

```cpp
Vector2D position(10, 5);
Vector2D movement(1, 0);
position += movement; // 位置现在是(11, 5)
```

### Block

表示控制台中的单个字符块，包含字符值和颜色信息：

```cpp
Block wall('#', Color::White, Color::Black);
Block player('@', Color::LightBlue, Color::Black);
```

### BlockBuffer

管理块集合，可以从字符串数组创建：

```cpp
std::vector<std::string> map = {
    "##########",
    "#        #",
    "#  $@    #",
    "#   .    #",
    "##########"
};
BlockBuffer buffer(map);
```

### Canvas

绘图画布抽象，提供帧渲染功能。

## 示例

BlockFrame包含一个推箱子(Sokoban)游戏的实现示例，展示了库的基本用法：

```cpp
SokobanGame game(20, 20);
game.run();
```

## 构建

项目使用Visual Studio 2019/2022构建系统。要构建项目：

1. 克隆仓库
2. 使用Visual Studio打开解决方案文件
3. 选择构建配置(Debug/Release)
4. 构建解决方案

## 贡献
欢迎贡献！请随时提交问题或拉取请求。