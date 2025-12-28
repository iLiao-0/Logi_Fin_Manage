// utils.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "employee.h"

// 清空输入缓冲区
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 显示菜单
void display_menu() {
    printf("\n========== 物流财务管理子系统 ==========\n");
    printf("1. 添加员工\n");
    printf("2. 显示所有员工\n");
    printf("3. 计算单个员工工资\n");
    printf("4. 保存到文件\n");
    printf("5. 从文件加载\n");
    printf("6. 查找员工\n");
    printf("7. 计算所有员工工资\n");
    printf("8. 退出\n");
    printf("========================================\n");
    printf("请选择 (1-8): ");
}

// 验证输入是否为有效数字
int is_valid_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            return 0;
        }
    }
    return 1;
}

// 格式化工资金额
void format_salary(float salary, char *buffer, int size) {
    snprintf(buffer, size, "¥%.2f", salary);
}