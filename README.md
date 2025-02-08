## 静态库和动态库使用示例

## 项目概述
本项目旨在展示如何在 Visual Studio 2022 和 Visual Studio 2022 中创建纯 C 项目并使用静态库和动态库，同时也包含了使用 CMake 创建静态库和动态库的示例。通过这些示例，你可以学习到如何组织项目结构、配置 CMake 文件以及在主程序中调用静态库和动态库的函数。

本项目提供了两种创建和使用静态库、动态库的方法：
1. **Visual Studio 2022 纯 C 项目**：展示了如何在 Visual Studio 2022 中创建纯 C 项目，并集成静态库和动态库。
2. **Visual Studio 2022 项目配置**：详细介绍了在 Visual Studio 2022 中创建静态库 `staticLibrary`、动态库 `dynamicLibrary` 和可执行项目 `rhin` 时，在 `Debug` 和 `Release` 模式下各项目属性页中需要重点配置的内容。
3. **CMake 创建方式**：演示了使用 CMake 工具来创建和管理静态库、动态库项目。

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
- **Visual Studio 2022**：用于按照特定配置创建静态库、动态库和可执行项目。
- **CMake**：版本 3.10 及以上，用于 CMake 创建的项目。

## 使用方法

### Visual Studio 2022 纯 C 项目
1. 打开 Visual Studio 2022。
2. 选择“打开项目或解决方案”，导航到 `vs2022_project` 文件夹并选择 `CMakeLists.txt` 文件。
3. 等待 Visual Studio 自动配置项目。
4. 选择合适的配置（如 `Debug` 或 `Release`）和平台（如 `x64`）。
5. 点击“生成” -> “生成解决方案”来构建项目。
6. 点击“调试” -> “开始执行（不调试）” 或按下 `Ctrl + F5` 运行项目。

### Visual Studio 2022 项目配置

#### 通用配置
##### 1. 编译语言设置
对于所有项目（`staticLibrary`、`dynamicLibrary` 和 `rhin`），都需要将其配置为使用 C 语言进行编译：
- 右键点击项目，选择“属性”。
- 在“配置属性” -> “C/C++” -> “高级”中，将“编译为”选项设置为“编译为 C 代码 (/TC)”。

##### 2. 预编译头设置
如果不想使用预编译头，可以在所有项目中禁用：
- 右键点击项目，选择“属性”。
- 在“配置属性” -> “C/C++” -> “预编译头”中，将“预编译头”选项设置为“不使用预编译头”。

#### 静态库项目 `staticLibrary`
##### 1. 配置类型
- 右键点击 `staticLibrary` 项目，选择“属性”。
- 在“配置属性” -> “常规”中，将“配置类型”设置为“静态库 (.lib)”。

#### 动态库项目 `dynamicLibrary`
##### 1. 配置类型
- 右键点击 `dynamicLibrary` 项目，选择“属性”。
- 在“配置属性” -> “常规”中，将“配置类型”设置为“动态库 (.dll)”。

##### 2. 预处理器定义
- 在“配置属性” -> “C/C++” -> “预处理器” -> “预处理器定义”中，添加 `DYNAMICLIBRARY_EXPORTS` （仅在 `dynamicLibrary` 项目中添加，`rhin` 项目不需要），用于导出动态库函数。

#### 可执行项目 `rhin`
##### 1. 配置类型
- 右键点击 `rhin` 项目，选择“属性”。
- 在“配置属性” -> “常规”中，将“配置类型”设置为“应用程序 (.exe)”。

##### 2. 包含目录
- 在“配置属性” -> “VC++ 目录” -> “包含目录”中，添加 `staticLibrary` 和 `dynamicLibrary` 项目的头文件所在目录，以便编译器能够找到这些头文件。
```
$(SolutionDir)\dynamicLibrary\dynamicLibrary;
$(SolutionDir)\staticLibrary\staticLibrary;
```

##### 3. 库目录
- 在“配置属性” -> “VC++ 目录” -> “库目录”中，添加 `staticLibrary` 和 `dynamicLibrary` 项目生成的 `.lib` 文件所在目录，以便链接器能够找到这些库文件。
```
$(SolutionDir)\x64\$(Configuration);
```

##### 4. 链接器输入
- 在“配置属性” -> “链接器” -> “输入” -> “附加依赖项”中，添加 `staticLibrary.lib` 和 `dynamicLibrary.lib`，确保链接器在链接时使用这些库文件。

##### 5. 后期生成事件（可选）
为了避免手动复制动态库文件，可以在 `rhin` 项目中配置后期生成事件，自动将 `dynamicLibrary.dll` 复制到可执行文件输出目录：
- 在“配置属性” -> “生成事件” -> “后期生成事件” -> “命令行”中，添加以下命令（以 Windows 系统为例）：
```plaintext
xcopy /y "$(SolutionDir)dynamicLibrary\$(Configuration)\dynamicLibrary.dll" "$(OutDir)"
```

```powershell
powershell -Command "Copy-Item -Path '$(SolutionDir)dynamicLibrary\x64\$(Configuration)\dynamicLibrary.dll' -Destination '$(OutDir)' -Force"
```

#### 项目依赖关系（解决方案层面）
为了确保在生成 `rhin` 项目时，`staticLibrary` 和 `dynamicLibrary` 项目会先被生成，需要设置项目依赖关系：
- 右键点击解决方案，选择“项目依赖项”。
- 在“项目依赖项”对话框中，选择 `rhin` 项目，然后在“依赖于”列表中勾选 `staticLibrary` 和 `dynamicLibrary` 项目。

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
- 确保 `Debug` 和 `Release` 模式下的所有配置一致，避免因配置不同导致的问题。
- 如果项目路径或文件名包含特殊字符或空格，可能会导致编译或链接错误，建议使用简单的路径和文件名。

## 贡献
欢迎对本项目提出改进建议或提交 Pull Request。如果你发现了任何问题，请在 GitHub 上提交 Issue。

## 许可证
本项目采用 [MIT 许可证](LICENSE)。