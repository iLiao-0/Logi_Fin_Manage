# Logistics Financial Management Subsystem (物流财务管理子系统)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)]()

这是一个基于 C 语言开发的控制台应用程序，旨在模拟物流公司的员工财务管理流程。系统采用了模块化设计，支持员工信息的录入、查询、基础薪资计算以及数据的持久化存储（文件读写）。

## 📖 项目简介

本项目提供了一个轻量级的财务管理工具。管理员可以通过命令行菜单管理员工档案，进行基础的工资核算，并将数据保存到本地文本文件中。代码针对 Windows 控制台环境进行了 UTF-8 编码优化，解决了常见的中文显示乱码问题。

## ✨ 功能特性

* **员工信息管理**
    * 录入新员工数据：支持 ID、姓名、基本工资、奖金、扣除项。
    * 内存管理：系统当前支持最多 `MAX_EMPLOYEES` (100) 名员工的记录。
* **薪资核算**
    * **单人计算**：自动计算特定员工的实发工资，计算公式为：`实发 = 基本 + 奖金 - 扣除`。
    * **批量汇总**：一键计算所有在职员工的当月薪资，并输出公司总支出报表。
* **查询功能**
    * **全览**：以列表形式显示所有员工的详细信息。
    * **搜索**：通过员工 ID 快速查找特定员工。
* **数据持久化**
    * **保存 (Save)**：将当前内存中的员工数据导出至 `employees.txt` 文件。
    * **加载 (Load)**：从文本文件中恢复历史数据，支持跨会话操作。
* **用户体验**
    * 清晰的交互式数字菜单。
    * 输入合法性验证（防止因输入非数字字符导致的程序崩溃）。
    * Windows 环境下自动设置代码页为 65001 (UTF-8) 以正常显示中文。

## 📂 项目文件结构

| 文件名 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`main.c`** | Core | 程序入口。包含主循环、菜单显示逻辑及系统环境初始化。 |
| **`employee.c`** | Source | 核心业务逻辑实现（员工录入、显示、查找、基础工资计算、文件读写）。 |
| **`employee.h`** | Header | 数据结构定义 (`Employee` struct)、全局常量宏及所有函数的声明。 |
| **`utils.c`** | Utils | 辅助工具函数库（菜单绘制、输入缓冲区清理、数字验证）。 |
| **`salary.c`** | *Dev* | **(扩展模块)** 包含基于职位的复杂薪资计算逻辑。*注意：当前版本暂未启用此文件。* |

## 🛠️ 安装与编译

### 1. 获取代码
```bash
git clone [https://github.com/iLiao-0/Logi_Fin_Manage.git](https://github.com/iLiao-0/Logi_Fin_Manage.git)
cd Logi_Fin_Manage
