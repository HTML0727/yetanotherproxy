# YetAnotherProxy (yetanotherproxy)

跨平台终端 TUI 代理管理工具，使用 **C++17** 编写，支持 **Linux/macOS/Windows**。  
它可以自动爬取代理、测试可用性，并在一个类似 **btop** 风格的终端界面中直观展示代理状态。  

## ✨ 功能特性

- **跨平台支持**：Linux / macOS / Windows  
- **代理采集**：从配置文件或网络爬取代理列表（支持 HTTP / SOCKS5）  
- **代理测试**：多线程并行检测延迟、可用性，自动打分排序  
- **TUI 界面**：基于 `ncurses` / `pdcurses`，彩色高亮、分页浏览、实时刷新  
- **历史记录**：测试结果持久化保存为 JSON/SQLite  
- **脚本支持**：内置构建脚本（Linux/macOS Bash & Windows PowerShell）  

## 📂 目录结构

```

yetanotherproxy/
├── CMakeLists.txt        # 构建配置
├── README.md             # 项目说明
├── LICENSE               # 开源协议
├── include/              # 头文件
│   ├── proxy.hpp
│   ├── scraper.hpp
│   ├── tester.hpp
│   ├── tui.hpp
│   ├── datastore.hpp
│   └── utils.hpp
├── src/                  # 源码实现
│   ├── main.cpp
│   ├── scraper.cpp
│   ├── tester.cpp
│   ├── tui.cpp
│   ├── datastore.cpp
│   └── utils.cpp
├── data/                 # 配置与样例数据
│   ├── sources.txt
│   └── config.json
├── tests/                # 简单单元测试
│   ├── test\_scraper.cpp
│   ├── test\_tester.cpp
│   ├── test\_datastore.cpp
│   └── test\_utils.cpp
└── scripts/              # 构建脚本
├── build.sh
└── build.ps1

````

## ⚙️ 构建与运行

### Linux/macOS

依赖：
- `g++` 或 `clang`（支持 C++17）
- `cmake >= 3.10`
- `libcurl`，`ncurses`

```bash
# 安装依赖 (Debian/Ubuntu)
sudo apt install g++ cmake libcurl4-openssl-dev libncurses5-dev

# 构建
./scripts/build.sh

# 运行
./build/yetanotherproxy
````

### Windows (MSVC + vcpkg)

依赖：

* Visual Studio 2019+ (MSVC)
* [vcpkg](https://github.com/microsoft/vcpkg) 安装 `curl` 和 `pdcurses`

```powershell
# 构建
.\scripts\build.ps1

# 运行
.\build\Debug\yetanotherproxy.exe
```

## 📊 使用说明

* 程序启动后会从 `data/sources.txt` 或配置文件读取代理列表
* 自动并行测试可用性与延迟
* 在 TUI 界面中可：

  * `↑/↓` 移动选择
  * 高亮代理显示详细状态
  * `q` 退出

输出结果会保存到 `data/history.json`，方便后续分析。

## 🛠️ 开发计划

* [ ] 更真实的 HTTP/HTTPS/SOCKS5 测试
* [ ] 更完善的 HTML 解析（Gumbo / RapidJSON）
* [ ] btop 风格的 UI（带实时图表、排序/搜索栏）
* [ ] SQLite 存储与查询
* [ ] 代理池 API 输出

## 📜 协议

本项目采用 **MIT License** 开源。
