本项目展示了如何在 Visual Studio 2022 中创建纯 C 项目并使用静态库和动态库，同时也包含了使用 CMake 创建静态库和动态库的示例。通过这些示例，你可以学习到如何组织项目结构、配置 CMake 文件以及在主程序中调用静态库和动态库的函数。

# 静态库和动态库使用示例

## 项目概述
本项目提供了两种创建和使用静态库、动态库的方法：
1. **Visual Studio 2022 纯 C 项目**：展示了如何在 Visual Studio 2022 中创建纯 C 项目，并集成静态库和动态库。
2. **CMake 创建方式**：演示了使用 CMake 工具来创建和管理静态库、动态库项目。

## 项目结构
```plaintext
├─CMake
│  ├─lib
│  │  ├─dynamicLibrary
│  │  └─staticLibrary
│  └─src
└─rhin
    ├─dynamicLibrary
    ├─rhin
    ├─staticLibrary
```

## 环境要求
- **Visual Studio 2022**：用于运行 Visual Studio 2022 纯 C 项目。
- **CMake**：版本 3.10 及以上，用于 CMake 创建的项目。

## 使用方法

### Visual Studio 2022 纯 C 项目
1. 打开 Visual Studio 2022。
2. 选择“打开项目或解决方案”，导航到 `vs2022_project` 文件夹并选择 `CMakeLists.txt` 文件。
3. 等待 Visual Studio 自动配置项目。
4. 选择合适的配置（如 `Debug` 或 `Release`）和平台（如 `x64`）。
5. 点击“生成” -> “生成解决方案”来构建项目。
6. 点击“调试” -> “开始执行（不调试）” 或按下 `Ctrl + F5` 运行项目。

### CMake 创建的项目
1. 打开终端，导航到 `cmake_project` 文件夹。
2. 创建一个构建目录：
```sh
mkdir build
cd build
```
3. 运行 CMake 配置和生成命令：
```sh
cmake ..
cmake --build .
```
4. 进入构建目录下的可执行文件所在目录，运行生成的可执行文件。

## 代码说明
### 静态库和动态库
- **`staticLibrary`**：包含静态库的源文件和头文件，提供了 `add` 函数的实现。
- **`dynamicLibrary`**：包含动态库的源文件和头文件，同样提供了 `add` 函数的实现。

### 主程序
- **`main.c`**：调用静态库和动态库的 `add` 函数，并输出计算结果。

## 注意事项
- 在使用动态库时，确保动态库文件（`.dll`）与可执行文件在同一目录下，或者将动态库所在目录添加到系统的 `PATH` 环境变量中。
- 如果遇到编译或运行问题，请检查项目配置、CMake 文件以及环境变量的设置。

## 贡献
欢迎对本项目提出改进建议或提交 Pull Request。如果你发现了任何问题，请在 GitHub 上提交 Issue。

## 许可证
本项目采用 [MIT 许可证](LICENSE)。
